#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <array>

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#else 
#include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>

#include <geometry/point.hpp>

using namespace std;
using namespace geometry;

class Window
{
	GLFWwindow *window = nullptr;

	std::string title;
	std::vector<Point<3, GLfloat>> points;

	void genPoints(int n)
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::random_device rd;
		std::uniform_real_distribution<double> dist(-2.,2.);
		std::array<GLfloat, 3> V;

		for (int i = 0; i < n; ++i)
		{
			V[0] = dist(generator);
			V[1] = dist(generator);

			V[2] = V[0] * V[0] + V[1] * V[1];

			points.emplace_back(V);
		}
	}

public:
	Window(int width, int height, int n, std::string title)
	{
		glfwInit();

		glfwWindowHint(GLFW_SAMPLES, 4);

		window = glfwCreateWindow( width, height, title.c_str(), NULL, NULL);

		glfwMakeContextCurrent( window );
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glDisable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		
		genPoints(n);
	};

	void display()
	{
		static float alpha = 30;

		while (!glfwWindowShouldClose(window))
		{
			// What are this variables? width and height?
			GLint w,h;

			glfwGetWindowSize(window, &w, &h);
			glViewport(0, 0, w, h);
		
			glClearColor(.8, .3, 0.75, 1.0);
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION_MATRIX);
			glLoadIdentity();

			gluPerspective(45, (double) w / (double) h, 0.1, 100);

			glMatrixMode(GL_MODELVIEW_MATRIX);
			glTranslatef(0, 0, -5);
			glRotatef(alpha, 2, -4, -1);
			
			alpha += 1;

			glBegin(GL_POINTS);

			for (auto &p : points)
			{
				p.render();
			}

			glEnd();
			
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
};

#endif
