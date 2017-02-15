/*
 * DateTime.h
 *
 * Copyright (C) 2016-2016 by Raffaele Ficcadenti
 * All rights reserved.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
// DateTime
//
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>

using namespace std;

class DateTime 
{

public:
	DateTime();
	~DateTime();
	void showTime(const char *msg);
	
	void splitTicks(time_t time);
	
private:
   	int seconds;
   	int minutes;
   	int hours;
   	int year;
   	int month;
   	int day;
   
   	bool isLeap(int year);
	int daysPerMonth (int year,int month);
	int daysInYear (int year);
	int reduceDaysToYear(time_t &days);
	int reduceDaysToMonths(time_t &days,int year);

};
