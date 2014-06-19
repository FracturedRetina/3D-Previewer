#include <iostream>
#include <string>
#include <sstream>
#include <GL/glfw.h>
#include "util.h"

int renderMode;

void setRenderMode(int rm) {
	switch (rm) {
		case RM_LIT:{
			GLfloat light_color[]	 = {1.5, 1.5, 1.5, 0.0};
			GLfloat light_position[] = {3.0, 3.0, 3.0, 0.0};

			glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		}
		case RM_WIREFRAME:{
			glDisable(GL_LIGHT0);
			glDisable(GL_LIGHTING);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
		}
		default: std::cout << "Invalid render mode.";
			break;
	}
	renderMode = rm;
}

int getRenderMode() {
	return renderMode;
}

std::vector<std::string> &split(const std::string &str, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(str);
	std::string item;
	while (std::getline(ss, item, delim)) {
		if (item != "") {
			elems.push_back(item);
		}
	}
	return elems;
}


std::vector<std::string> split(const std::string &str, char delim) {
	std::vector<std::string> elems;
	split(str, delim, elems);
	return elems;
}
