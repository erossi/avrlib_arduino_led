# Copyright (C) 2017 Enrico Rossi
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

PRG_NAME = arduino_led

# space opt
OPTLEV = s

# Microcontroller definition
MCU = atmega328p
FCPU = 16000000UL

PWD = $(shell pwd)
INC = -I/usr/lib/avr/include/

# Compilers
AR = avr-ar
CXX = avr-g++
CC = $(CXX)

# Flags
CXXFLAGS := $(INC) -Wall -pedantic -std=c++14 -mmcu=$(MCU) -O$(OPTLEV) -D F_CPU=$(FCPU)
LFLAGS = -lm

## git version
#
GIT_TAG = "$(shell git describe --tags --long --always)"
PRGNAME = $(PRG_NAME)_$(GIT_TAG)_$(MCU)
ELFNAME = $(PRGNAME)_$@

# Program DUDE
DUDEPORT = /dev/ttyACM0
DUDEDEV = arduino
DUDE = avrdude -p $(MCU) -e -U flash:w:$(PRGNAME).hex

OBJCOPY = avr-objcopy -j .text -j .data -O ihex
OBJDUMP = avr-objdump
SIZE = avr-size --format=avr --mcu=$(MCU) $(PRGNAME).elf

REMOVE = rm -f

.PHONY: clean indent
.SILENT: help
.SUFFIXES: .cpp, .o

## Default
#
all: arduino_led.o
	$(CXX) $(CXXFLAGS) -o $(PRGNAME).elf blink.cpp arduino_led.o $(LFLAGS)
	$(OBJCOPY) $(PRGNAME).elf $(PRGNAME).hex

program:
	$(DUDE) -c $(DUDEDEV) -P $(DUDEPORT)

## CleanUp and tools
#
clean:
	$(REMOVE) *.elf *.hex *.o $(objects)

version:
	# Last Git tag: $(GIT_TAG)

size:
	$(SIZE)
