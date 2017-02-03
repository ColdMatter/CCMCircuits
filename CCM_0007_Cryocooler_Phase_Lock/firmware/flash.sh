#!/bin/bash

clear

echo "flashing latest firmware..."

particle flash --usb photon_firmware*

echo "flash complete."
