#pragma once
#include <vector>
#include <GL/glfw.h>

struct Point {
	float x, y, z;

	Point() {
		x = 0;
		y = 0;
		z = 0;
	}

	operator float*() {
		float arr[3] = {x, y, z};
		float* ptr = arr;

		return ptr;
	}
	operator std::vector<float>() {
		std::vector<float> arr;
		arr.push_back(x);
		arr.push_back(y);
		arr.push_back(z);

		return arr;
	}

	Point& Point::operator=(float* rhs) {
		switch (sizeof(rhs)) {
			case 2:
				x = rhs[0];
				y = rhs[1];
				break;
			case 3:
				x = rhs[0];
				y = rhs[1];
				z = rhs[2];
				break;
		}
		return *this;
	}
	Point& Point::operator=(std::vector<float> rhs) {
		switch (sizeof(rhs)) {
			case 2:
				x = rhs[0];
				y = rhs[1];
				break;
			case 3:
				x = rhs[0];
				y = rhs[1];
				z = rhs[2];
				break;
		}
		return *this;
	}

	inline void render() {
		glVertex3f(x, y, z);
	}
};

struct ColoredPoint : public Point {
	float r;
	float g;
	float b;

	inline void render() {
		glColor3f(r, g, b);
		glVertex3f(x, y, z);
	}
};
