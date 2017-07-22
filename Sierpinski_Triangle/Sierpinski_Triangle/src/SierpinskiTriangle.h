#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"

class SierpinskiTriangle
{
private:
	vector<ofVec2f*> _vertex;

public:
	// Create the first Triangle
	SierpinskiTriangle();

	// Create a new triangle using 3 vertex coordinate
	SierpinskiTriangle(vector<ofVec2f*> vertex);

	// Return triangle vertex coordinate vector that will be formed inside this triangle
	vector<ofVec2f*> insideTriangle();

	void Draw();
};