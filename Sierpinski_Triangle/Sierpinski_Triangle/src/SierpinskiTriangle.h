#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"

class SierpinskiTriangle
{
private:
	vector<ofVec2f*> _vertex;
	int _color;

public:
	// Create the first Triangle
	SierpinskiTriangle(int color);

	// Create a new triangle using 3 vertex coordinate
	SierpinskiTriangle(ofVec2f v1, ofVec2f v2, ofVec2f v3);
	
	void Draw();

	vector<ofVec2f> SierpinskiCoordinate() const;

};