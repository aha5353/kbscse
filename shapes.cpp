#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"




const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

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
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;


		drawPixel(i, j, red, green, blue);

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
void drawCircle(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = sqrt(pow((i1 - i0) / 2, 2) - pow(i - (i1+i0)/2, 2)) + (j1+j0)/2;

		drawPixel(i, j, red, green, blue);
		drawPixel(i, (j0+j1)-j, red, green, blue);


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


		drawthicknerLine(0, 300, 100, 400, 1.0f, 0.0f, 0.0f);
		drawTriangle(0, 100, 100, 100 + 100 * sqrt(3), 200, 100, 1.0f, 0.0f, 0.0f);
		drawSquare(150, 300, 300, 450, 1.0f, 0.0f, 0.0f);
		drawfillSquare(350, 300, 500, 450, 1.0f, 0.0f, 0.0f);
		drawCircle(400, 100, 550, 250, 1.0f, 0.0f, 0.0f);
		drawPentagon(250, 100, 300, 100, 325, 100 + 25 * sqrt(3), 275, 100 + 50 * sqrt(3), 225, 100 + 25 * sqrt(3),1.0f,0.0f,0.0f);
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);



		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	glfwTerminate();
	return 0;
}