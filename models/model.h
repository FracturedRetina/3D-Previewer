#pragma once
#include <string>
#include <vector>
#include "point.h"
#include "face.h"

using std::vector;

class Model {
	private:
		vector<Point> verts;
		vector<Point> txtrs;
		vector<Point> norms;
		vector<Face> faces;
	public:
		Model();
		Model(
			vector<Point> verts,
			vector<Point> txtrs,
			vector<Point> norms,
			vector<Face> faces
		);
		/*Model(
			vector< vector<float> > verts,
			vector< vector<float> > txtrs,
			vector< vector<float> > norms,
			vector< Face > faces
		);*/
		/*Model(std::string path);*/
		void render();
};
