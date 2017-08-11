#include "TriangleControl.h"

TriangleControl::TriangleControl()
{
	_numberTriangles = 0;
	_lastTriangles = 0;
	_sierTri.push_back(SierpinskiTriangle(0));
	_sierTri.push_back(SierpinskiTriangle(144));
}

void TriangleControl::Update()
{
	std::cout << "tri: " << _numberTriangles << " || last: " << _lastTriangles << std::endl;

	if (_moreTri)
	{
		_numberTriangles++;
		_moreTri = false;
	}
	if (_lessTri)
	{
		if (_numberTriangles > 1)
			_numberTriangles--;

		_lessTri = false;
	}
	std::cout << "tri: " << _numberTriangles << " || last: " << _lastTriangles << std::endl;

	if (_lastTriangles > _numberTriangles || _lastTriangles < _numberTriangles)
	{
		MinusTriangles((_numberTriangles - 1));
		AddTriangles(_sierTri.at(0), _numberTriangles);

		_lastTriangles = _numberTriangles;
	}
}

void TriangleControl::Draw()
{
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
		createTriangle(createTriangle(Digo).at(0));
		createTriangle(createTriangle(Digo).at(1));
		createTriangle(createTriangle(Digo).at(2));
	}

}

void TriangleControl::MinusTriangles(int less)
{
	int eraseTri = pow(3, less);

	for (int i = _sierTri.size(); i > eraseTri; i--)
	{
		_sierTri.pop_back();
	}
}

void TriangleControl::GetKeyPress(int a)
{
	if (a == 1)
		_moreTri = true;

	if (a == -1)
		_lessTri = true;
}
