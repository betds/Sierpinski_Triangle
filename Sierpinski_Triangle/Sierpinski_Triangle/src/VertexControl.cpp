#include "VertexControl.h"

VertexControl::VertexControl()
{
	// Calculate the vertex coordinate of First Triangle
	int x = ofGetWindowWidth();
	int y = ofGetWindowHeight();

	_vertexCoordinate.push_back(ofVec2f(x / 2, y / 4));
	_vertexCoordinate.push_back(ofVec2f(x / 4, y * 3 / 4));
	_vertexCoordinate.push_back(ofVec2f(x * 3 / 4, y * 3 / 4));
}

vector<ofVec2f*> VertexControl::vertexTriangle(int id)
{
	vector<ofVec2f*> insTri;
	ofVec2f v1, v2, v3;

	v1.set(_vertexCoordinate.at(0 + id));
	v2.set(_vertexCoordinate.at(1 + id));
	v3.set(_vertexCoordinate.at(2 + id));

	insTri.push_back(new ofVec2f((v1 + v2) / 2));
	insTri.push_back(new ofVec2f((v1 + v3) / 2));
	insTri.push_back(new ofVec2f((v3 + v2) / 2));

	return insTri;
}
