# IR Remote Decoder

## Prerequisites

* LAN connected LXI suppoted oscilloscope (currently, only tested for RIGOL DS1102 ZE. Maybe workes for DS1000Z series.)
* lxi-tools
* bash
* make
* sed
* g++

## Build

```sh
$ make
```

## Usage

Decoded bytes are printed by following commands. Replace `192.168.xxx.xxx` to your oscilloscope's ip address.

```sh
$ bash decode.sh 192.168.xxx.xxx
2c 52 09 3d 34
```