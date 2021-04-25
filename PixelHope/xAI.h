#pragma once
class xAI
{


	struct cell
	{
		struct node
	{
		double negative;
		double positive;
		double neutral;
		
		int yes_or_no; // 1 or 0 randomly

		cell * link;

	};
	
		node core;

		int onoff;

		int level;

		node* input[5];
		node* output[5];



	};


	public:


		cell bias; // the bias is an value representing if the character lives or die or is happy, it is an end result which modifies all other cells

		cell brain[9]; // [9] = [3 x 3] = [3 = x][3 = y] 
		// Meaning [x =1-3 perceptors][Y = 1]    or [1-3] perceptors
		//         [x = 1-3 intermediate level[ Y = 2] or [4-6] intermediates the thinking
		//         [x= 1- 3][ 3= y] the actualizers

		// brain[perceptors][1]      = [1-3][perceptors]    = [1-3][2]
		// brain[intermediates][2]   = [4-6][intermediates] = [1-3][2]
		// brain[actualizers][3]     = [7-9][actualizers]   = [1-3][3]


		void update();

		void revaluate_nodes(int braincell, int input);


};

