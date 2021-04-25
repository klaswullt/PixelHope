#pragma once
#include "olcPixelGameEngine.h"
#include <vector>

using namespace::std;

class geometry
{

	struct point
	{
		olc::Pixel color;
		olc::vd2d vector;
		double z;

	};


	double rotation_x[4][4];

	public :
	
		vector<point> buffer;

		vector<point> drawbuffer;






	int light[200][200];

	int N[200][200];
	int M[200][200];

	int g;

	void update()
	{

		for (int i = 1; i <= 199; i++)
		{
			for (int j =  1; j <= 199; j++)
			{
				if (N[i][j] == 1)
				{
					N[i][j] = 0;

					point new_point;
					new_point.vector.x = i;
					new_point.vector.y = j;
					new_point.z = g;
					new_point.color.r = (M[i][j]*2) +50;
					new_point.color.g = 200;
					new_point.color.b  = i*2 +50;

					buffer.push_back(new_point);

					M[i][j]++;
				};
				if (N[i][j] == 2)
				{
					N[i][j] = 0;

					point new_point;
					new_point.vector.x = i;
					new_point.vector.y = j;
					new_point.z = g;
					new_point.color.r = 50;
					new_point.color.g = 50;
					new_point.color.b = 200;

					buffer.push_back(new_point);

					M[i][j]++;
				};
			}
		}


		rotation_x[0][1] = 1;
		rotation_x[0][2] = 0;
		rotation_x[0][3] = 0;
		rotation_x[0][4] = 0;
		rotation_x[1][1] = 0;
		rotation_x[1][2] = cos(0.5);
		rotation_x[1][3] = cos(0.5);
		rotation_x[1][4] = 0;
		rotation_x[2][1] = 0;
		rotation_x[2][2] = -cos(0.5);
		rotation_x[2][3] = cos(0.5);
		rotation_x[2][4] = 0;
		rotation_x[3][1] = 0;
		rotation_x[3][2] = 0;
		rotation_x[3][3] = 0;
		rotation_x[3][4] = 1;




		for (int i = buffer.size() - 1; i > 1; i--)
		{

			point new_point = buffer[i];

			new_point.vector.x = buffer[i].vector.x  ;
			new_point.vector.y = buffer[i].vector.y  ;
			new_point.z        = buffer[i].z ;


			 
			 
			

	



		}

	}





};

