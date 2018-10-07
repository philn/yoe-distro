# Notes on using Yoe on the Raspberry PI

[up](index.md)

## Building an image

1. `git clone git://github.com/YoeDistro/yoe-distro.git`
1. `cd yoe-distro`
1. `. raspberrypi3-64-envsetup.sh`
1. `yoe_setup`
1. `bitbake core-image-minimal`
1. insert SD card
1. `lsblk` (note sd card device, and substitute for /dev/sdX below)
1. `yoe_install_wic_image /dev/sdX core-image-minimal`
1. optional: configure console for serial port (see below)
1. `sudo eject /dev/sdX`
1. Install SD card in a Raspberry PI and enjoy your new image

Other Raspberry Pi variants can be built by sourcing the appropriate
envsetup file.

## Enable serial console

Currently, the images default to console only on HDMI display. If you want
the console on the serial port, you will need to edit two files in the
boot partition of the SD card.

* config.txt
  * add the following line to the end of the file: `enable_uart=1`
* cmdline.txt
  * add the following to the end of the kernel cmdline: `console=ttyAMA0,115200`

We would like to make this configurable in the near future.

## Connecting to rPI serial console

The Raspberry PI serial console is avaiable on the expansion header. A USB->serial
cable with flying leads is a convenient way to connect to this. [FTDI](https://www.ftdichip.com/Products/Cables/RPi.htm) (as well as many
other companies supply these cables). The below image shows how the FTDI cable is
connected:

![rPI serial console](raspberry-pi-serial-console.jpg)

The relevant signals are:

* FTDI Black (GND) <-> rPI Pin 6 (GND)
* FTDI Yellow (RXD) <- rPI Pin8 (TXD)
* FTDI Orange (TXD) -> rPI Pin10 (RXD)

See the [schematics](https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/README.md) for more information.

## rPI Power Supply

Some of the Raspberry PI products seem to be sensitive to power quality. It is recommended
to use a supply that outputs 5.1V such as the [official supply](https://www.raspberrypi.org/products/raspberry-pi-universal-power-supply/). An inadequate supply may result in lockups or
SD card file system corruption.