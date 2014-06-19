#include <stdlib.h>
#include <math.h>
#include <GL/glfw.h>
#include "camera.h"

const double TO_RADS = M_PI / 180;

Camera::Camera(float x, float y, float z) {
	xPos = x;
	zPos = y;
	yPos = z;
	xRot = 0;
	zRot = 0;
	yRot = 0;
	lookUpMax = 90;
	lookDownMax = 90;
}

float Camera::getXrot() {
	return xRot;
}
float Camera::getYrot() {
	return yRot;
}
float Camera::getZrot() {
	return zRot;
}


void Camera::flyUp(double speed) {
	yPos -= speed;
}
void Camera::flyDown(double speed) {
	yPos += speed;
}

void Camera::flyForward(float distance) {
	xPos -= distance * sin(TO_RADS * (yRot));
	yPos += distance * cos(TO_RADS * (xRot - 90));
	zPos += distance * cos(TO_RADS * (yRot));
}
void Camera::flyBackward(float distance) {
	xPos += distance * sin(TO_RADS * (yRot));
	yPos -= distance * cos(TO_RADS * (xRot - 90));
	zPos -= distance * cos(TO_RADS * (yRot));
}

void Camera::moveForward(float distance) {
	xPos -= distance * sin(TO_RADS * (yRot));
	zPos += distance * cos(TO_RADS * (yRot));
}
void Camera::moveBackward(float distance) {
	xPos += distance * sin(TO_RADS * (yRot));
	zPos -= distance * cos(TO_RADS * (yRot));
}
void Camera::moveLeft(float distance) {
	xPos -= distance * sin(TO_RADS * (yRot - 90));
	zPos += distance * cos(TO_RADS * (yRot - 90));
}
void Camera::moveRight(float distance) {
	xPos -= distance * sin(TO_RADS * (yRot + 90));
	zPos += distance * cos(TO_RADS * (yRot + 90));
}

void Camera::rotateX(float amount) {
	//Look up limit
	//If look up
	if (amount < 0) {
		// If already looking down
		if (xRot < 360 - lookUpMax) {
			xRot += amount;
		//If already looking up
		} else if (xRot > 360 - lookUpMax) {
			if (xRot + amount < 360 - lookUpMax) {
				xRot = 360 - lookUpMax;
			} else {
				xRot += amount;
			}
		}
	//If looking down
	} else if (amount > 0) {
		// If already looking down
		if (xRot < lookDownMax) {
			if (xRot + amount > lookDownMax) {
				xRot = lookDownMax;
			} else {
				xRot += amount;
			}
		//If already looking up
		} else if (xRot > lookDownMax) {
			xRot += amount;
		}
	}


	//Keep rotation within 360°
	if (xRot > 360) {
		xRot = (int) xRot % 360;
	} else if (xRot < 0) {
		while (xRot < 0) {
			xRot = 360 - abs(xRot);
		}
	}
}
void Camera::rotateY(float amount) {
	yRot += amount;
	if (yRot > 360) {
		yRot = (int) yRot % 360;
	} else if (yRot < 0) {
		while (yRot < 0) {
			yRot = 360 - abs(yRot);
		}
	}
}

void Camera::look() {
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glTranslatef(xPos, yPos, zPos);
}

void Camera::checkInput() {
	if (glfwGetKey('W')) {
		moveForward(0.05f);
	}
	if (glfwGetKey('S')) {
		moveBackward(0.05f);
	}
	if (glfwGetKey('A')) {
		moveLeft(0.05f);
	}
	if (glfwGetKey('D')) {
		moveRight(0.05f);
	}

	if (glfwGetKey(GLFW_KEY_SPACE)) {
		flyUp(0.05f);
	}
	if (glfwGetKey(GLFW_KEY_LSHIFT)) {
		flyDown(0.05f);
	}

	//Lookaround
	if (glfwGetKey(GLFW_KEY_UP)) {
		rotateX(-1);
	}
	if (glfwGetKey(GLFW_KEY_DOWN)) {
		rotateX(1);
	}
	if (glfwGetKey(GLFW_KEY_LEFT)) {
		rotateY(-1);
	}
	if (glfwGetKey(GLFW_KEY_RIGHT)) {
		rotateY(1);
	}
}
