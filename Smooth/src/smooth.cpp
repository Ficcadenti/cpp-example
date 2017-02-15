/*
 * DateTime.cpp
 *
 * Copyright (C) 2016-2016 by Raffaele Ficcadenti
 * All rights reserved.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
// Smooth: classe c+ per lo smoothing di un array.
//
////////////////////////////////////////////////////////////////////////////////
#include "smooth.h"

Smooth::Smooth(void)
{}

Smooth::~Smooth(void)
{}

void Smooth::MyCopy(int vet_size,double *vet_sorg,double *vet_dest)
{
	int i;
	for(i=0;i<vet_size;i++)
	{
	 	vet_dest[i]=vet_sorg[i];
	}
}

double Smooth::MyMedian(int n,double *valori)
{
	int i = 0,j;
	double val, mediana = -1.0;
	int minori, maggiori;
	
	while (i < n && mediana == -1.0) 
	{
	    minori = 0;
	    maggiori = 0;
	    val = valori[i];
	    for (j = 0 ; j < n ; j++) 
	    {
		if (valori[j] <= val) 
		{
		    minori++;
		}
		if (valori[j] >= val)
		{
		    maggiori++;
		}
	    }
	    if (minori >= (n+1)/2 && maggiori >= (n+1)/2)
	    {
		mediana = val;
	    }
	    i++;
	}
	return mediana;
}

double Smooth::MyMinElement(int vet_size,double *vet_sorg)
{
	double min;
	int i;
	
	min=vet_sorg[0];
	
	for(i=1;i<vet_size;i++)
	{
	 	if(vet_sorg[i]<min)
	 	{
	 		min=vet_sorg[i];
	 	}
	}
	
	return min;
}

double Smooth::MyMax(double a, double b)
{ 
	return a >= b ? a : b; 
}


void  Smooth::MySmoothArray(int nn, double *xx, int ntimes)
{

	int jj, jk, ii, pass, noent, kk, medianType, ifirst, ilast;
	double hh[6] = {0,0,0,0,0,0};
	double xmin;
	double *yy = NULL,*zz = NULL,*rr = NULL;
	
	if (nn < 3 ) 
	{
		printf(" Error: SmoothArray->Need at least 3 points for smoothing: n = %d\n",nn);
		return;
	}
	
	yy = (double*)malloc(nn*sizeof(double));
	zz = (double*)malloc(nn*sizeof(double));
	rr = (double*)malloc(nn*sizeof(double));
	
	for (pass=0;pass<ntimes;pass++) 
	{
		/* first copy original data into temp array */
		MyCopy(nn, xx, zz );
      	
		for (noent = 0; noent < 2; ++noent) 
		{ /* run algorithm two times */

			/*  do 353 i.e. running median 3, 5, and 3 in a single loop */
			for  (kk = 0; kk < 3; kk++)  
			{
				MyCopy(nn, zz, yy);
				medianType	= (kk != 1)  ?  3 : 5;
				ifirst		= (kk != 1 ) ?  1 : 2;
				ilast		= (kk != 1 ) ? nn-1 : nn -2;
		        	
				/* nn2 = nn - ik - 1;
				   do all elements beside the first and last point for median 3
				   and first two and last 2 for median 5 */
				for  ( ii = ifirst; ii < ilast; ii++)  
				{
					/* assert(ii - ifirst >= 0); */
					if (ii - ifirst < 0) break;
					
					for  (jj = 0; jj < medianType; jj++)   
					{
						hh[jj] = yy[ii - ifirst + jj ];
					}
					zz[ii] = MyMedian(medianType, hh);
				}
				
				if  (kk == 0)  
				{   /* first median 3 */
					/* first point */
					hh[0] = zz[1];
					hh[1] = zz[0];
					hh[2] = 3*zz[1] - 2*zz[2];
					zz[0] = MyMedian(3, hh);
					/* last point */
					hh[0] = zz[nn - 2];
					hh[1] = zz[nn - 1];
					hh[2] = 3*zz[nn - 2] - 2*zz[nn - 3];
					zz[nn - 1] = MyMedian(3, hh);
				}
            	
				if  (kk == 1)  
				{   /*  median 5 */
					for  (ii = 0; ii < 3; ii++) 
					{
						hh[ii] = yy[ii];
					}
					zz[1] = MyMedian(3, hh);
					/* last two points */
					for  (ii = 0; ii < 3; ii++) 
					{
						hh[ii] = yy[nn - 3 + ii];
					}
					zz[nn - 2] = MyMedian(3, hh);
				}
			}
			
			MyCopy ( nn, zz, yy );
			
			/* quadratic interpolation for flat segments */
			for (ii = 2; ii < (nn - 2); ii++)
			{
				if  (zz[ii - 1] != zz[ii]) 
				{
					continue;
				}
				if  (zz[ii] != zz[ii + 1])
				{
					continue;
				}
				hh[0] = zz[ii - 2] - zz[ii];
				hh[1] = zz[ii + 2] - zz[ii];
				if  (hh[0] * hh[1] <= 0)
				{
					continue;
				}
				jk = 1;
				if  ( fabs(hh[1]) > fabs(hh[0]) )
				{
					jk = -1;
				}
				yy[ii] = -0.5*zz[ii - 2*jk] + zz[ii]/0.75 + zz[ii + 2*jk] /6.;
				yy[ii + jk] = 0.5*(zz[ii + 2*jk] - zz[ii - 2*jk]) + zz[ii];
			}
			
			/* running means */
			for  (ii = 1; ii < nn - 1; ii++) 
			{
				zz[ii] = 0.25*yy[ii - 1] + 0.5*yy[ii] + 0.25*yy[ii + 1];
			}
			zz[0] = yy[0];
			zz[nn - 1] = yy[nn - 1];
			
			if (noent == 0) 
			{
				/* save computed values */
				MyCopy(nn, zz, rr);
		    
				/* COMPUTE  residuals */
				for  (ii = 0; ii < nn; ii++)
				{
				    zz[ii] = xx[ii] - zz[ii];
				}
			}
		} /* end loop on noent */
		
		xmin = MyMinElement(nn,xx);
		for  (ii = 0; ii < nn; ii++) 
		{
			if (xmin < 0) 
			{
				xx[ii] = rr[ii] + zz[ii];
			}
			/* make smoothing defined positive - not better using 0 ? */
			else
			{
				xx[ii] = MyMax((rr[ii] + zz[ii]),0.0 );
			}
		}
	}
	
	if(yy!=NULL) free(yy);
	if(zz!=NULL) free(zz);
	if(rr!=NULL) free(rr);
}

void Smooth::PrintArray(int vet_size,double *vet_sorg)
{
	for(int i=0;i<vet_size;i++)
	{
		printf("Array[%d]=%f\n",i,vet_sorg[i]);
	}
}
