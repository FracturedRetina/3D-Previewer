#pragma once

class Camera {
	private:
		float xPos;
		float yPos;
		float zPos;
		float xRot;
		float yRot;
		float zRot;
		float lookUpMax;
		float lookDownMax;
	public:
		Camera(float x, float y, float z);
		float getXrot();
		float getYrot();
		float getZrot();
		void flyUp(double speed);
		void flyDown(double speed);
		void flyForward(float distance);
		void flyBackward(float distance);
		void moveForward(float distance);
		void moveBackward(float distance);
		void moveLeft(float distance);
		void moveRight(float distance);
		void rotateX(float amount);
		void rotateY(float amount);
		void rotateZ(float amount);
		void look();
		void checkInput();
};
