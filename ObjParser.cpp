#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>

using namespace std;

struct vertex {
	float a, b, c;
};

int main()
{
	ifstream obj_file("Cube.obj");
	if (!obj_file) {
		cerr << "Can't open or find the specified file" << endl;
	}

	vector<vertex> vertices;
	vector<vector<int>> faces;
	string line;
	while (getline(obj_file, line))
	{
		istringstream iss(line);
		string prefix;
		vertex v;
		if (!(iss >> prefix)) continue;
		else if (prefix == "v") {
			iss >> v.a >> v.b >> v.c;
			vertices.push_back(v); // fixed line
		}
		else if (prefix == "f") {
			int vertex_index, texcoord_index, normal_index;
			vector<int> face;
			if (iss.peek() == '/') {
				iss.ignore();
				if (iss.peek() != '/') {
					iss >> texcoord_index;
				}
				if (iss.peek() == '/') {
					iss.ignore();
					iss >> normal_index;
				}
				face.push_back(vertex_index);
			}
			faces.push_back(face);
		}

	}


	for (const auto& face : faces) {
		std::cout << "Face: ";
		for (const auto& index : face) {
			std::cout << index << " ";
		}
		std::cout << "\n";
	}

	obj_file.close();
}







