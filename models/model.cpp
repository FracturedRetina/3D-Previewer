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

}

Model::Model(vector<Point> verts, vector<Point> txtrs, vector<Point> norms, vector<Face> faces) {
	this->verts = verts;
	this->txtrs = txtrs;
	this->norms = norms;
	this->faces = faces;
}
/*Model::Model(vector< vector<float> > verts, vector< vector<float> > txtrs, vector< vector<float> > norms, vector<Face> faces) {
	this->verts = verts;
	this->txtrs = txtrs;
	this->norms = norms;
	this->faces = faces;
}*/

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
					norms.at(normInd1).x,
					norms.at(normInd1).y,
					norms.at(normInd1).z
				);
				/*std::cout << "Normal[" << normInd1<< "]: "
				<< norms.at(normInd1).x << ", "
				<< norms.at(normInd1).y << ", "
				<< norms.at(normInd1).z << std::endl;*/
			}
			if (verts.size() > vertInd1) {
				glVertex3f(
					verts.at(vertInd1).x,
					verts.at(vertInd1).y,
					verts.at(vertInd1).z
				);
				/*std::cout << "Vertex[" << vertInd1<< "]: "
				<< verts.at(vertInd1).x << ", "
				<< verts.at(vertInd1).y << ", "
				<< verts.at(vertInd1).z << std::endl;*/
			}

			if (norms.size() > normInd2) {
				glNormal3f(
					norms.at(normInd2).x,
					norms.at(normInd2).y,
					norms.at(normInd2).z
				);
			}
			if (verts.size() > vertInd2) {
				glVertex3f(
					verts.at(vertInd2).x,
					verts.at(vertInd2).y,
					verts.at(vertInd2).z
				);
			}

			if (norms.size() > normInd3) {
				glNormal3f(
					norms.at(normInd3).x,
					norms.at(normInd3).y,
					norms.at(normInd3).z
				);
			}
			if (verts.size() > vertInd3) {
				glVertex3f(
					verts.at(vertInd3).x,
					verts.at(vertInd3).y,
					verts.at(vertInd3).z
				);
			}
		}
	glEnd();
}
