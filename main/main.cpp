#include <iostream>
#include <GL/glfw.h>
#include "util.h"
#include "../models/modelLoader.h"
#include "../models/model.h"
#include "../camera/camera.h"

int width = 640, height = 480;
void drawGrid(int size);
void render();
int mainLoop();
char* arg;

int main(int argc, char* argv[]) {
	//If no file name entered
	if (argc <= 1) {
		std::cout << "No file supplied.\n\n\n";
		system("pause");
		return 1;
	}

	arg = argv[1];
	mainLoop();


	return 0;
}

void init() {
	glfwInit();
	if (!glfwOpenWindow(width, height, 0, 0, 0, 0, 0, 0, GLFW_WINDOW)) {
		glfwTerminate();
		return;
	}

	glfwSetWindowTitle("GLFW");
	setRenderMode(RM_LIT);
}

int mainLoop() {
	bool running = true;
	Camera cam(15, 0, 1);

	init();

	while (running) {

		glfwGetWindowSize(&width, &height);
		height = height > 0 ? height : 1;

		glViewport(0, 0, width, height);

		//Clear last frame
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65.0f, (GLfloat) width / (GLfloat) height, 1.0f, 250.0f);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_DEPTH_TEST);

		//Draw things
		render();
		//Camera rotation
		cam.checkInput();
		cam.look();

		glfwSwapBuffers();

		//Exit if ESC was pressed or window was closed
		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
	}


	glfwTerminate();
	return 0;
}

void render() {
	Model model = loadObj(arg);

	drawGrid(30);
	if (glfwGetKey('Z')) {
		switch (getRenderMode()) {
			case RM_LIT:
				setRenderMode(RM_WIREFRAME);
				break;
			case RM_WIREFRAME:
				setRenderMode(RM_LIT);
				break;
		}
	}


	model.render();
}

void drawGrid(int size) {

	setRenderMode(RM_WIREFRAME);

	glBegin(GL_LINES);
		glColor3f(0.5f, 0.5f, 0.5f);

		for (int i = -size; i < size; i++) {
			//XZ Grid
			if (i == 0) {
				glColor3f(0.0f, 1.0f, 0.0f);
			}
			glVertex3i(size, 0, i);
			glVertex3i(-size, 0,i);
			//ZX Grid
			if (i == 0) {
				glColor3f(1.0f, 0.0f, 0.0f);
			}
			glVertex3i(i, 0, size);
			glVertex3i(i, 0, -size);

			//Y Axis
			if (i == 0) {
				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3i(0, size, 0);
				glVertex3i(0, -size, 0);
			}


			if (i == 0) {
				glColor3f(0.5f, 0.5f, 0.5f);
			}
		}
	glEnd();
	setRenderMode(RM_LIT);
}
