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

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	0
#endif

#ifndef LAYOUT_HAPPY
#    define LAYOUT_HAPPY 0
#endif
#ifndef LAYOUT_MINI
#    define LAYOUT_MINI 0
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static uint8_t read_rows(void);
static uint8_t read_caps(void);
static void init_rows(void);
static void unselect_cols(void);
static void select_col(uint8_t col);

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    unselect_cols();
    init_rows();
    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++)  {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);    
        _delay_us(3); // TODO: Determine the correct value needed here.
        uint8_t rows = read_rows();
        if((col == 0 && !LAYOUT_MINI) || (col == 2 && LAYOUT_MINI) ) {
            rows |= read_caps();
        }
        
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = matrix_debouncing[row] & ((matrix_row_t)1<<col);
            bool curr_bit = rows & (1<<row);
            if (prev_bit != curr_bit) {
                matrix_debouncing[row] ^= ((matrix_row_t)1<<col);
                if (debouncing) {
                    dprint("bounce!: "); dprintf("%02X", debouncing); dprintln();
                }
                debouncing = DEBOUNCE;
            }
        }
        unselect_cols();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }
    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        xprintf("%02X: %032lb\n", row, bitrev32(matrix_get_row(row)));
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop32(matrix[i]);
    }
    return count;
}

/* Row pin configuration TKL size, On Happy 60%, B7 is not used.
 * row: 0   1   2   3   4   5
 * pin: D0  D1  D2  D3  D5  B7
 *
 * Caps lock uses its own pin PE2
 */

static void init_rows(void)
{
    // Input (DDR:0, PORT:0) for matrix
    DDRD  &= ~0b00101111;
    PORTD &= ~0b00101111;
    if(!LAYOUT_HAPPY && !LAYOUT_MINI){
        DDRB  &= ~(1<<7);
        PORTB &= ~(1<<7);
    }
    // Input with pull-up, for CAPS lock
    DDRE &= ~(1<<2);
    PORTE |= (1<<2);
}

static uint8_t read_rows()
{
    if(LAYOUT_HAPPY || LAYOUT_MINI){
        return (PIND&(1<<0) ? (1<<0) : 0) |
               (PIND&(1<<1) ? (1<<1) : 0) |
               (PIND&(1<<2) ? (1<<2) : 0) |
               (PIND&(1<<3) ? (1<<3) : 0) |
               (PIND&(1<<5) ? (1<<4) : 0);
    }else{
        return (PIND&(1<<0) ? (1<<0) : 0) |
               (PIND&(1<<1) ? (1<<1) : 0) |
               (PIND&(1<<2) ? (1<<2) : 0) |
               (PIND&(1<<3) ? (1<<3) : 0) |
               (PIND&(1<<5) ? (1<<4) : 0) |
               (PINB&(1<<7) ? (1<<5) : 0);
    }

}

static uint8_t read_caps(void)
{
    if(LAYOUT_HAPPY || LAYOUT_MINI){
        return PINE&(1<<2) ? 0 : (1<<2);
    }
    else{
        return PINE&(1<<2) ? 0 : (1<<3);
    }
}

/* Columns 0 - 15 TKL SIZE
 * These columns uses two 74HC238D 3 to 8 bit demultiplexers.
 * col / pin:    PC6  PB6  PF0  PF1  PC7
 * 0:             1    0    0    0    0
 * 1:             1    0    1    0    0
 * 2:             1    0    0    1    0
 * 3:             1    0    1    1    0
 * 4:             1    0    0    0    1
 * 5:             1    0    1    0    1
 * 6:             1    0    0    1    1
 * 7:             1    0    1    1    1
 * 8:             0    1    0    0    0
 * 9:             0    1    1    0    0
 * 10:            0    1    0    1    0
 * 11:            0    1    1    1    0
 * 12:            0    1    0    0    1
 * 13:            0    1    1    0    1
 * 14:            0    1    0    1    1
 * 15:            0    1    1    1    1
 *
 * col: 16
 * pin: PB5
 */

 /* Columns 0 - 14 HAPPY SIZE
 * These columns uses one 74HC237D 3 to 8 bit demultiplexer Column 0-8
 * col / pin:    PC6  PF0  PF1  PC7  PE6  PB0  PB7  PD4  PD6  PD7  PB4
 * 0:             1    0    0    0    0    0    0    0    0    0    0
 * 1:             1    1    0    0    0    0    0    0    0    0    0
 * 2:             1    0    1    0    0    0    0    0    0    0    0
 * 3:             1    1    1    0    0    0    0    0    0    0    0
 * 4:             1    0    0    1    0    0    0    0    0    0    0
 * 5:             1    1    0    1    0    0    0    0    0    0    0
 * 6:             1    0    1    1    0    0    0    0    0    0    0
 * 7:             1    1    1    1    0    0    0    0    0    0    0
 * 8:             0    0    0    0    1    0    0    0    0    0    0
 * 9:             0    0    0    0    0    1    0    0    0    0    0
 * 10:            0    0    0    0    0    0    1    0    0    0    0
 * 11:            0    0    0    0    0    0    0    1    0    0    0
 * 12:            0    0    0    0    0    0    0    0    1    0    0
 * 13:            0    0    0    0    0    0    0    0    0    1    0
 * 14:            0    0    0    0    0    0    0    0    0    0    1
 *
 *
 *
 */


/* Columns 0 - 14 MINI SIZE
 * These columns uses one 74HC237D 3 to 8 bit demultiplexer Column 0-8
 * col / pin:   PB5 PB6 PC6  PF0  PF1  PC7  PE6  PB0  PB7  PD4  PD6  PD7  PB4
 * 0:                   1    0    0    0    0    0    0    0    0    0    0
 * 1:                   1    1    0    0    0    0    0    0    0    0    0
 * 2:                   1    0    1    0    0    0    0    0    0    0    0
 * 3:                   1    1    1    0    0    0    0    0    0    0    0
 * 4:                   1    0    0    1    0    0    0    0    0    0    0
 * 5:             1    1    0    1    0    0    0    0    0    0    0
 * 6:             1    0    1    1    0    0    0    0    0    0    0
 * 7:             1    1    1    1    0    0    0    0    0    0    0
 * 8:             0    0    0    0    1    0    0    0    0    0    0
 * 9:             0    0    0    0    0    1    0    0    0    0    0
 * 10:            0    0    0    0    0    0    1    0    0    0    0
 * 11:            0    0    0    0    0    0    0    1    0    0    0
 * 12:            0    0    0    0    0    0    0    0    1    0    0
 * 13:            0    0    0    0    0    0    0    0    0    1    0
 * 14:            0    0    0    0    0    0    0    0    0    0    1
 *
 *
 *
 */
static void unselect_cols(void)
{
    if(LAYOUT_HAPPY){

        DDRB |= (1<<0) | (1<<4) | (1<<7);
        PORTB &= ~((1<<0) | (1<<4) | (1<<7));

        DDRD |= (1<<4) | (1<<6) | (1<<7);
        PORTD &= ~((1<<4) | (1<<6) | (1<<7));

        DDRE |= (1<<6);
        PORTE &= ~(1<<6);
    }else if(LAYOUT_MINI){

        DDRB |= (1<<0) | (1<<4) | (1<<7);
        PORTB &= ~((1<<0) | (1<<4) | (1<<7));

        DDRD |= (1<<4) | (1<<6) | (1<<7);
        PORTD &= ~((1<<4) | (1<<6) | (1<<7));

        DDRE |= (1<<6);
        PORTE &= ~(1<<6);

        DDRB |= (1<<5) | (1<<6);
        PORTB &= ~((1<<5) | (1<<6));
    }else{

        DDRB |= (1<<5) | (1<<6);
        PORTB &= ~((1<<5) | (1<<6));
    }

    DDRC |= (1<<6) | (1<<7);
    PORTC &= ~((1<<6) | (1<<7));

    DDRF |= (1<<0) | (1<<1);
    PORTF &= ~((1<<0) | (1<<1));
}

static void select_col(uint8_t col)
{
    // Output high (DDR:1, PORT:1) to select
    switch (col) {
       
    }

    if(LAYOUT_HAPPY){
        switch(col){
             case 0:
                PORTC |= (1<<6);
                break;
            case 1:
                PORTC |= (1<<6);
                PORTF |= (1<<0);
                break;
            case 2:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                break;
            case 3:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                break;
            case 4:
                PORTC |= (1<<6);
                PORTC |= (1<<7);
                break;
            case 5:
                PORTC |= (1<<6);
                PORTF |= (1<<0);
                PORTC |= (1<<7);
                break;
            case 6:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                PORTC |= (1<<7);
                break;
            case 7:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                PORTC |= (1<<7);
                break;
            case 8:  
                PORTE |= (1<<6);
                break;
            case 9:
                PORTB |= (1<<0);  
                break;
            case 10:
                PORTB |= (1<<7);
                break;
            case 11:
                PORTD |= (1<<4);
                break;
            case 12:
                PORTD |= (1<<6);
                break;
            case 13:
                PORTD |= (1<<7);
                break;
            case 14:
                PORTB |= (1<<4);
                break;
        }
    }else if(LAYOUT_MINI){
        switch(col){
            case 0:
                PORTB |= (1<<5);
                break;
            case 1:
                PORTB |= (1<<6);
                break;
            case 2:
                PORTC |= (1<<6);
                break;
            case 3:
                PORTC |= (1<<6);
                PORTF |= (1<<0);
                break;
            case 4:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                break;
            case 5:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                break;
            case 6:
                PORTC |= (1<<6);
                PORTC |= (1<<7);
                break;
            case 7:
                PORTC |= (1<<6);
                PORTF |= (1<<0);
                PORTC |= (1<<7);
                break;
            case 8:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                PORTC |= (1<<7);
                break;
            case 9:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                PORTC |= (1<<7);
                break;
            case 10:  
                PORTE |= (1<<6);
                break;
            case 11:
                PORTB |= (1<<0);  
                break;
            case 12:
                PORTB |= (1<<7);
                break;
            case 13:
                PORTD |= (1<<4);
                break;
            case 14:
                PORTD |= (1<<6);
                break;
            case 15:
                PORTD |= (1<<7);
                break;
            case 16:
                PORTB |= (1<<4);
                break;
        }
    }else{
        switch(col){
            case 0:
                PORTC |= (1<<6);
                break;
            case 1:
                PORTC |= (1<<6);
                PORTF |= (1<<0);
                break;
            case 2:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                break;
            case 3:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                break;
            case 4:
                PORTC |= (1<<6);
                PORTC |= (1<<7);
                break;
            case 5:
                PORTC |= (1<<6);
                PORTF |= (1<<0);
                PORTC |= (1<<7);
                break;
            case 6:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                PORTC |= (1<<7);
                break;
            case 7:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                PORTC |= (1<<7);
                break;
            case 8:
                PORTB |= (1<<6);
                break;
            case 9:
                PORTB |= (1<<6);
                PORTF |= (1<<0);
                break;
            case 10:
                PORTB |= (1<<6);
                PORTF |= (1<<1);
                break;
            case 11:
                PORTB |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                break;
            case 12:
                PORTB |= (1<<6);
                PORTC |= (1<<7);
                break;
            case 13:
                PORTB |= (1<<6);
                PORTF |= (1<<0);
                PORTC |= (1<<7);
                break;
            case 14:
                PORTB |= (1<<6);
                PORTF |= (1<<1);
                PORTC |= (1<<7);
                break;
            case 15:
                PORTB |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                PORTC |= (1<<7);
                break;
            case 16:
                PORTB |= (1<<5);
                break;
        }
    }
}
