#pragma once
#include "geo.h"
#include "drawpixel.h"



class line : public geo
{
public:
	void draw()
	{
		if (start_x != end_x)
		{
			for (int i = start_x; i <= end_x; i++)
			{

				const int j = (end_y - start_y)*(i - start_x) / (end_x - start_x) + start_y;


				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			}
		}
		else if (start_x == end_x)
		{
			for (int i = start_y; i <= end_y; i++)
			{
				drawPixel(start_x, i, 1.0f, 0.0f, 0.0f);
			}
		}
	}

	line(int stx, int sty, int ex, int ey)
	{
		start_x = stx;
		start_y = sty;
		end_x = ex;
		end_y = ey;

	}

	void setstx(int sx)
	{
		start_x = sx;
	}
	void setsty(int sy)
	{
		start_y = sy;
	}
	void setex(int ex)
	{
		end_x = ex;
	}
	void setey(int ey)
	{
		end_y = ey;
	}

private:
	int start_x;
	int start_y;
	int end_x;
	int end_y;
};
