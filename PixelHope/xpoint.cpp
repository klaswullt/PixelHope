#include "xpoint.h"

cpoint::cpoint()
{

	 y = 0;
	 z = 0;
	 r = 0;


}

cpoint::~cpoint()
{



}

void xpoint::cat(cpoint *A, cpoint *B, cpoint *C)
{

	 goal_A.x = A->x;
	 goal_A.y = A->y;

	 goal_B.x = B->x - A->x;
	 goal_B.y = B->y - A->y;

	 goal_C.x = C->x - A->x;
	 goal_C.y = C->y - A->y;



	 diff.x = goal_B.x - (sin(45 * PI / 180) * goal_C.x) ;
	 diff.y = goal_B.y - (sin(45 * PI / 180) * goal_C.y) ;


	double hug = (sin( 45 * PI / 180)* goal_C.x ) + (sin((90)* PI / 180) * diff.x);


	 base.x = A->x;
	 base.y = A->y;
	 stop = false;
}

void xpoint :: bird()
{
 // I cant name this.. lets call it bird


	degree[1] = time;
	degree[2] = time * (2.0);

 
	pos.x = base.x + (sin(degree[1] * PI / 180)* goal_C.x) + (sin((degree[2])* PI / 180) * diff.x);
	pos.y = base.y + (sin(degree[1] * PI / 180)* goal_C.y) + (sin((degree[2])* PI / 180) * diff.y);



 
}

void xpoint::update()
{
	time += 0.2;


	if (time > 90)
	{
		time = 0;
		stop = true;
	}

	bird();

}

xpoint::xpoint()
{
	pos.x = 0;
	pos.y = 0;

	diff.x = 0;
	diff.y = 0;

	degree[0] = 0;
	degree[1] = 0;
	degree[2] = 0;

	time = 0;


}


xpoint::~xpoint()
{
}
