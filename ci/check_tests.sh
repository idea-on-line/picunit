#!/bin/sh

# The MIT License (MIT)
# 
# Copyright (c) <2013> IDEA. SOC. COOP.
# 
# Author: Angelo Compagnucci <a.compagnucci@idea-on-line.it>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

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
