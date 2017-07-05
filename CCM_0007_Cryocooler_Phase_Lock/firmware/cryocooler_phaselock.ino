/*
This project is a Photon-based phase lock for cryocooler-based buffer-gas experiments.
The Gifford-McMahon cryocooler cycle is 1 Hz, with a main compression stroke followed
by a return stroke about 200ms later.  The pulse tubes are a little different, with
a 2 Hz frequency and no discernable return stroke.  Here we detect the sound spikes from
the compression stroke using a microphone placed a couple of mm off the helium line
(near the head works best, the compressor is so loud and causes so much white-noise-like
vibration that it makes things more difficult) and provide digital output signals
for experimental triggering.  An analog input (pin A1, 0-10V) controls the
delay between when a threshold event is detected and when the trigger is pulsed
high.  A variable "dead time" is specified (in ms), triggers cannot be sent more
often than this period.

With no low-pass or high-pass filter components installed, tapping or blowing on
the microphone yields a maximum volume of about 1.5V (the rail).
Placing the microphone near the compressor line yields about 0.6-0.7V.
Background room noise (worst case) is about 0.2-0.3V.
Adjust the threshold as necessary to get reliable triggering.
*/

/*
Decent parameters for different experimental setups:

(1) CaF Gifford-McMahon: the primary cryocooler pulse is very loud and high
pitched, much louder than the secondary pulse that occurs ~ 200 ms later.
threshold = 0.6, deadTime = 900 ms --> 10ms trigger accuracy (probably better than that even)

(2) Neon YbF Gifford-McMahon: the secondary cryocooler pulse seems louder than
the primary one.

(3) He YbF Gifford-McMahon:

(4) Large molecule pulse-tube: overall much quieter but so is the lab
threshold = ?, deadTime = 450 ms
*/

// program constants
const float threshold = 0.6;			// choose a volume threshold, in volts, you can use an oscilloscope to tune
const int deadTime = 900;				// dead time after a pulse before another can be detected (change for different coolers)
const int maxDelay = 1000;				// longest possible delay between high volume and trigger output, corresponds to 10V at BNC input
const float offset = 1.65;				// offset (use if DC coupled - no high-pass filter installed)


#include "application.h"

SYSTEM_MODE(MANUAL);					// run code even if not connected to the cloud

// hardware connections
const int aboveThreshold = D7;			// output, high indicates threshold is currently being exceeded
const int triggerOut = D6;				// pulses high to trigger experiment, on-board led for visual status
const int audioIn = A0;					// microphone output after gain stage and optional filtering
const int delayAdjust = A1;				// analog input for controlling the trigger delay (0-10V divided down to 0-3.3V)
const int volumeIndicator = A3;			// true analog-output for indicating volume

float volume;							// recorded volume level
bool readyForNext = true;				// waiting/ready for next loud trigger event flag


Timer delayTimer(1000, sendTrigger, true);		// timer for delaying trigger output, period adjusted dynamically
Timer deadTimer(deadTime, resetSystem, true);	// timer that resets system to allow next peak to be detected


// this gets called early, before any cloud connectivity etc.
STARTUP(
	WiFi.disconnect();					// don't need a cloud connection for this application
	WiFi.off();							// Photon RGB LED should slowly flash white
)

void setup() {
	pinMode(aboveThreshold, OUTPUT);
	digitalWrite(aboveThreshold, HIGH);		// brief on-board led flash to indicate starting up
	delay(500);
	digitalWrite(aboveThreshold, LOW);
  	pinMode(triggerOut, OUTPUT);
  	digitalWrite(triggerOut, LOW);
}


void loop() {

	volume = (float)(analogRead(audioIn)*3.3/4095);		// read and convert to volts
	volume = abs(volume - offset);

	pinMode(volumeIndicator, OUTPUT);					// for DAC need to continually make an output
	analogWrite(volumeIndicator, 4095*volume/3.3 );		// indicate volume

// if above threshold and trigger isn't active, start the trigger process
	if ( volume > threshold ) {
		digitalWrite(aboveThreshold, HIGH);
		if (readyForNext) {
			readyForNext = false;
			startTimers();
		}
	}
	else {
		digitalWrite(aboveThreshold, LOW);
	}

}


// volume detected an above-threshold event, start the send-trigger timer!
void startTimers() {
	int delayVoltage = analogRead(delayAdjust);					// 0..4095 for 0-3.3V
	int triggerDelay = map(delayVoltage, 0, 4095, 0, maxDelay);	// convert to delay (ms)
	delayTimer.changePeriod(triggerDelay);						// update the timer period for next event
	delayTimer.start();
	deadTimer.start();
}

// send a trigger to start the experiment
void sendTrigger() {
	digitalWrite(triggerOut, HIGH);			// send the trigger to the experiment
	delay(10);
	digitalWrite(triggerOut, LOW);
}

void resetSystem() {
	readyForNext = true;
}
