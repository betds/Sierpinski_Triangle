#include "TriangleControl.h"

TriangleControl::TriangleControl()
{
	_numberTriangles = 1;
	_sierTri.push_back(new SierpinskiTriangle());
}

void TriangleControl::Update()
{
	if (_moreTri)
	{
		_numberTriangles++;
		_moreTri = false;
	}
	if (_lessTri)
	{
		_numberTriangles--;
		_lessTri = false;
	}

	for (int i = 0; i < _numberTriangles; i++)
	{

	}
}

void TriangleControl::Draw()
{
	for (int i = 0; i < _numberTriangles; i++)
	{
		_sierTri.at(i)->Draw();
	}
}

void TriangleControl::GetKeyPress(int a)
{
	if (a = 1) 
		_moreTri = true;
	if (a = -1)
		_lessTri = true;
}

void TriangleControl::GetKeyRelease(int a)
{
	if (a = 1)
		_moreTri = false;
	if (a = -1)
		_lessTri = false;
}
