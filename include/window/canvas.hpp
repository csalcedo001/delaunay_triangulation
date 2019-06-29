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
    int width = 600;
    int height = 600;
    string title = "Window";
public:
	Window()
	{
		glfwInit();

		glfwWindowHint(GLFW_SAMPLES, 4);

		window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);

		glfwMakeContextCurrent( window );
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glDisable(GL_CULL_FACE);
		glCullFace(GL_BACK);
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
			
			alpha += 1;

			glBegin(GL_LINES);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 1, 0);

            glVertex3f(0, 0, 0);
            glVertex3f(1, 0, 0);

            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, 1);

            // glBegin(GL_POINTS);
			// for (auto &p : points)
			// {
			// 	p.render();
			// }

			glEnd();
			
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
};

#endif
