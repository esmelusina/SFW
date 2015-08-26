

#include "sfwdraw.h"
#include "GLFW\glfw3.h"
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cctype>

namespace sfw
{

	static float lt;
	static float dt;
	static GLFWwindow *window;

	void initContext(int width, int height, const char *title)
	{
		lt = dt = 0;
		if (!glfwInit())
			exit(EXIT_FAILURE);
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);

		glViewport(0, 0, width, height);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-0.5, (width - 1) + 0.5, (height - 1) + 0.5, -0.5, 0.0, 1.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glColor3f(1, 1, 1);
	}

	bool stepContext()
	{
		float current = glfwGetTime();
		dt = current - lt;
		lt = current;
		
		glfwSwapBuffers(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		return !glfwWindowShouldClose(window);
	}

	void termContext()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	float getDeltaTime() { return dt; }

	bool getKey(char key) { return glfwGetKey(window, toupper(key)); }

	void drawLine(float x1, float y1, float x2, float y2)
	{
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}

	void drawCircle(float x, float y, float r)
	{
		glBegin(GL_LINE_LOOP);
		const float step = PI / 12;

		for (float i = 0; i <= 2 * PI; i += step)
			glVertex2f(x + cos(i) * r, y + sin(i) * r);

		glEnd();
	}

}