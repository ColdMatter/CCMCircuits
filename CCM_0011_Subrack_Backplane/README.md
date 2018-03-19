Subrack Backplane
===========
     
This circuit is an attempt to create a subrack standard for CCM circuits.  It uses a 64-pin bus based on the EURO-card standard (100 mm tall boards x various lengths, typically 160 mm) using DIN41612 "Type B" connectors.  The bus provides separate analog and digital ground planes and associated power supplies of +/-15V and +/-5V, respectively.  The backplane provides female connectors with a 4HP pitch.

We have a number of existing circuits that use a 32-pin rear connector (actually a 64-pin connector with half of the pins unpopulated).  The bus standard defined here should be compatible with our existing circuits.

In addition to power rails, the backplane also provides various communication buses, which can be used with microcontroller projects.  Take care though, the GPIOX and ANX lines are shared across all daughter boards, which can cause conflicts if you aren't careful.  In a similar vein, please only install a single power-supply module!  