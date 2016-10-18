#pragma once
#include "geo.h"
#include"drawpixel.h"
#include "math.h"


class fillcircle : public geo
{
public:
	void draw()
	{

		for (float i = xpos - radius; i <= xpos + radius; i = i++)
			for (float j = ypos - radius; j <= ypos + radius; j = j++)
			{
				int f = pow((i - xpos), 2) + pow((j - ypos), 2) - radius*radius;
				if (f < 0)
				{
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
					drawPixel(i, (2 * ypos) - j, 1.0f, 0.0f, 0.0f);
				}
			}
	}

	void setr(int r)
	{
		radius = r;
	}

	fillcircle(int x, int y, int r)
	{
		xpos = x;
		ypos = y;
		radius = r;

	}

private:
	int radius;


};
