# CCM 0010 RevD

This is revision D of the floating H-bridge + bypass circuit that we use to control our CaF MOT and transport coils.  The bypass circuit feedback/control should use circuit CCM_0008 or equivalent.  For the bypass circuit current sensing, any galvanically isolated current sensor can be used, but **do not** use a sense resistor.  The FET drive side is floating and will definitely break the lab-ground referenced feedback instrumentation amplifier on CCM_0008.

## RevD Changes
- The HIP4082 full h-bridge driver has been replaced by a HIP4081a.  The former drives the upper FET gates using (solely) a bootstrap supply that only recharges when switching the h-bridge.  We typically operate at or near 100% duty cycle so only very rarely switch the h-bridge.  This means that the bootstrap supply isn't operating properly, limiting the gate voltage available to drive the upper FET gates.  This is especially true when the voltage drop across the load approaches a few volts; the bootstrap supply is operating around 12V above local ground and combined with the load voltage drop limits the gate voltage available to the FET.  Using the IXFN360N FET at 150A, the voltage drop across the load (1/2 of the transport coils) is 8V, leaving only 4V for the FET gate-source voltage.  This means the FET is turning off when it should be conducting hard, meaning that the power dissipation is too high.  We've already lost one of the h-bridge FETs this way.  


## Known Issues
