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

#pragma once

#include "PS2Mouse.h"

#define MOU_DATA 4
#define MOU_CLK 5
PS2Mouse mouse(MOU_CLK, MOU_DATA, STREAM);
int16_t mouseX = 0;
int16_t mouseY = 0;
int16_t mouseXrel = 0;
int16_t mouseYrel = 0;

uint8_t lastMouse[3];

byte mouseButton = 0;

#define SET_RELATIVE_MOUSE_POSITIONING 0x08
#define SET_ABSOLUTE_MOUSE_POSITIONING 0x09
#define INTERROGATE_MOUSE_POSITION 0x0D

bool mouseInRelativeMode = true;

unsigned long mouseLastMillis = 0;

void mouseSetup() {
  mouse.initialize();
}

/***************************************************************************//**
 * mouseLoop
 *
 * Handles PS/2 Mouse Input and sends to Atari ST
 *
 * @param forceSend - send without reading from Serial first
 ******************************************************************************/
void mouseLoop(/*bool forceSend*/) {
  int16_t data[3];
  mouse.report(data); // -- is blocking code until mouse moves (!)
  mouseX = (mouseX + data[1]) % 65535;
  mouseY = (mouseY + data[2]) % 65535;

  mouseXrel += data[1];
  mouseYrel += data[2];

  while(Serial.available() > 0) {
      byte receivedByte = Serial.read();
      switch(receivedByte) {
        case SET_RELATIVE_MOUSE_POSITIONING:
          mouseInRelativeMode = true;
          return;
          break;
        case SET_ABSOLUTE_MOUSE_POSITIONING:
          mouseInRelativeMode = false;
          return;
          break;
        case INTERROGATE_MOUSE_POSITION:
          break;
        //case 0x13: // mouse - disable transmit
          //return;
       }
    }

  if(mouseInRelativeMode) {
    uint8_t mouse[3] = {0};

		mouse[0] = 0xF8;
	  if(data[0] == 9) {
	    mouse[0] = mouse[0] | 1 << 1;
    }
    /*if(data[0] == 10) {
      mouse[0] = mouse[0] | 1;
    }*/

    mouse[1] = mouseXrel;
    mouse[2] = -1 * mouseYrel;

    // -- check if values changes
    bool update = false;
    for(int i = 0; i < 3; i++) {
      if(lastMouse[i] != mouse[i]) {
        update = true;
        break;
      }
    }
    //if(!update) return; //-- always update

    // -- send data
    for(int i = 0; i < 3; i++) {

      #ifdef PC_DEBUG
        char buffer[10];
        int d = mouse[i];
        sprintf(buffer, "%d,", d);
        Serial.write(buffer);
      #else
        Serial.write(mouse[i]);
      #endif

      lastMouse[i] = mouse[i];
    }
    #ifdef PC_DEBUG
      Serial.write(" ");
    #endif

    mouseXrel = 0;
    mouseYrel = 0;
  }
}
