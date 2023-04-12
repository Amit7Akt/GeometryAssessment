#include<gl/glut.h>

#include<math.h>

#include<iostream>

#include<vector>

using namespace std;

class vertex

{

public:

	float x, y, z;

};

vector<vertex> v;

GLfloat T = 0;

void myInit()

{

	glClearColor(0, 0, 0, 1);

	glColor3f(1, 0, 0);

	glEnable(GL_DEPTH_TEST);

}

void draw()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPointSize(10);

	glBegin(GL_POLYGON);

	for (int i = 0; i < v.size(); i++) {



		glVertex3f(v[i].x, v[i].y, v[i].z);

	}

	glEnd();

	glutSwapBuffers();

}

int main(int argc, char** argv) {




	for (int i = 0; i < 3; i++)

	{

		vertex ver;

		cout << "enter x,y,z of vertex :" << i + 1 << ":";

		cin >> ver.x >> ver.y >> ver.z;

		v.push_back(ver);

	}

	glutInit(&argc, argv);

	glClearColor(0, 0, 0, 1);

	glutInitWindowPosition(0, 0);

	glutInitWindowSize(600, 600);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("3Dtriangle");

	myInit();

	glutDisplayFunc(draw);

	glutMainLoop();

}
