/* Copyright (C) 2017 Enrico Rossi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <avr/io.h>
#include "arduino_led.h"

void Arduino_Led::init()
{
	/* Arduino led L */
	PORTB &= ~_BV(PB5); // led off
	DDRB |= _BV(PB5); // DDR out
}

void Arduino_Led::shut()
{
	PORTB &= ~_BV(PB5); // led off
	DDRB &= ~_BV(PB5); // DDR in
}

void Arduino_Led::set(bool i)
{
	if (i)
		PORTB |= _BV(PB5);
	else
		PORTB &= ~_BV(PB5);
}
