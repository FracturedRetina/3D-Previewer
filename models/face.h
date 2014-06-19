#pragma once
#include <vector>

using std::vector;

struct Face {
	int vertIndexes[3];
	int txtrIndexes[3];
	int normIndexes[3];

	Face(int xv, int yv, int zv, int xt, int yt, int zt, int xn, int yn, int zn) {
		vertIndexes[0] = xv;
		vertIndexes[1] = yv;
		vertIndexes[2] = zv;

		txtrIndexes[0] = xt;
		txtrIndexes[1] = yt;
		txtrIndexes[2] = zt;

		normIndexes[0] = xn;
		normIndexes[1] = yn;
		normIndexes[2] = zn;
	}

	Face(int* verts, int *txtrs, int *norms) {
		vertIndexes[0] = verts[0];
		vertIndexes[1] = verts[1];
		vertIndexes[2] = verts[2];

		txtrIndexes[0] = txtrs[0];
		txtrIndexes[1] = txtrs[1];
		txtrIndexes[2] = txtrs[2];

		normIndexes[0] = norms[0];
		normIndexes[1] = norms[1];
		normIndexes[2] = norms[2];
	}

	Face(vector<int> verts, vector<int> txtrs, vector<int> norms) {
		vertIndexes[0] = verts[0];
		vertIndexes[1] = verts[1];
		vertIndexes[2] = verts[2];

		txtrIndexes[0] = txtrs[0];
		txtrIndexes[1] = txtrs[1];
		txtrIndexes[2] = txtrs[2];

		normIndexes[0] = norms[0];
		normIndexes[1] = norms[1];
		normIndexes[2] = norms[2];
	}

	Face(vector<float> verts, vector<float> txtrs, vector<float> norms) {
		vertIndexes[0] = (int) verts[0];
		vertIndexes[1] = (int) verts[1];
		vertIndexes[2] = (int) verts[2];

		txtrIndexes[0] = (int) txtrs[0];
		txtrIndexes[1] = (int) txtrs[1];
		txtrIndexes[2] = (int) txtrs[2];

		normIndexes[0] = (int) norms[0];
		normIndexes[1] = (int) norms[1];
		normIndexes[2] = (int) norms[2];
	}
};
