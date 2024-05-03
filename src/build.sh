#!/bin/bash
set -e

if [ -f "/home/codered/arduino-cli" ]; then
  echo "arduino-cli exists"
else
  cd "$HOME/"
  wget https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Linux_64bit.tar.gz
  tar -xvf arduino-cli_latest_Linux_64bit.tar.gz
fi

arduinocli="${HOME}/arduino-cli"

${arduinocli} config init --overwrite
${arduinocli} config add board_manager.additional_urls https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json
${arduinocli} core update-index
${arduinocli} core install MiniCore:avr
${arduinocli} board details --fqbn MiniCore:avr:328

${arduinocli} compile --fqbn MiniCore:avr:328 --board-options "clock=8MHz_internal" ../src/src.ino
${arduinocli} upload -P avrispmkii --verbose --fqbn MiniCore:avr:328 ../src/src.ino

avrdude="$HOME/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude"
${avrdude} -C $HOME/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf -v -V -patmega328p -cavrispmkII -Pusb -U lfuse:w:0xE2:m

echo "Reset the board (e.g. by pulling FTDI off and reinserting)"
