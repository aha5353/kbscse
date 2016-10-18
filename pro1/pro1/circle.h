#pragma once
#include "geo.h"
#include <math.h>
#include "drawpixel.h"


double xx, yy;
class circle : public geo
{
public:
	void draw()
	{

		for (float i = xpos - radius; i <= xpos + radius; i = i + 0.01)
		{
			const int j = sqrt(pow((xpos + 2 * radius - xpos) / 2, 2) - pow(i - (2 * xpos) / 2, 2)) + (2 * ypos) / 2;
			drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			drawPixel(i, (2 * ypos) - j, 1.0f, 0.0f, 0.0f);
		}

		const int k = (xx - (2 * xpos) / 2)*(xx - (2 * xpos) / 2) + (yy - (2 * ypos) / 2)*(yy - (2 * ypos) / 2) - ((2 * radius) / 2)*((2 * radius) / 2);
		if (k <= 0)
		{
			for (float i = xpos - radius; i <= xpos + radius; i = i + 0.01)
			{
				const int j = sqrt(pow((2 * radius) / 2, 2) - pow(i - (2 * xpos) / 2, 2)) + (2 * ypos) / 2;

				drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				drawPixel(i, (2 * ypos) - j, 0.0f, 0.0f, 1.0f);



			}
		}
	}

	void setr(int r)
	{
		radius = r;
	}

	circle(int x, int y, int r)
	{
		xpos = x;
		ypos = y;
		radius = r;

	}

private:
	int radius;


};
