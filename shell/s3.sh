#!/bin/bash
set -x #Debug is switched on
echo "Enter the name"
read Name
echo "Welcome, $Name"
set +x #Debug is switched off
echo "Enter the value of x"
read x
echo "x = $x"
