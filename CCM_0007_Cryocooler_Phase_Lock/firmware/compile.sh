#!/bin/bash

clear

echo "removing old firmware file(s)..."

rm *.bin

echo "compiling..."

particle compile photon

echo "compilation complete"
