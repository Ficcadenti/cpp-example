#----------------------------------------------------------------
#
#  Makefile for Date Time
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

CFLAGS = -g -Wall -std=c++11  -L/usr/local/lib -I$(SUBDIR)/src -I$(SUBDIR)/inc 

LDFLAGS = 

TARGET = test_datetime

SORGENTI 	=      $(SUBDIR)/src/main.cpp\
				   $(SUBDIR)/src/datetime.cpp

HEADERS =       $(SUBDIR)/inc/datetime.h			
                

$(TARGET): $(SORGENTI)
	$(CC) $(CFLAGS) -o $(TARGET) $(LDFLAGS) $(SORGENTI) $(HEADERS)


all: $(TARGET)

clean:
	$(RM) $(TARGET)

realclean:
	$(RM) $(BINDIR)/$(TARGET)

install:
	$(CP) $(TARGET) $(BINDIR)
