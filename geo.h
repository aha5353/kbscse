#pragma once


class geo
{
public:

	virtual void draw()
	{

	}

	void setx(int x)
	{
		xpos = x;
	}
	void sety(int y)
	{
		ypos = y;
	}


protected:
	int xpos;
	int ypos;
};