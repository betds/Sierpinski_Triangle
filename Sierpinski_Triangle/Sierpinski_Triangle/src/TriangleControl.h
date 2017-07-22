#pragma once
#include "ofMain.h"
#include "SierpinskiTriangle.h"

class TriangleControl
{
private:
	int _numberTriangles;
	vector<SierpinskiTriangle*> _sierTri;
	bool _lessTri, _moreTri;

public:
	TriangleControl();

	void Update();

	void Draw();

	void GetKeyPress(int a);
	void GetKeyRelease(int a);
};