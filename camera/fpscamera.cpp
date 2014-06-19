//#include <stdlib.h>
//#include <math.h>
//#include <GL/glfw.h>
//#include "camera.h"
//
//const double TO_RADS = M_PI / 180;
//
//Camera::Camera(float x, float y, float z) {
//	xPos = x;
//	yPos = y;
//	zPos = z;
//	xRot = 0;
//	yRot = 0;
//	zRot = 0;
//	lookUpMax = 90;
//	lookDownMax = 90;
//}
//
//float Camera::getXrot(){
//	return xRot;
//}
//float Camera::getZrot(){
//	return zRot;
//}
//
//
//void Camera::flyUp(double speed) {
//	zPos -= speed;
//}
//void Camera::flyDown(double speed) {
//	zPos += speed;
//}
//
//void Camera::flyForward(float distance) {
//	xPos -= distance * sin(TO_RADS * (zRot));
//	yPos += distance * cos(TO_RADS * (xRot - 90));
//	zPos += distance * cos(TO_RADS * (zRot));
//}
//void Camera::flyBackward(float distance) {
//	xPos += distance * sin(TO_RADS * (zRot));
//	yPos -= distance * cos(TO_RADS * (xRot - 90));
//	zPos -= distance * cos(TO_RADS * (zRot));
//}
//
//void Camera::moveForward(float distance) {
//	xPos -= distance * sin(TO_RADS * (zRot));
//	yPos += distance * cos(TO_RADS * (zRot));
//}
//void Camera::moveBackward(float distance) {
//	xPos += distance * sin(TO_RADS * (zRot));
//	yPos -= distance * cos(TO_RADS * (zRot));
//}
//void Camera::moveLeft(float distance) {
//	xPos -= distance * sin(TO_RADS * (zRot - 90));
//	yPos += distance * cos(TO_RADS * (zRot - 90));
//}
//void Camera::moveRight(float distance) {
//	xPos -= distance * sin(TO_RADS * (zRot + 90));
//	yPos += distance * cos(TO_RADS * (zRot + 90));
//}
//
//void Camera::rotateX(float amount) {
//	//Look up limit
//	//If look up
//	if (amount < 0) {
//		//If already looking down
//		if (xRot < 360 - lookUpMax) {
//			xRot += amount;
//		//If already looking up
//		} else if (xRot > 360 - lookUpMax) {
//			if (xRot + amount < 360 - lookUpMax) {
//				xRot = 360 - lookUpMax;
//			} else {
//				xRot += amount;
//			}
//		}
//	//If looking down
//	} else if (amount > 0) {
//		//If already looking down
//		if (xRot < lookDownMax) {
//			if (xRot + amount > lookDownMax) {
//				xRot = lookDownMax;
//			} else {
//				xRot += amount;
//			}
//		//If already looking up
//		} else if (xRot > lookDownMax) {
//			xRot += amount;
//		}
//	}
//
//
//	//Keep rotation within 360°
//	if (xRot > 360) {
//		xRot = (int) xRot % 360;
//	} else if (xRot < 0) {
//		while (xRot < 0) {
//			xRot = 360 - abs(xRot);
//		}
//	}
//}
//
//void Camera::rotateZ(float amount) {
//	zRot += amount;
//	if (zRot > 360) {
//		zRot = (int) zRot % 360;
//	} else if (zRot < 0) {
//		while (zRot < 0) {
//			zRot = 360 - abs(zRot);
//		}
//	}
//}
//
//void Camera::look() {
//	glRotatef(xRot, 1, 0, 0);
//	glRotatef(yRot, 0, 1, 0);
//	glRotatef(zRot, 0, 0, 1);
//	glTranslatef(xPos, yPos, zPos);
//}
//
//void Camera::checkInput() {
//	if (glfwGetKey('W')) {
//		moveForward(0.05f);
//	}
//	if (glfwGetKey('S')) {
//		moveBackward(0.05f);
//	}
//	if (glfwGetKey('A')) {
//		moveLeft(0.05f);
//	}
//	if (glfwGetKey('D')) {
//		moveRight(0.05f);
//	}
//
//	if (glfwGetKey(GLFW_KEY_SPACE)) {
//		flyUp(0.05f);
//	}
//	if (glfwGetKey(GLFW_KEY_LSHIFT)) {
//		flyDown(0.05f);
//	}
//
//	//Lookaround
//	if (glfwGetKey(GLFW_KEY_UP)) {
//		rotateX(-1);
//	}
//	if (glfwGetKey(GLFW_KEY_DOWN)) {
//		rotateX(1);
//	}
//	if (glfwGetKey(GLFW_KEY_LEFT)) {
//		rotateZ(-1);
//	}
//	if (glfwGetKey(GLFW_KEY_RIGHT)) {
//		rotateZ(1);
//	}
//}
