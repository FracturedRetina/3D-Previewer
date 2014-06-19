#include <GL/glfw.h>
#include <iostream>
#include <vector>
#include "../main/util.h"
#include "model.h"

#define X 0
#define Y 1
#define Z 2

using std::vector;

Model::Model() {
	this->verts = vector< vector<float> >();
	this->txtrs = vector< vector<float> >();
	this->norms = vector< vector<float> >();
	this->faces = vector<Face>();
}

Model::Model(vector< vector<float> > verts, vector< vector<float> > txtrs, vector< vector<float> > norms, vector<Face> faces) {
	this->verts = verts;
	this->txtrs = txtrs;
	this->norms = norms;
	this->faces = faces;
}

/*Model::Model(std::string path) {
	std::string extension = split(path, '.').back();

	if (extension == 'obj') {

	} else if (extension == 'dae') {
		std::cout << "Unsupported file type.";
	} else {
		std::cout << "Unsupported file type.";
	}
}*/

void Model::render() {
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.8f, 0.8f, 0.8f);

		for (unsigned int i = 0; i < faces.size(); i++) {
			unsigned int normInd1 = faces.at(i).normIndexes[0] - 1;
			unsigned int normInd2 = faces.at(i).normIndexes[1] - 1;
			unsigned int normInd3 = faces.at(i).normIndexes[2] - 1;
			unsigned int vertInd1 = faces.at(i).vertIndexes[0] - 1;
			unsigned int vertInd2 = faces.at(i).vertIndexes[1] - 1;
			unsigned int vertInd3 = faces.at(i).vertIndexes[2] - 1;


			if (norms.size() > normInd1) {
				glNormal3f(
					norms.at(normInd1).at(X),
					norms.at(normInd1).at(Y),
					norms.at(normInd1).at(Z)
				);
			}
			if (verts.size() > vertInd1) {
				glVertex3f(
					verts.at(vertInd1).at(X),
					verts.at(vertInd1).at(Y),
					verts.at(vertInd1).at(Z)
				);
			}

			if (norms.size() > normInd2) {
				glNormal3f(
					norms.at(normInd2).at(X),
					norms.at(normInd2).at(Y),
					norms.at(normInd2).at(Z)
				);
			}
			if (verts.size() > vertInd2) {
				glVertex3f(
					verts.at(vertInd2).at(X),
					verts.at(vertInd2).at(Y),
					verts.at(vertInd2).at(Z)
				);
			}

			if (norms.size() > normInd3) {
				glNormal3f(
					norms.at(normInd3).at(X),
					norms.at(normInd3).at(Y),
					norms.at(normInd3).at(Z)
				);
			}
			if (verts.size() > vertInd3) {
				glVertex3f(
					verts.at(vertInd3).at(X),
					verts.at(vertInd3).at(Y),
					verts.at(vertInd3).at(Z)
				);
			}
		}
	glEnd();
}
