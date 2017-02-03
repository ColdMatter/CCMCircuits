/*
This project is a Photon-based phase lock for cryocooler-based buffer-gas experiments.
The Gifford-McMahon cryocooler cycle is 1 Hz, with a main compression stroke followed
by a return stroke about 200ms later.  The pulse tubes are a little different, with
a 2 Hz frequency and no discernable return stroke.  Here we detect the sound spikes from
the compression stroke using a microphone placed a couple of mm off the helium lines
(near the head works best, the compressor is so loud and causes so much white-noise-like
vibration that it makes things more difficult) and provide digital output signals
for triggering/locking purposes.  An analog input (pin A1, 0-3.3V) controls the
delay between when a threshold event is detected and the trigger channel (triggerOut, D7)
is sent high.  The trigger stays high until the specified "dead time" is reached,
at which point the software starts monitoring the microphone again and is ready
to produce the next trigger.

*/

const float threshold = 1.65;			// choose a volume threshold, in volts
const int deadTime = 990;				// dead time after a pulse before another can be detected
										// two close peaks/cycle so make ~1/2 cycle to make sure and get the first one always
const int maxDelay = deadTime - 50;		// the longest the trigger can be high for
const float offset = 1.65;
const float gain = 25.0;


#include "application.h"

SYSTEM_MODE(SEMI_AUTOMATIC);			// run code even if not connected to the cloud
SYSTEM_THREAD(ENABLED);

// hardware connections
const int syncOut = D7;					// output from (software) comparator, rising edge indicates threshold exceeded
const int triggerOut = D6;				// pulses high to trigger experiment, on-board led for visual status
const int audioIn = A0;					// microphone output
const int delayAdjust = A1;				// analog input for controlling the trigger delay
const int volumeIndicator = A3;			// true analog-output for indicating volume level that is compared to threshold

float volume;							// recorded volume level


Timer delayTimer(1000, sendTrigger, true);		// one-shot delay timer, started from accelerometer interrupt
Timer triggerTimer(1000, stopTrigger, true);	// stay high for awhile for a debounce


void setup() {

	WiFi.disconnect();					// don't need a cloud connection for this application
	WiFi.off();							// Photon RGB LED should slowly flash white

	pinMode(syncOut, OUTPUT);
	digitalWrite(syncOut, LOW);
  	pinMode(triggerOut, OUTPUT);
  	digitalWrite(triggerOut, LOW);

	pinMode(volumeIndicator, OUTPUT);				// true analog output

}


void loop() {

	volume = (float)(analogRead(audioIn)*3.3/4095);		// read and convert to volts
	volume = gain*(volume - offset);					// offset and scale
	analogWrite(volumeIndicator, 4095*volume/3.3);		// indicate amplified volume

// if above threshold and trigger isn't active, start the trigger process
	if ( volume > threshold && !delayTimer.isActive() && !triggerTimer.isActive()) {
		startDelayTimer();
	}

}


// volume detected an above-threshold event, start the send-trigger timer!
void startDelayTimer() {
	int delayVoltage = analogRead(delayAdjust);					// 0..4095 for 0-3.3V
	int triggerDelay = map(delayVoltage, 0, 4095, 0, maxDelay);	// convert to delay (ms)
	delayTimer.changePeriod(triggerDelay);						// update the timer period for next event
	triggerTimer.changePeriod(deadTime - triggerDelay);			// two timers summed = dead time
	digitalWrite(syncOut, HIGH);								// indicate trigger is sent
	delayTimer.start();
}

// send a trigger to start the experiment
void sendTrigger() {
	digitalWrite(triggerOut, HIGH);			// send the trigger to the experiment
	triggerTimer.start();					// start timer to send trigger output low
}

void stopTrigger() {
	digitalWrite(triggerOut, LOW);
	digitalWrite(syncOut, LOW);
}
