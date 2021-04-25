
#include <stdio.h>      /* printf */
#include <math.h>       /* cos */
#include <time.h> 
#include <vector>
#include <iostream>

// random_device example
#include <random>

#define PI 3.14159265
using namespace std;

#pragma once


class cpoint
{
	public:
	double x;
	double y;
	double z;
	double r;

	cpoint();
	~cpoint();
};

#pragma once
class xpoint
{
public:


	double time;
	double degree[3];

	cpoint diff;

	cpoint pos;
	cpoint base;

	cpoint goal_A;
	cpoint goal_B;
	cpoint goal_C;


	bool stop;

	void update();

	void cat(cpoint *A, cpoint *B, cpoint *C);
	void bird();

	xpoint();
	~xpoint();
};

