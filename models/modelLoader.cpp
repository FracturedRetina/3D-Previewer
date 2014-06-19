#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "point.h"
#include "face.h"
#include "../main/util.h"
#include "modelLoader.h"

using namespace std;

Model loadObj(string path) {
	vector< Point > verts;
	vector< Point > txtrs;
	vector< Point > norms;
	vector< Face > faces;

	string line;
	ifstream fin(path.c_str());

	if (!fin.good()) {
		cout << "File not found: " << path << endl;
	} else if (split(path, '.').back() != "obj") {
		cout << "Invalid file type." << endl;
	}

	while (getline(fin, line)) {
		vector<string> splitLn;

		//If line is empty
		if (line == "" || line == "\n") {
			continue;
		}

		splitLn = split(line, ' ');

		//If line is comment
		if (splitLn[0].c_str()[0] == '#') {
			continue;
		}

		Point xyz;
		if ((splitLn[0] == "v" || splitLn[0] == "vt" || splitLn[0] == "vn") && splitLn[0] != "f") {
			xyz.x = ::atof(splitLn[1].c_str());
			xyz.y = ::atof(splitLn[2].c_str());
			xyz.z = ::atof(splitLn[3].c_str());
		}
		if (splitLn[0] == "v") {
			verts.push_back(xyz);
		} else if (splitLn[0] == "vt") {
			txtrs.push_back(xyz);
		} else if (splitLn[0] == "vn") {
			norms.push_back(xyz);
		} else if (splitLn[0] == "f") {
			vector<int> vIndexes;
			vector<int> tIndexes;
			vector<int> nIndexes;

			string item;
			for (unsigned int segment = 1; segment < splitLn.size(); segment++) {
				int i = 0;
				stringstream ss(splitLn[segment]);

				while (getline(ss, item, '/')) {
					int val;

					if (item != "") {
						val = atoi(item.c_str());
					} else {
						val = -1;
					}

					switch (i) {
						case 0: vIndexes.push_back(val);
							break;
						case 1: tIndexes.push_back(val);
							break;
						case 2: nIndexes.push_back(val);
							break;
					}

					i++;
				}

				if (i == 1) {
					tIndexes.push_back(-1);
				}
				if (i == 2) {
					nIndexes.push_back(-1);
				}
			}

//			cout << "-Face-" << endl;
//			cout << "vertices: " << vIndexes[0] << ", " << vIndexes[1] << ", " << vIndexes[2] << ", " << endl;
//			cout << "textures: " << tIndexes[0] << ", " << tIndexes[1] << ", " << tIndexes[2] << ", " << endl;
//			cout << "normals:  " << nIndexes[0] << ", " << nIndexes[1] << ", " << nIndexes[2] << ", " << endl;
			faces.push_back(Face(vIndexes, tIndexes, nIndexes));
		} else if (splitLn[0] == "mtllib") {
//			if (sizeof(splitLn) > 1) {
//				cout << "Accessing .mtl file, \"" << splitLn[1] << "\"" << endl;
//			}
		} else if (splitLn[0] == "usemtl") {

		} else if (splitLn[0] == "o") {
			if (sizeof(splitLn) > 1) {
				cout << "Object: " << splitLn[1] << endl;
			}
		} else if (splitLn[0] == "g") {
			if (sizeof(splitLn) > 1) {
				cout << "Group: " << splitLn[1] << endl;
			}
		} else if (splitLn[0] == "s") {
			//Smoothing groups
		} else {
			cout << "Unrecognized Key, \"" << splitLn[0] << "\"" << endl;
		}
	}

	fin.close();


	return Model(verts, txtrs, norms, faces);
}
