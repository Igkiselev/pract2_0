#ifndef _TRIANGLE_H
#define _TRIANGLE_H

typedef struct {
	float x, y;
}Coord;

typedef struct {
	Coord vertices[3]; 
}Triangle;


char* read_string(FILE* stream);
char* getPath();
Triangle* ReadTriangleFile(char* file_path, int* number_of_triangles);
Triangle ReadTriangleEntity(FILE* file);
float CountSquare(Triangle triangle);
float CountPerimeter(Triangle triangle);
float* Sides(Triangle triangle);
float* Height(Triangle triangle);
void PrintTriangleType(Triangle triangle);


#endif _TRIANGLE_H