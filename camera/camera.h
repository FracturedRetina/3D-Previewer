#pragma once

class Camera {
	private:
		float distFromCent;
		int viewAng;
		float yPos;
	public:
		Camera(float distanceFromCenter, int viewAngle, float up);
		void checkInput();
		void look();
		float getX();
		float getY();
		float getZ();
};
