#include "SierpinskiTriangle.h"

SierpinskiTriangle::SierpinskiTriangle()
{
	int x = ofGetWindowWidth();
	int y = ofGetWindowHeight();

	_vertex.push_back(new ofVec2f(x / 2, y / 4));
	_vertex.push_back(new ofVec2f(x / 4, y * 3 / 4));
	_vertex.push_back(new ofVec2f(x * 3 / 4, y * 3 / 4));
}

SierpinskiTriangle::SierpinskiTriangle(vector<ofVec2f*> vertex)
{
	for (int i = 0; i < 3; i++)
	{
		_vertex.push_back(new ofVec2f(*vertex.at(i)));
	}
}

vector<ofVec2f*> SierpinskiTriangle::insideTriangle()
{
	vector<ofVec2f*> insTri;
	ofVec2f v1, v2, v3;
	v1.set(*_vertex.at(0));
	v2.set(*_vertex.at(1));
	v3.set(*_vertex.at(2));

	insTri.push_back(new ofVec2f((v1 + v2) / 2));
	insTri.push_back(new ofVec2f((v1 + v3) / 2));
	insTri.push_back(new ofVec2f((v3 + v2) / 2));

	return insTri;
}

void SierpinskiTriangle::Draw()
{
	ofSetColor(144);
	ofVec2f v1, v2, v3;
	v1.set(*_vertex.at(0));
	v2.set(*_vertex.at(1));
	v3.set(*_vertex.at(2));
	ofDrawTriangle(v1, v2, v3);
}
