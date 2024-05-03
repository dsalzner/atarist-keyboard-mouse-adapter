## Fork, then clone

```
git clone git@github.com:<your-username>/atarist-keyboard-mouse-adapter.git
```

## Solder the board

It's a simple Atmega328 circuit, [see Details](https://www.dennissalzner.de/retrocomp/2023/06/13/Di-AtariStKeyboardMouse.html)

## (Optional) Arduino IDE

* Install the Arduino IDE and load the project.

## Or on Linux, run standalone build script

```
./build.sh
```

It will download arduino-cli, set up the dependencies build and flash for you

## (Optional) Open the serial port for debug messages

In the Arduino IDE via the ```Serial Monitor```

On Linux you can run

```
./debug.sh
```
