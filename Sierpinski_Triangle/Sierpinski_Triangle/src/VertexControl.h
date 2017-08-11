#pragma once
#include "ofMain.h"
class VertexControl
{
private:
	vector<ofVec2f> _vertexCoordinate;

public:
	VertexControl();

	// Return triangle vertex coordinate vector that will be formed inside of "id" triangle
	vector<ofVec2f*> vertexTriangle(int id);

};