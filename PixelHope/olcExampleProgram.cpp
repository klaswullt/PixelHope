#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"

#include "unit.h"
#include <vector>
#include <random>
#include "geometry.h"


using namespace::std;

struct kw_tile
{

	int obstacle;
	int temperature;
	int flag;
	int id;
};

struct kw_proj
{
	olc::vd2d X;
	olc::vd2d Y;
	olc::vd2d Z;

};

void placeholder();


class Example : public olc::PixelGameEngine
{
public:



	olc::vf2d getpos;
	olc::vf2d mouse;

	olc::vf2d screen_space;

	olc::vf2d hex_space;
	

	olc::vf2d Global;

	olc::vf2d Local;

	olc::vf2d Iso;



	std::default_random_engine generator;


	vector<unit> units;
	
	olc::Sprite * Xsprite;

	olc::Sprite* Xtile;

	olc::Sprite* tile_overlay;

	unit new_unit;

	int tile_lvl[61][61];

	int t_overlay[20][20]; // 3 x 3 tiles

	geometry map;



	int moveability;


	Example()
	{
		sAppName = "Example";
	}

public:

	bool OnUserCreate() override
	{
		Xsprite = new olc::Sprite("fuckman.png");
		
		Xtile = new olc::Sprite("load/isometric_demo.png");

		Xtile->SaveToPGESprFile("go");

		tile_overlay = new olc::Sprite("ground_overlay.png");

		double IsoW = 1;
		double IsoH = 0.5;
		
		Iso.x =  77+20; 
		Iso.y = 10;
		SetDrawTarget(Xtile);
		
		for (double i = -10; i <= 10; i++)
		{
			for (double j = -10; j <= 10; j++)
			{

				Local.x = i ;
				Local.y = j ;

				Global.x = Iso.x + (Local.x - Local.y) * IsoW;
				Global.y = Iso.y + (Local.x + Local.y) * IsoH;

		
				Draw(Global, olc::Pixel(200,0,0));
		
			}
		}
SetDrawTarget(nullptr);

		for (int j = 0; j <= 2; j++)
		{
		
			units.push_back(new_unit);
		}

	

		// Called once at the start, so create things here
		return true;
	}




	void local_to_global()
	{

	}


	bool OnUserUpdate(float fElapsedTime) override
	{


		Clear(olc::BLACK);

		SetPixelMode(olc::Pixel::ALPHA);
	
		//	SetPixelMode(olc::Pixel::ALPHA);

		SetDrawTarget(Xtile);

		double IsoW = 2;
		double IsoH = 1;

		Iso.x = 77 + 20;
		Iso.y = 1 + 10;
		SetDrawTarget(Xtile);

		for (double i = -20; i <= 20; i++)
		{
			for (double j = -20; j <= 20; j++)
			{

				Local.x = i;
				Local.y = j;

				Global.x = Iso.x + (Local.x - Local.y) * IsoW;
				Global.y = Iso.y + (Local.x + Local.y) * IsoH;


				//Draw(Local, olc::Pixel(olc::RED));

			}
		}
		SetDrawTarget(nullptr);



		/*
		* 
		GlobalX = IsoX + (LocalX - LocalY) * IsoW;
		GlobalY = IsoY + (LocalX + LocalY) * IsoH;


				Local.x = ((Global.y - Iso.y) / IsoH + (Global.x - Iso.x) / IsoW) / 2;
				Local.y = ((Global.y - Iso.y) / IsoH - (Global.x - Iso.x) / IsoW) / 2;
		*/
	
		

		Iso.x = 250;
		Iso.y = 250;
		
		Local.x = 0;
		Local.y = 0;



		double temp_x = (double)GetMouseX()-100;
		double temp_y = (double)GetMouseY()-(100-map.g);
	

		olc::vd2d mouse_local_space;

				// this code works 


	 	for (double i = -5; i <= 5; i++)
		{
			for (double j = -5; j <= 5; j++)
			{

				Local.x = i * 10;
				Local.y = j * 10;

				Global.x = Iso.x + (Local.x - Local.y) * IsoW;
				Global.y = Iso.y + (Local.x + Local.y) * IsoH;


						olc::Pixel p(255, 255, 255);
				

						if (
							int(mouse_local_space.x) >= int(Local.x) - 0
							&&
							int(mouse_local_space.x) <= int(Local.x) + 0
							&&
							int(mouse_local_space.y) >= int(Local.y) - 0
							&&
							int(mouse_local_space.y) <= int(Local.y) + 0
							&&
							int(mouse_local_space.y) >= -100
							&&
							int(mouse_local_space.y) <= 100
							&&
							int(mouse_local_space.x) >= -100
							&&
							int(mouse_local_space.x) <= 100
							)
						{	
							
				
							
						}
				
						
						DrawPartialSprite(Global.x , Global.y , Xtile, 77, 1, 39, 20);
					
			}

		}
	


		DrawSprite(1,10,Xtile);

		


		/*
		
					for (int i = -100; i < 100; i += 20)
					{
						for (int j = -100; j < 100; j += 20)
						{

							local_space.x = i;
							local_space.y = j;

							world_space.x = (local_space.x * proj_x.x) + (local_space.y * proj_y.x) + 100;
							world_space.y = (local_space.x * proj_x.y) + (local_space.y * proj_y.y) + 100;

					
			
								//	DrawPartialSprite(world_space.x, world_space.y, Xtile, 77, 1, 39, 20);
							
							
								  DrawPartialSprite(world_space.x, world_space.y, Xtile, 1, 1, 39, 20);
					

						}


					}
		*/


		/*
		for (int j = 0; j <= units.size()-1; j++)
		{

			getpos.x =  units[j].position.x + ScreenWidth() / 4;
			getpos.y =  units[j].position.x + ScreenHeight() / 4;

		//	DrawSprite(getpos, Xsprite);
		}
		*/

		SetPixelMode(olc::Pixel::NORMAL);
	
			
			
		return true;
	}

};






void mousepointtile(olc::vf2d input)
{
	
	    olc::vf2d output;

		olc::vf2d proj_x;
		olc::vf2d proj_y;

		proj_x.x = 32;
		proj_x.y = 17;

		proj_y.x = 32;
		proj_y.y = -17;

		output.x =  (input.x* proj_x.x) + (input.y * proj_y.x);

		output.y = (input.x * proj_x.y) + (input.y * proj_y.y);



}



int main()
{



	Example demo;
	if (demo.Construct(500, 500, 1, 1))
		demo.Start();

	return 0;
}




/*
#include "xpoint.h"
void createcurve(cpoint* A,cpoint* B,cpoint* C)
{


	xtest.cat(A, B, C); // determines the information innate to the curve

	for (int i = 0; i <= 90; i++)
	{

		xtest.update(); // actually moves a point according to curve


		cpoints.push_back(xtest.pos);

	}

}
*/


/*

					red = 0;
					blue = 0;
					green = 0;

					 k = 0;
					 g = 0;

					for (int q = -4; q <= 4; q++)
					{
						olc::Pixel r = Xtile->GetPixel(x * 20 + q , w);

						g = 0;
						if (
							blue >= double(r.b) + 1 && blue <= double(r.b) - 1
							)
						{
							blue += double(r.b);
							g = 1;
						};
						if (
							green >= double(r.b) + 1 && green <= double(r.b) - 1
							)
						{
							red += double(r.b);
							g = 1;
						};

						if (
							green >= double(r.b) + 1 && green <= double(r.b) - 1
							)
						{
							blue += double(r.b);
							g = 1;
						};

						k += g;

					}


					if (
						k >= 1
						)
					{

						p.b = blue / int(k);
						p.g = green / int(k);
						p.r = red / int(k);


						Xtile->SetPixel((x * 20 ), w, p);
					};

					 red = 0;
					 blue = 0;
					 green = 0;

					  k = 0;
					  g = 0;

					for (int q = -4; q <= 4; q++)
					{
						olc::Pixel r = Xtile->GetPixel(x * 20+w , q );

						g = 0;
						if (
							blue >= double(r.b)+1 && blue <= double(r.b) - 1
							)
						{
							blue += double(r.b);
							g = 1;
						};
						if (
							green >= double(r.b)+1 && green <= double(r.b) - 1
							)
						{
							red += double(r.b);
							g = 1;
						};

						if (
							green >= double(r.b)+1 && green <= double(r.b) - 1
							)
						{
							blue += double(r.b);
							g = 1;
						};

					k += g;

					}


					if (
						k >= 1
						)
					{

					p.b = blue / int(k);
					p.g = green / int(k);
					p.r = red /  int(k);

						Xtile->SetPixel((x * 20 - 1) + w, 2, p);

					};

					olc::Pixel u;
					u.b = 121;
					u.g = 121;
					u.r = 121;

					Xtile->SetPixel((x * 20 - 1) + w, 1, u);
					Xtile->SetPixel((x * 20 - 1) , w, u);
					Xtile->SetPixel((x * 20 - 1) + w, w, u);
					Xtile->SetPixel((x * 20 - 1) - w, w, u);


*/


void placeholder()
{




	/////////////////////


	/*


	olc::vd2d hex_x;

	hex_x.x = (i * cos((45.0) * PI / 180));
	hex_x.y = (i * sin((45.0) * PI / 180));

	olc::vd2d hex_y;

	hex_y.x =  (j * cos((135.0) * PI / 180));
	hex_y.y =  (j * sin((135.0) * PI / 180));

	olc::vd2d screen_x;

	screen_x.x = (i * mod_proj_x.x) * proj_x.x;
	screen_x.y = (i * mod_proj_x.y) * proj_x.y;

	olc::vd2d screen_y;

	screen_x.x = (i * mod_proj_y.x) * proj_y.x;
	screen_x.y = (i * mod_proj_y.x) * proj_y.y;

	double a = double(screen_x.x / proj_y.x) / mod_proj_x.x;
	double b = double(screen_x.y / proj_y.y) / mod_proj_x.y;

	double c = double(screen_y.x / proj_y.x) / mod_proj_y.x;
	double d = double(screen_y.y / proj_y.y) / mod_proj_y.y;

	*/



}