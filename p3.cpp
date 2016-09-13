#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>



double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;


	temp = min + (max - min)*temp;

	return temp;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.125;
	const double a = 0.5;
	const double b = 0.125;


	const double f = sqrt(pow(x-(0.5-(a*a-b*b)),2)+pow((y-0.5),2))+sqrt(pow(x - (0.5 + (a*a - b*b)), 2) + pow((y - 0.5), 2))- 2*a;

	if (f > 0.0)
		return false;
	else return true;
}

void main()
{
	FILE *of = fopen("ellipse.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 1.0);
		double y = getRandomNumber(0.0, 1.0);

		if (isInsideCircle(x, y) == true)
		{
			fprintf(of, "%f %f\n", x, y);

		}
	}
}