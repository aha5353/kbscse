#pragma once

#include <vector>
#include "geo.h"
#include "drawpixel.h"
#include "circle.h"
#include "fillcircle.h"
#include "line.h"
#include "squareblue.h"
#include "fillsquare.h"

using namespace std;

void geticon(vector<geo*> &v)
{
	

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 10; i++)
		{
			squareblue * c = new squareblue(50 + 110 * i, 150 + 200 * j, 150+110*i,250 + 200*j);
			v.push_back(c);
			
		}//circle

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
		{
			line *l = new line(75 + 110 * j, 200 + 200 * i, 125 + 110 * j, 200 + 200 * i);
			v.push_back(l);
			

		}//line

	for (int i = 0; i < 2; i++)
	{
		line *l = new line(210, 175 + 200 * i, 235, 200 + 200 * i);
		v.push_back(l);
	

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(210, 225 + 200 * i, 235, 200 + 200 * i);
		v.push_back(l);
	

	}//arrow
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(285, 200 + 200 * i, 310, 175 + 200 * i);
		v.push_back(l);
	

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(285, 200 + 200 * i, 310, 225 + 200 * i);
		v.push_back(l);
	

	}//arrow

	for (int i = 0; i < 2; i++)
	{
		squareblue *s = new squareblue(405, 175 + 200 * i, 455, 225 + 200 * i);
		v.push_back(s);
	

	}

	for (int i = 0; i < 2; i++)
	{
		fillsquare *f = new fillsquare(515, 175 + 200 * i, 565, 225 + 200 * i);
		v.push_back(f);
		

	}




	for (int j = 0; j < 2; j++)
	{
		fillcircle * i = new fillcircle(650, 200 + 200 * j, 25);
		v.push_back(i);
		
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			line *l = new line(760 + 110 * j, 175 + 200 * i, 760 + 110 * j, 225 + 200 * i);
			v.push_back(l);
			

		}//line

	for (int i = 0; i < 2; i++)
	{
		line *l = new line(735, 200 + 200 * i, 760, 225 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(760, 225 + 200 * i, 785, 200 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(845, 200 + 200 * i, 870, 175 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(870, 175 + 200 * i, 895, 200 + 200 * i);
		v.push_back(l);
		

	}


	for (int i = 0; i < 2; i++)
	{
		line *l = new line(950, 175 + 200 * i, 1000, 225 + 200 * i);
		v.push_back(l);
		

	}
	for (int i = 0; i < 2; i++)
	{
		line *l = new line(950, 225 + 200 * i, 1000, 175 + 200 * i);
		v.push_back(l);
		

	}
	for (int j = 0; j < 2; j++)
	{
		line *l = new line(1065, 200 + 200 * j, 1115, 200 + 200 * j);
		v.push_back(l);
		
	}
	for (int j = 0; j < 2; j++)
	{
		line *l = new line(1090, 175 + 200 * j, 1090, 225 + 200 * j);
		v.push_back(l);
	}
}
