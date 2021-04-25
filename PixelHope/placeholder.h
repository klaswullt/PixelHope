#pragma once
/*

code 1
				local_space.x = (i * mod_proj_x.x) + (j * mod_proj_y.x) ;  //* frame_to_frame_proj_x.x;
				local_space.y = (i * mod_proj_x.y) + (j * mod_proj_y.y) ; // * frame_to_frame_proj_x.y;


				local_space.x = (i * mod_proj_x.x) + (j * mod_proj_y.x) ;  //* frame_to_frame_proj_x.x;
				local_space.y = (i * mod_proj_x.y) + (j * mod_proj_y.y) ; // * frame_to_frame_proj_x.y;



				world_space.x = (local_space.x * proj_x.x ) + (local_space.y * proj_y.x) + 100;
				world_space.y = (local_space.x * proj_x.y ) + (local_space.y * proj_y.y) + 100;



*/


/*
code 2
	N = (i - (N * proj_y.x) - 100)/ proj_x.x;

	M = (j  - (M * proj_x.y) - 100) /proj_y.y ;


	local_space.x = (world_space.x - (local_space.y * proj_y.x) - 100)/ proj_x.x;

	local_space.y = ( world_space.y  - (local_space.x * proj_x.y) - 100) /proj_y.y ;


	you need a vector axis X (x,y,z)
	and a      vector axis Y (x,y,z)

	X_axis



	*/


	////////////////////////////////////////////////////////////////////////////////////////////
	/*
	code 3
	world_space.x = ( (i * mod_proj_x.x) + (j * mod_proj_y.x) * proj_x.x ) + ( i * mod_proj_x.y) + (j * mod_proj_y.y * proj_y.x) + 100;
	world_space.y = ( (i * mod_proj_x.x) + (j * mod_proj_y.x) * proj_x.y ) + ( i * mod_proj_x.y) + (j * mod_proj_y.y * proj_y.y) + 100;

*/