#pragma once

#include <vector>
#include "geo.h"
#include "drawpixel.h"
#include "circle.h"
#include "fillcircle.h"
#include "line.h"
#include "square.h"
#include "fillsquare.h"

using namespace std;

void geticon(vector<geo*> &v)
{
	

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 10; i++)
		{
			circle * c = new circle(100 + 100 * i, 200 + 200 * j, 50);
			v.push_back(c);
			
		}//circle

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
		{
			line *l = new line(75 + 100 * j, 200 + 200 * i, 125 + 100 * j, 200 + 200 * i);
			v.push_back(l);
			

		}//line

	for (int i = 0; i < 2; i++)
	{
		line *l = new line(200, 175 + 200 * i, 225, 200 + 200 * i);
		v.push_back(l);
	

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(200, 225 + 200 * i, 225, 200 + 200 * i);
		v.push_back(l);
	

	}//arrow
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(275, 200 + 200 * i, 300, 175 + 200 * i);
		v.push_back(l);
	

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(275, 200 + 200 * i, 300, 225 + 200 * i);
		v.push_back(l);
	

	}//arrow

	for (int i = 0; i < 2; i++)
	{
		square *s = new square(375, 175 + 200 * i, 425, 225 + 200 * i);
		v.push_back(s);
	

	}

	for (int i = 0; i < 2; i++)
	{
		fillsquare *f = new fillsquare(475, 175 + 200 * i, 525, 225 + 200 * i);
		v.push_back(f);
		

	}




	for (int j = 0; j < 2; j++)
	{
		fillcircle * i = new fillcircle(600, 200 + 200 * j, 25);
		v.push_back(i);
		
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			line *l = new line(700 + 100 * j, 175 + 200 * i, 700 + 100 * j, 225 + 200 * i);
			v.push_back(l);
			

		}//line

	for (int i = 0; i < 2; i++)
	{
		line *l = new line(675, 200 + 200 * i, 700, 225 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(700, 225 + 200 * i, 725, 200 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(775, 200 + 200 * i, 800, 175 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(800, 175 + 200 * i, 825, 200 + 200 * i);
		v.push_back(l);
		

	}


	for (int i = 0; i < 2; i++)
	{
		line *l = new line(875, 175 + 200 * i, 925, 225 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(875, 225 + 200 * i, 925, 175 + 200 * i);
		v.push_back(l);
		

	}
	for (int j = 0; j < 2; j++)
	{
		line *l = new line(975, 200 + 200 * j, 1025, 200 + 200 * j);
		v.push_back(l);
		
	}
	for (int j = 0; j < 2; j++)
	{
		line *l = new line(1000, 175 + 200 * j, 1000, 225 + 200 * j);
		v.push_back(l);
	}
}
