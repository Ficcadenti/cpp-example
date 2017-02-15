/*
 * main.cpp
 *
 * Copyright (C) 2016-2016 by Raffaele Ficcadenti
 * All rights reserved.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
// test_smooth
//
////////////////////////////////////////////////////////////////////////////////


//My Class
#include "smooth.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DI_PASSAGGI 1


int main (int   argc, char *argv[])
{

	Smooth  _smooth;
	double *vett;
	int vett_size=20;
	
	vett=(double*)calloc(vett_size,sizeof(double));
	for(int i=0;i<vett_size;i++)
	{
		vett[i]=rand() % 100 + 1;
	}
	
	
	printf("My Smoothing -- Vettore originale: \n");
	_smooth.PrintArray(vett_size,vett);
	
	_smooth.MySmoothArray(vett_size,vett,NUMERO_DI_PASSAGGI);
	printf("\n My Smoothing -- Vettore dopo smoothing: \n");
	_smooth.PrintArray(vett_size,vett);
	
	return 0;
}