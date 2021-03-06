/*
Copyright 2013 Mathias Andersson <wraul@dbox.se>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "backlight.h"

/* Backlight pin configuration
 * F-row: High PB1
 * W: Low PB4
 * A: Low PB2
 * S: Low PB3
 * D: Low PD7
 */
void backlight_set(uint8_t level)
{
    // Set as output.
    DDRB |= (1<<1) | (1<<3) ;
    //DDRD |= (1<<7);

    
    // F-row
    if(level & BACKLIGHT_SWITCH)
    {
        backlight_switch_enable();
    }
    else
    {
        backlight_switch_disable();
    }
}

void backlight_switch_enable()
{
    PORTB &= ~(1<<1);
    PORTB |= (1<<3);
}

void backlight_switch_disable()
{
    PORTB |= (1<<1);
    PORTB &= ~(1<<3);
}


