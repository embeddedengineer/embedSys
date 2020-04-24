# Node name.
NODE_NAME  = base

# Microcontroller name.
DEVICE     = atmega32

# Microcontroller clock frequency.
CLOCK      = 16000000

# Programmer type.
PROGRAMMER = usbasp

# Fuse values for avr: low.
LFU = 0xFF

# Fuse values for avr: high.
HFU = 0xD9

# Fuse values for avr: extended.
EFU = 0xFF

# Microcontroller fuses. 
FUSES      = -U lfuse:w:$(LFU):m -U hfuse:w:$(HFU):m -U efuse:w:$(EFU):m

# Compiler variable.
CC         = avr-gcc

# Object copy to generate the hex file.
OBJCOPY    = avr-objcopy

# Output file name.
OUT_FILE   = $(NODE_NAME)-node

# Source files name.
SRC        = led 

# Object files list.
OBJFILES   = ../src/main.o $(patsubst %, ../src/app/%.o, $(SRC))

# Release directory.
REL_DIR    = ../../Release

# Release number.
REL_NO     = $(shell cat VERSION)

# Full path to the current Release.
REL_PATH   = $(REL_DIR)/$(REL_NO)

# Release folder path for the current node.
NODE_PATH  =  $(REL_PATH)/$(NODE_NAME)

# Compiling flags.
# Error levels -w(ignore all warnings) -Wall(show all warnings) -Werror(stop compilaing process in case of any warning).
CCFLAGS    = -Wall

# Debug levels -g(enable the debugging symbols) -Og(optimize for debug).
CCFLAGS    += -g

# -O is the optimization level.
# levels 0(no opt) - 1 - 2 - 3(highest) - s(size) - g(debugging) - fast.
CCFLAGS    += -Os

# Set microcontroller type.
CCFLAGS    += -mmcu=$(DEVICE)

# Set clk frequency.
CCFLAGS    += -DF_CPU=$(CLOCK)

# Test programmer connectivity.
programmer:
	avrdude -c $(PROGRAMMER) -p $(DEVICE) -v

# Write fuses to the mcu.
fuse:
	avrdude -c $(PROGRAMMER) -p $(DEVICE) $(FUSES)

# Flash code to the mcu.
flash :
	echo "----------Start flashing base node hex----------"
	avrdude -p $(DEVICE) -c $(PROGRAMMER) -U flash:w:$(NODE_PATH)/$(OUT_FILE).hex:i -F -P usb

# Equivalent to %.o: %.c.
# $< is the 1st dependency.
# $@ is the filename representing the target.
.c.o:
	$(CC) $(CCFLAGS) -c $< -o $@

# Build the base-node code.
build : $(OBJFILES)
	mkdir -p $(NODE_PATH)
	$(CC) $(CCFLAGS) -o $(OUT_FILE).elf $(OBJFILES) 
	$(OBJCOPY) -j .text -j .data -O ihex $(OUT_FILE).elf $(OUT_FILE).hex
	avr-size --format=avr --mcu=$(DEVICE) $(OUT_FILE).elf
	rm -f $(OBJFILES) 
	mv $(OUT_FILE).elf $(NODE_PATH)/$(OUT_FILE).elf
	mv $(OUT_FILE).hex $(NODE_PATH)/$(OUT_FILE).hex
	 
# Clean all the files.
clean :
	rm -rf $(REL_PATH)