# CCM 0010 RevC

This is revision C of the floating H-bridge + bypass circuit that we use to control our CaF MOT coils (and soon also the transport coils).  The bypass circuit feedback/control should use circuit CCM_0008 or equivalent.  For the bypass circuit current sensing, any galvanically isolated current sensor can be used, but **do not** use a sense resistor.  The FET drive side is floating and will definitely break the lab-ground referenced feedback instrumentation amplifier on CCM_0008.

## RevC Changes
- Bypass control/feedback circuit was moved to lab-referenced potential (via circuit CCM_0008 or equivalent).  This allows some integration since there we have dual supplies available but requires the user to employ a galvanically isolated current sensor.  In revB we used a sense resistor, which due to the single supply limitation on the floating side required the feedback instrumentation amplifier to operate with its inputs near or at the negative rail.
- Optocoupler receiver op amp was changed to a LT1097, which is both highly precise, affordable, and can drive unlimited capacitive loads.
- Fixed missing ground connection on non-inverting input of optocoupler receiver op amp.


## Known Issues
