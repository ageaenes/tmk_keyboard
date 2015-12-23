Compact L3 keyboard firmware
============================
Custom keyboard designed by LifeZone and LeeKu.

*Note that this is not the official firmware. By using this firmware you won't get any
support from LeeKu nor LifeZone.*

Supported models
----------------
This firmware was developed and tested for COMPACT L3 pcb version 1.1

All pcb options are supported.

This firmware will currently run only as USB Keyboard. PS2 protocol is currently not
supported.

Build
-----
Move to this directory then just run `make` like:

    $ make

This will create a firmware with default "winkey" keymap. To compile a different keymap
run make like this:

    $ make KEYMAP=winkey

Bootloader
---------
This firmware was tested with 'BootloadHID' an USB boot loader for AVR microcontrollers.

   https://www.obdev.at/products/vusb/bootloadhid-de.html

To compile the bootloader use the configuration header "bootloaderconfig.h"
and the make file "Makefile.bootloader" coming with this firmware.

   $ make

To flash the custom bootloader an AVR programmer is required.

   $ make flash

Once the bootloader is flashed to your keyboard you can enter it by pressing ESC after
the USB cable was attached. Your keyboard is now listed as bootHID in your device tree.

To flash tmk firmware to your keyboard you have to enter bootloader and then use
BootloadHID command line tool.

   $ ./bootloadHID -r l3.hex
