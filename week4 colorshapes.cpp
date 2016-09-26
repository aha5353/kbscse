#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <windows.h>
#include <iostream>




const int width = 800;
const int height = 500;

float* pixels = new float[width*height * 3];

double xpos, ypos;

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	int box[1000];
	int k = 0;
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;


		drawPixel(i, j, red, green, blue);
		box[k] = j;
		k++;
		if (box[k - 1] != box[k])
		{
			drawPixel(i, j - 1, red, green, blue);
		}

	}
}

void drawthicknerLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
		drawPixel(i - 1, j, red, green, blue);
		drawPixel(i, j - 1, red, green, blue);

	}
}

void drawTriangle(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);
	drawLine(i1, j1, i2, j2, 1.0f, 0.0f, 0.0f);
	drawLine(i0, j0, i2, j2, 1.0f, 0.0f, 0.0f);

}
//void drawCircle(const int& x1, const int& y1, const int& r, const float& red, const float& green, const float& blue)
//{
//	for (int i = x1 - r; i <= x1 + r; i++)
//		for (int j = y1 - r; j <= y1 + r; j++)
//		{
//			const int f = pow(i - x1, 2) + pow(j - y1, 2) - r*r;
//			if (f == 0)
//			{
//				drawPixel(i, j, red, green, blue);
//			}
//			
//		}
//	
//}

void drawCircle(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (float i = i0; i <= i1; i=i+0.01)
	{
		const int j = sqrt(pow((i1 - i0) / 2, 2) - pow(i - (i1 + i0) / 2, 2)) + (j1 + j0) / 2;

		drawPixel(i, j, red, green, blue);
		drawPixel(i-0.5, j, red, green, blue);
		drawPixel(i, j-0.5, red, green, blue);
		drawPixel(i, (j0 + j1) - j, red, green, blue);
		drawPixel(i-0.5, (j0 + j1) - j, red, green, blue);
		drawPixel(i, (j0 + j1) - j-0.5, red, green, blue);

	}//drawcircle
	const int k = (xpos - (i0 + i1) / 2)*(xpos - (i0 + i1) / 2) + (ypos - (j0 + j1) / 2)*(ypos - (j0 + j1) / 2) - ((i1 - i0) / 2)*((i1 - i0) / 2);
	if (k <= 0)
	{
		for (float i = i0; i <= i1; i = i + 0.01)
		{
			const int j = sqrt(pow((i1 - i0) / 2, 2) - pow(i - (i1 + i0) / 2, 2)) + (j1 + j0) / 2;

			drawPixel(i, j, 0.0f, 0.0f, 1.0f);
			drawPixel(i - 0.5, j, 0.0f, 0.0f, 1.0f);
			drawPixel(i, j - 0.5, 0.0f, 0.0f, 1.0f);
			drawPixel(i, (j0 + j1) - j, 0.0f, 0.0f, 1.0f);
			drawPixel(i - 0.5, (j0 + j1) - j, 0.0f, 0.0f, 1.0f);
			drawPixel(i, (j0 + j1) - j - 0.5, 0.0f, 0.0f, 1.0f);


		}
	}//change color
}

void drawThickCircle(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (float i = i0; i <= i1; i = i + 0.01)
	{
		const int j = sqrt(pow((i1 - i0) / 2, 2) - pow(i - (i1 + i0) / 2, 2)) + (j1 + j0) / 2;
			drawPixel(i, j, red, green, blue);
			drawPixel(i, (j0 + j1) - j, red, green, blue);
			drawPixel(i , j, red, green, blue);
			drawPixel(i, (j0 + j1) - j , red, green, blue);
		drawPixel(i - 0.5, j, red, green, blue);
		drawPixel(i, j - 0.5, red, green, blue);
		drawPixel(i - 0.5, (j0 + j1) - j, red, green, blue);
		drawPixel(i, (j0 + j1) - j - 0.5, red, green, blue);
		drawPixel(i - 1, j, red, green, blue);
		drawPixel(i, j - 1, red, green, blue);
		drawPixel(i - 1, (j0 + j1) - j, red, green, blue);
		drawPixel(i, (j0 + j1) - j - 1, red, green, blue);
		drawPixel(i + 0.5, j, 0.0f, 0.0f, 1.0f);
		drawPixel(i, j + 0.5, 0.0f, 0.0f, 1.0f);
		drawPixel(i + 0.5, (j0 + j1) - j, red, green, blue);
		drawPixel(i, (j0 + j1) - j + 0.5, red, green, blue);
		drawPixel(i + 1, j, red, green, blue);
		drawPixel(i, j + 1, red, green, blue);
		drawPixel(i + 1, (j0 + j1) - j, red, green, blue);
		drawPixel(i, (j0 + j1) - j + 1, red, green, blue);

	}
}
void drawSquare(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		if (i == i0 || i == i1)
		{
			for (int j = j0; j <= j1; j++)
			{
				drawPixel(i, j, red, green, blue);
			}
		}
		drawPixel(i, j0, red, green, blue);
		drawPixel(i, j1, red, green, blue);
	}
	
}

void drawPentagon(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3,const int& i4,const int& j4, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i1, j1, i2, j2, red, green, blue);
	drawLine(i3, j3, i2, j2, red, green, blue);
	drawLine(i4, j4, i3, j3, red, green, blue);
	drawLine(i4, j4, i0, j0, red, green, blue);

}


void drawfillSquare(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
		for (int j = j0; j <= j1; j++)
		{
			drawPixel(i, j, red, green, blue);
		}

}
void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}
	
	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;
	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);

	//TODO: try moving object
}



int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	
	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);



		std::fill_n(pixels, width*height * 3, 1.0f);
		for (int i = 0; i <= 4; i++)
			for (int j = 0; j <= 1; j++)
			{
				drawCircle(50 + 150*i, 100 + 200*j, 150 + 150*i, 200 + 200*j, 1.0f, 0.0f, 0.0f);
			}
		
		
			
			drawLine(70, 150, 130, 150, 1.0f, 0.0f, 0.0f);
			drawLine(110, 165, 130, 150, 1.0f, 0.0f, 0.0f);
			drawLine(110, 135, 130, 150, 1.0f, 0.0f, 0.0f);//picture1

			drawLine(220, 125, 250, 175, 1.0f, 0.0f, 0.0f);
			drawLine(250, 175, 280, 125, 1.0f, 0.0f, 0.0f);
			drawLine(234, 150, 266, 150, 1.0f, 0.0f, 0.0f);//picture2

			for (int i = 0; i <= 50; i++)
			{
				drawPixel(400, 125 + i, 1.0f, 0.0f, 0.0f);
			}//picture3
			drawLine(525, 150, 575, 150, 1.0f, 0.0f, 0.0f);
			drawLine(525, 150, 540, 165, 1.0f, 0.0f, 0.0f);
			drawLine(525, 150, 540, 135, 1.0f, 0.0f, 0.0f);//picture4

			for (int i = 0; i <= 50; i++)
			{
				drawPixel(700, 125 + i, 1.0f, 0.0f, 0.0f);
			}
			drawLine(685, 160, 700, 175, 1.0f, 0.0f, 0.0f);
			drawLine(700, 175, 715, 160, 1.0f, 0.0f, 0.0f);//picture5

			drawLine(70, 330, 130, 370, 1.0f, 0.0f, 0.0f);//picture6

			drawThickCircle(234, 334, 266, 366, 1.0f, 0.0f, 0.0f);//picture7

			drawSquare(375, 325, 425, 375, 1.0f, 0.0f, 0.0f);//picture8

			drawLine(525, 325, 575, 375, 1.0f, 0.0f, 0.0f);
			drawLine(525, 375, 575, 325, 1.0f, 0.0f, 0.0f);//picture9

			for (int i = 0; i <= 50; i++)
			{
				drawPixel(700, 325 + i, 1.0f, 0.0f, 0.0f);
			}
			drawLine(685, 340, 700, 325, 1.0f, 0.0f, 0.0f);
			drawLine(700, 325, 715, 340, 1.0f, 0.0f, 0.0f);//picture10
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		


		glfwGetCursorPos(window, &xpos, &ypos);
		ypos = height - ypos;

		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	glfwTerminate();
	return 0;
}