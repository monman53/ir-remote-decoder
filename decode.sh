#!/bin/bash

set -e

IPADDR=$1

MDEPTH=`lxi scpi :acquire:mdepth? -a $IPADDR`

lxi scpi ":waveform:start 1" -a $IPADDR
lxi scpi "waveform:stop $MDEPTH" -a $IPADDR

lxi scpi waveform:data? -a $IPADDR | cut -c 12- | sed 's/,/\n/g' | ./decoder $MDEPTH