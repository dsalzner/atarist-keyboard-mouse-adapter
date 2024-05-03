# Atari ST Mega Keyboard and Mouse Adapter

An easy to solder Atari ST Keyboard and Mouse adapter that allows to connect most PS/2 keyboards and mice to the Atari ST.

Disclaimer:
* use at your own risk. If you solder the board incorrectly you could damage your Atari.

![Atari ST Keyboard Mouse Adapter Board](scrn/board.jpg)

* [Technical Information](https://www.dennissalzner.de/retrocomp/2023/06/13/Di-AtariStKeyboardMouse.html)
* [Releases](https://github.com/dsalzner/atarist-keyboard-mouse-adapter/releases)

## Dependencies

The code is inspired by and rewritten from [1]

1] https://oldcomputer.info/hacks/mega_key/index.htm

Additionally code from the Arduino PS/2 library "PS2Keyboard" is used [2]

2] http://www.arduino.cc/playground/Main/PS2Keyboard

And a Mouse library found here [3]

3] https://github.com/kristopher/PS2-Mouse-Arduino/


## Contributing & Compiling from source

The code can be compiled from source on Linux with the build.sh file.
The Arduino project file (*.ino) can also be loaded into the Arduino IDE and built from there.

Anyone is welcome to contribute, see [Guide on Contributing](CONTRIBUTING.md)

## Release History

### 2023-07-05

* both mouse and keyboard work, but sometimes moving the mouse while pressing a button locks the controller chip in the Atari ST and you'll have to reboot.
* code has some sort of a lock up likely due to an issue in my understanding of the Atari ST protocol.

##
