#include <iostream>
#include <math.h>
#include <GL/glfw.h>
#include "camera.h"

Camera::Camera(float distanceFromCenter, int viewAngle, float up) {
	distFromCent = distanceFromCenter;
	viewAng = viewAngle;
	yPos = up;
}

void Camera::checkInput() {
	if (glfwGetKey(GLFW_KEY_UP)) {
		distFromCent--;
	}
	if (glfwGetKey(GLFW_KEY_DOWN)) {
		distFromCent++;
	}
	if (glfwGetKey(GLFW_KEY_LEFT)) {
		viewAng++;
	}
	if (glfwGetKey(GLFW_KEY_RIGHT)) {
		viewAng--;
	}
	if (glfwGetKey(GLFW_KEY_SPACE)) {
		yPos++;
	}
	if (glfwGetKey(GLFW_KEY_LSHIFT)) {
		yPos--;
	}
}

void Camera::look() {
	//Clear existing transformations
	glLoadIdentity();

	gluLookAt(
		getX(), getY(), getZ(),	//Camera XYZ
		0,		0,		0,		//Look at
		0,		1,		0		//Up vector
	);
	glRotatef(viewAng, 0.f, 1.f, 0.f);
//	std::cout << "Camera at: " << getX() << ", " << getY() << ", " << getZ() << std::endl;
}

float Camera::getX() {
	return cos(viewAng * (M_PI / 180)) * distFromCent;
}

float Camera::getY() {
	return yPos;
}

float Camera::getZ() {
	return sin(viewAng * (M_PI / 180)) * distFromCent;
}
