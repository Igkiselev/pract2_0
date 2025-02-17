#include <iostream>
#include <fstream>
#include <string>
#include "triangle.h"
#include <math.h>
using namespace std;
int main() {
	Triangle* triangles;
	string f;
	cout << "Enter filename or path: ";
	cin >> f;

	int n = read(triangles, f);
	for (int i = 0; i < n; i++)
	{
		cout << triangles[i];
	}
	
	int t = 0;
	int type;
	while (1)
	{
		printf("Select an operation : 1 - area, 2 - perimeter, 3 - height, 4 - type of triangle:  ");
		cin >> t;
		for (int i = 0; i < n; i++) {
			if (t == 1)
				triangles[i].CountSquare();
			else if (t == 2)
				triangles[i].CountPerimeter();
			else if (t == 3)
				triangles[i].Height();
			else if (t == 4) {
				type = triangles[i].TriangleType();
				if (type == straight)
					cout << "straight" << endl;
				else if (type == sharp)
					cout << "sharp" << endl;
				else if (type == blunt)
					cout << "blunt" << endl;
			}
		}

		cout << "If you want to exit, enter 0: ";
		cin >> t;
		if (t == 0)
			break;
	}
	delete[] triangles;
	return 0;
}