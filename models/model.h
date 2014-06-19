#pragma once
#include <string>
#include <vector>
#include "face.h"

using std::vector;

class Model {
	private:
		vector< vector<float> > verts;
		vector< vector<float> > txtrs;
		vector< vector<float> > norms;
		vector< Face > faces;
	public:
		Model();
		Model(
			vector< vector<float> > verts,
			vector< vector<float> > txtrs,
			vector< vector<float> > norms,
			vector< Face > faces
		);
		/*Model(std::string path);*/
		void render();
};
