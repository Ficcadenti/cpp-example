#----------------------------------------------------------------
#
#  Makefile for Smmoth
#
#  Author: Raffaele Ficcadenti
#
#----------------------------------------------------------------



#----------------------------------------------------------------
# Definitions:
#


CC = g++
CP = /usr/bin/cp
PREFIX=/usr/pamela
BINDIR=${PREFIX}/bin
SUBDIR=./

CFLAGS = -g -Wall -std=c++11 -L/usr/local/lib -I$(SUBDIR)/src -I$(SUBDIR)/inc 

LDFLAGS = 

TARGET = test_smooth

SORGENTI 	=      $(SUBDIR)/src/main.cpp\
				   $(SUBDIR)/src/smooth.cpp

HEADERS =       $(SUBDIR)/inc/smooth.h			
                

$(TARGET): $(SORGENTI)
	$(CC) $(CFLAGS) -o $(TARGET) $(LDFLAGS) $(SORGENTI) $(HEADERS)


all: $(TARGET)

clean:
	$(RM) $(TARGET)

realclean:
	$(RM) $(BINDIR)/$(TARGET)

install:
	$(CP) $(TARGET) $(BINDIR)
