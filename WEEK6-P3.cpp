#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

const int width = 1200;
const int height = 600;

float* pixels = new float[width*height * 3];


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

using namespace std;

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
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
	/*const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;
	drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);*/

	//TODO: try moving object
}


class Box
{
public:


	void draw()
	{
		int start_x = 200;
		int start_y = 200;
		int end_x = 300;
		int end_y = 300;
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
	}

	 
};

class Circle
{
public:

	void draw()
	{
		int xpos = 500;
		int ypos = 500;
		int radius = 100;
		for (float i = xpos - radius; i <= xpos + radius; i = i + 0.01)
		{
			const int j = sqrt(pow((xpos + 2 * radius - xpos) / 2, 2) - pow(i - (2 * xpos) / 2, 2)) + (2 * ypos) / 2;
			drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			drawPixel(i, (2 * ypos) - j, 1.0f, 0.0f, 0.0f);
		}

	}
};


class GeometricObjectInterface
{
public:

	virtual void draw()
	{
	}
};

template<class geo>
class Geometricobject :public GeometricObjectInterface
{
public:
	void draw()
	{
		geo drawgeo;
		drawgeo.draw();
	}
};

// And implement an templatized GeometricObject class.

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

		//for (auto itr : object_list)
		//{
		//	itr->drawfor(int i:int object_list)
		//}

		vector<GeometricObjectInterface*> obj_list;

		obj_list.push_back(new Geometricobject<Box>);
		obj_list.push_back(new Geometricobject<Circle>);

		for (auto itr : obj_list)
		{
			itr->draw();
		}


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