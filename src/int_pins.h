/*
Atari ST Keyboard and Mouse Adapter
Copyright (C) 2023 D.Salzner <mail@dennissalzner.de>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
see also
- https://github.com/arkadiuszmakarenko/USB2Atari/blob/master/stm32ToAtari/Core/Src/main.c
- https://oldcomputer.info/hacks/mega_key/index.htm
*/

// interrupt pins for known boards

// Teensy and maybe others automatically define this info
#if !defined(CORE_INT0_PIN)

// Arduino Mega
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Arduino Mega
  #define CORE_INT0_PIN  2
  #define CORE_INT1_PIN  3
  #define CORE_INT2_PIN  21
  #define CORE_INT3_PIN  20
  #define CORE_INT4_PIN  19
  #define CORE_INT5_PIN  18

// Arduino Due (untested)
#elif defined(__SAM3X8E__)
  #define CORE_INT_EVERY_PIN
  #ifndef PROGMEM
  #define PROGMEM
  #endif
  #ifndef pgm_read_byte
  #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
  #endif

// Arduino Leonardo (untested)
#elif defined(__AVR_ATmega32U4__) && !defined(CORE_TEENSY)
  #define CORE_INT0_PIN  3
  #define CORE_INT1_PIN  2
  #define CORE_INT2_PIN  0
  #define CORE_INT3_PIN  1

// Sanguino (untested)
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__) // Sanguino
  #define CORE_INT0_PIN  10
  #define CORE_INT1_PIN  11
  #define CORE_INT2_PIN  2

// Chipkit Uno32 (untested)
#elif defined(__PIC32MX__) && defined(_BOARD_UNO_)
  #define CORE_INT0_PIN  38
  #define CORE_INT1_PIN  2
  #define CORE_INT2_PIN  7
  #define CORE_INT3_PIN  8
  #define CORE_INT4_PIN  35

// Chipkit Mega32 (untested)
#elif defined(__PIC32MX__) && defined(_BOARD_MEGA_)
  #define CORE_INT0_PIN  3
  #define CORE_INT1_PIN  2
  #define CORE_INT2_PIN  7
  #define CORE_INT3_PIN  21
  #define CORE_INT4_PIN  20

// http://hlt.media.mit.edu/?p=1229
#elif defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
  #define CORE_INT0_PIN  2

// Arduino Uno, Duemilanove, LilyPad, Mini, Fio, etc...
#else
  #define CORE_INT0_PIN  2
  #define CORE_INT1_PIN  3

#endif
#endif
