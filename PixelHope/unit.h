#include "olcPixelGameEngine.h"
#pragma once

#define PI 3.14159265





class unit
{
public:

	struct kw_vector
	{
	int x;
	int y;
	int z;
	int c;
	};
	
	struct kw_velocity
	{
		int velocity;
		double accellation;
		double energy;
	};


	olc::Sprite* Xsprite;


	kw_vector position;

	kw_velocity velocity;
	kw_vector direction;

	void update();

	unit();
	~unit();
};

