#pragma once
#include"geo.h"
#include"drawpixel.h"

double xx, yy;

class squareblue :public geo
{
public:
	void draw()
	{
		for (int i = start_x; i <= end_x; i++)
		{
			if (i == start_x || i == end_x)
			{
				for (int j = start_y; j <= end_y; j++)
				{
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
				}
			}
			drawPixel(i, start_y, 1.0f, 0.0f, 0.0f);
			drawPixel(i, end_y, 1.0f, 0.0f, 0.0f);
		}
		if (xx >= start_x&&xx <= end_x&&yy >= start_y&&yy <= end_y)
		{
			for (int i = start_x; i <= end_x; i++)
			{
				if (i == start_x || i == end_x)
				{
					for (int j = start_y; j <= end_y; j++)
					{
						drawPixel(i, j, 0.0f, 0.0f, 1.0f);
					}
				}
				drawPixel(i, start_y, 0.0f, 0.0f, 1.0f);
				drawPixel(i, end_y, 0.0f, 0.0f, 1.0f);
			}
		}//change color
	}

	squareblue(int stx, int sty, int ex, int ey)
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


