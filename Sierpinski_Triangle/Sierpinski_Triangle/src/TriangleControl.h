#pragma once
#include "ofMain.h"
#include "SierpinskiTriangle.h"
#include "ofMath.h"

class TriangleControl
{
private:
	int _numberTriangles, _lastTriangles;
	bool _lessTri, _moreTri;
	vector<SierpinskiTriangle> _sierTri;

public:
	TriangleControl();

	void Update();

	void Draw();

	//Create new 3 Triangles
	vector<SierpinskiTriangle> createTriangle(SierpinskiTriangle Digo);
	void AddTriangles(SierpinskiTriangle Digo, int trigo);

	void GetKeyPress(int a);
};