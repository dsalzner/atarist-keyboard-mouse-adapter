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

#pragma once

#define CORE_INT_EVERY_PIN 1

#include "PS2Keyboard.h"
#include "keymap.h"

#define KEY_DATA 2
#define KEY_CLK 3

PS2Keyboard keyboard;

void keyboardSetup() {
  keyboard.begin(KEY_DATA, KEY_CLK);
}

/***************************************************************************//**
 * keyboardLoop
 *
 * Handles PS/2 Keyboard Input and sends to Atari ST
 *
 * @param none
 * @return whether or not a key was sent
 ******************************************************************************/
void keyboardLoopInternal() {
  #ifdef PC_DEBUG
    PS2Keyboard keyboard2;
    if (keyboard2.available()) {
      char c = keyboard2.read();
      if (c == PS2_ENTER) {
        Serial.println();
      } else if (c == PS2_TAB) {
        Serial.print("[Tab]");
      } else if (c == PS2_ESC) {
        Serial.print("[ESC]");
      } else if (c == PS2_PAGEDOWN) {
        Serial.print("[PgDn]");
      } else if (c == PS2_PAGEUP) {
        Serial.print("[PgUp]");
      } else if (c == PS2_LEFTARROW) {
        Serial.print("[Left]");
      } else if (c == PS2_RIGHTARROW) {
        Serial.print("[Right]");
      } else if (c == PS2_UPARROW) {
        Serial.print("[Up]");
      } else if (c == PS2_DOWNARROW) {
        Serial.print("[Down]");
      } else if (c == PS2_DELETE) {
        Serial.print("[Del]");
      } else {
        Serial.print(c);
      }
    }
  #endif
}
