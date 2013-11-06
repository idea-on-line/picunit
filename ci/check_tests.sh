#!/bin/sh

#
# Configure your project details here
#
MDB_DIR=/opt/microchip/mplabx/mplab_ide/bin/
PROJECT_DIR=~/DEV/IDEA/picunit/demo_picunit.X
HEX_FILE=demo_picunit.X.production.hex
DEVICE=PIC18F26K22
CONFIGURATION=SIMULATOR

PATH=$PATH:$MDB_DIR

cat << EOF > $PROJECT_DIR/ci_mdb.txt
Device $DEVICE
Hwtool SIM
Program "dist/$CONFIGURATION/production/$HEX_FILE"
Run
Wait 120000
Quit
EOF

cd $PROJECT_DIR
mdb.sh ci_mdb.txt | tee ci_output.log
exit $(cat ci_output.log | grep --text "ALL TESTS" | cut -d" " -f5)
