#!/bin/sh

#
# Configure your project details here
#
PROJECT_DIR=~/DEV/IDEA/picunit/demo_picunit.X
CONFIGURATION=SIMULATOR

cd $PROJECT_DIR
make clean
make CONF=$CONFIGURATION
