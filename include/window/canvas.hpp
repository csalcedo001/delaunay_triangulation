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
#include <geometry/line.hpp>

using namespace std;
using namespace geometry;

GLfloat zoom = 5.f;
GLfloat alpha = 210.f;
GLfloat _beta = -70.f;

double cursorX;
double cursorY;

void scroll_callback(GLFWwindow* window, double x, double y)
{
    zoom += (float) y / 4.f;
    if (zoom < 0)
        zoom = 0;
}

void cursor_position_callback(GLFWwindow* window, double x, double y)
{
    if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
    {
        alpha += (GLfloat) (x - cursorX) / 10.f;
        _beta += (GLfloat) (y - cursorY) / 10.f;

        cursorX = x;
        cursorY = y;
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button != GLFW_MOUSE_BUTTON_LEFT)
        return;

    if (action == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwGetCursorPos(window, &cursorX, &cursorY);
    }
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

template <typename Geometry_>
class Window
{
	GLFWwindow *window = nullptr;
    int width = 640;
    int height = 640;
	int mode_ = 0;
    string title = "Window";

	vector<Geometry_*> geometries_;
public:
	Window(int mode, vector<Geometry_*> geometries)
	{
		this->mode_ = mode;
		this->geometries_ = geometries;

		glfwInit();

		glfwWindowHint(GLFW_SAMPLES, 4);

		window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);

		glfwMakeContextCurrent( window );
		
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_DEPTH_CLAMP);

		glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
		glPointSize(5);
		
		glDepthFunc(GL_LEQUAL);
		glDisable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		glfwSetMouseButtonCallback(window, mouse_button_callback);
		glfwSetCursorPosCallback(window, cursor_position_callback);
		glfwSetScrollCallback(window, scroll_callback);
	};

	void display()
	{
		while (!glfwWindowShouldClose(window))
		{
			// What are this variables? width and height?
			GLint w,h;

			glfwGetWindowSize(window, &w, &h);
			glViewport(0, 0, w, h);
		
			glClearColor(.8, .3, 0.75, 1.0);
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// glMatrixMode(GL_PROJECTION_MATRIX);
			glLoadIdentity();

			gluPerspective(45, (double) w / (double) h, 0.1, 100);

			glMatrixMode(GL_MODELVIEW_MATRIX);

			glTranslatef(0, 0, -zoom);
			glRotatef(_beta, 1.0, 0.0, 0.0);
			glRotatef(alpha, 0.0, 0.0, 1.0);
			
			if (this->mode_ == 1) 
			{
				glBegin(GL_LINES);
				for (auto &it : this->geometries_)
				{
					it->render();
				}
				glEnd();
			} else if (this->mode_ == 2)
			{
				glBegin(GL_POINTS);
				for (auto &it : this->geometries_)
				{
					it->render();
				}
				glEnd();
			}
			
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
};

#endif
