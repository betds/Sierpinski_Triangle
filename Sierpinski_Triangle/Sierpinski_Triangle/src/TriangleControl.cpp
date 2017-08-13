#include "TriangleControl.h"

TriangleControl::TriangleControl()
{
	_numberTriangles = 0;
	_lastTriangles = 0;
	_amoutTri = 1;

	_moreTri = false;
	_lessTri = false;

	_sierTri.push_back(SierpinskiTriangle(200));
	_sierTri.push_back(SierpinskiTriangle(255));
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
		if (_numberTriangles > 0)
			_numberTriangles--;

		_lessTri = false;
	}

	if (_lastTriangles < _numberTriangles || _lastTriangles > _numberTriangles)
	{
		for (int i = _sierTri.size(); i > 1; i--)
			_sierTri.pop_back();

		AddTriangles(_sierTri.at(0), _numberTriangles);

		_lastTriangles = _numberTriangles;
		_amoutTri = _sierTri.size() - 1;
	}
}

void TriangleControl::Draw()
{
	ofSetColor(0);
	ofDrawBitmapString("Hello!", 15, 15);
	ofDrawBitmapString("key right / a / z -> more Triangles", 15, 30);
	ofDrawBitmapString("key left / s / x -> less Triangles", 15, 45);
	ofDrawBitmapString("Amout of Triangles: " + ofToString(_amoutTri), 15, 60);
	ofSetColor(255);

	for (int i = 0; i < _sierTri.size(); i++)
	{
		_sierTri.at(i).Draw();
	}
}

vector<SierpinskiTriangle> TriangleControl::createTriangle(SierpinskiTriangle Digo)
{
	vector<SierpinskiTriangle> tri;
	vector<ofVec2f> vertex;

	vertex.push_back(Digo.SierpinskiCoordinate().at(0));
	vertex.push_back(Digo.SierpinskiCoordinate().at(1));
	vertex.push_back(Digo.SierpinskiCoordinate().at(2));

	ofVec2f vert;

	//Vertex4
	vert = (vertex.at(0) + vertex.at(1)) / 2;
	vertex.push_back(vert);

	//Vertex5
	vert = (vertex.at(0) + vertex.at(2)) / 2;
	vertex.push_back(vert);

	//Vertex6
	vert = (vertex.at(1) + vertex.at(2)) / 2;
	vertex.push_back(vert);

	// Top Triangle
	tri.push_back(SierpinskiTriangle(vertex.at(0), vertex.at(3), vertex.at(4)));
	// Left Triangle
	tri.push_back(SierpinskiTriangle(vertex.at(3), vertex.at(1), vertex.at(5)));
	// Right Triangle
	tri.push_back(SierpinskiTriangle(vertex.at(4), vertex.at(5), vertex.at(2)));

	return tri;
}

void TriangleControl::AddTriangles(SierpinskiTriangle Digo, int trigo)
{
	if (trigo <= 0)
	{
		_sierTri.push_back(SierpinskiTriangle(Digo));
	}
	else
	{
		trigo--;
		AddTriangles(createTriangle(Digo).at(0), trigo);
		AddTriangles(createTriangle(Digo).at(1), trigo);
		AddTriangles(createTriangle(Digo).at(2), trigo);
	}

}

void TriangleControl::GetKeyPress(int a)
{
	if (a == 1)
		_moreTri = true;

	if (a == -1)
		_lessTri = true;
}
