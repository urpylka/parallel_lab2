// parallel_lab2.cpp: главный файл проекта.

#include "stdafx.h"

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <intrin.h>
#include <iostream>
#include <omp.h>
using namespace std;

#pragma intrinsic(__rdtsc)

void main()
{
	unsigned __int64 t0, t;

	const double l = 1;
	//double min_x = 0;
	double max_x = l / 2;
	//double min_fi = 0;
	double max_fi = M_PI; //double max_fi = 2 * M_PI;

	double x;
	double fi;

	double my_pi;
	double my_err;
	double my_time;

	__int64 n = 0;
	__int64 i = 0;
	__int64 count = 10000;
	cout << "my_pi\terror\tcount\ttime" << endl;
back:
	t0 = __rdtsc();
	for (; i < count; i++)
	{
		x = ((double)rand() / (double)RAND_MAX) * max_x;
		fi = ((double)rand() / (double)RAND_MAX) * max_fi;
		if (x <= sin(fi)*max_x) n++;
	}
	t = __rdtsc();
	my_pi = (2*count) / (double)n;
	my_err = abs(M_PI - my_pi);
	my_time = (double)(t - t0) / 2000000000;
	cout << my_pi << "\t"<< my_err << "\t" << count << "\t" << my_time << endl;
	count *= 10;
	goto back;
}
