#include "SierpinskiTriangle.h"

SierpinskiTriangle::SierpinskiTriangle(int color)
{
	_color = color;

	_vertex.push_back(new ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/4));
	_vertex.push_back(new ofVec2f(ofGetWindowWidth()/4, ofGetWindowHeight() * 3 / 4));
	_vertex.push_back(new ofVec2f(ofGetWindowWidth() * 3 / 4, ofGetWindowHeight() * 3 / 4));
}

SierpinskiTriangle::SierpinskiTriangle(ofVec2f v1, ofVec2f v2, ofVec2f v3)
{
	_color = 255;

	_vertex.push_back(new ofVec2f(v1));
	_vertex.push_back(new ofVec2f(v2));
	_vertex.push_back(new ofVec2f(v3));
}

void SierpinskiTriangle::Draw()
{
	ofSetColor(_color);
	ofDrawTriangle(*_vertex.at(0), *_vertex.at(1), *_vertex.at(2));
	ofSetColor(255);
}

vector<ofVec2f> SierpinskiTriangle::SierpinskiCoordinate() const
{
	vector<ofVec2f> vert;
	
	vert.push_back(*_vertex.at(0));
	vert.push_back(*_vertex.at(1));
	vert.push_back(*_vertex.at(2));

	return vert;
}