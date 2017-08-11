#pragma once
#include "ofMain.h"

class VertexCoordinate
{
private:
	//AdressR, adressL
	ofVec2f _vertex;
	ofVec2f *_adressR, *_adressL;

public:
	VertexCoordinate();
	~VertexCoordinate();

};

VertexCoordinate::VertexCoordinate()
{
}

VertexCoordinate::~VertexCoordinate()
{
}