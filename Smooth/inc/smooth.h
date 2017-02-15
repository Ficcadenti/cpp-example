/*
 * DateTime.h
 *
 * Copyright (C) 2016-2016 by Raffaele Ficcadenti
 * All rights reserved.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
// Smooth: classe c++ per lo smoothin di un array.
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Smooth 
{
	public:
		Smooth();
		~Smooth();
		void MySmoothArray(int nn, double *xx, int ntimes);
		void PrintArray(int vet_size,double *vet_sorg);
		
	private:
	   	void MyCopy(int vet_size,double *vet_sorg,double *vet_dest);
	   	double MyMedian(int n,double *valori);
	   	double MyMinElement(int vet_size,double *vet_sorg);
	   	double MyMax(double a, double b);

};
