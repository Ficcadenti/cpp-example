/*
 * main.cpp
 *
 * Copyright (C) 2016-2016 by Raffaele Ficcadenti
 * All rights reserved.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
// test_datetime
//
////////////////////////////////////////////////////////////////////////////////


//My Class
#include "datetime.h"

#include <iostream>
#include <stdlib.h>
#include <string>


int main (int   argc, char *argv[])
{

	DateTime dt;
	std::string::size_type sz;   
		
	int i_start = std::stoi(argv[1],&sz);
	int i_stop = std::stoi (argv[2],&sz);
		
	printf("Start-time:%d    Stop-time:%d\n",i_start,i_stop);
	dt.splitTicks(i_start);dt.showTime("Start time=");
	dt.splitTicks(i_stop);dt.showTime("Stop time=");
		
	return 0;
}