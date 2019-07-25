#
# Makefile to create main
#
# Aron Lebani
# 11 February 2016
#

# Paths
#
IDIR = ../include
LDIR = ../lib
ODIR = obj
BDIR = ../bin

# Compiler
#
CC = g++
CFLAGS = -I$(IDIR)

# Objects to create
#
OBJ = $(ODIR)/arcade.o \
	  $(ODIR)/math.o \
	  $(ODIR)/menu.o \
	  $(ODIR)/tools.o \
	  $(ODIR)/alien.o \
	  $(ODIR)/bullet.o \
	  $(ODIR)/character.o \
	  $(ODIR)/number.o \
	  $(ODIR)/ship.o

# Libraries
#
LIB = ncurses

# Pattern rule to create object files
#
$(ODIR)/%.o: %.cpp $(IDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS) -l$(LIB)

# Make everything
#
.PHONY: all

all: $(BDIR)/main

# Ultimate target
#
$(BDIR)/main: main.cpp $(OBJ)
	$(CC) -o $@ $< $(OBJ) $(CFLAGS) -l$(LIB)

# Dependencies
#
$(ODIR)/math.o: $(ODIR)/tools.o $(ODIR)/arcade.o $(ODIR)/number.o \
				$(ODIR)/ship.o $(ODIR)/bullet.o $(ODIR)/alien.o

$(ODIR)/menu.o: $(ODIR)/math.o $(ODIR)/tools.o $(ODIR)/alien.o

$(ODIR)/tools.o:

$(ODIR)/arcade.o:

$(ODIR)/alien.o: $(ODIR)/character.o $(ODIR)/number.o $(ODIR)/tools.o

$(ODIR)/bullet.o: $(ODIR)/character.o $(ODIR)/tools.o

$(ODIR)/character.o:

$(ODIR)/number.o: $(ODIR)/character.o $(ODIR)/tools.o

$(ODIR)/ship.o: $(ODIR)/character.o $(ODIR)/tools.o $(ODIR)/bullet.o

# Clean up rule
#
.PHONY: clean

clean:
	rm $(ODIR)/*.o
