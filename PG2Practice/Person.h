#pragma once
#include "Pixel.h"
#include "Line.h"
#include "Circle.h"

class Person
{
private:

protected:

	int m_x; 
	int m_y; 
	int m_radius; 
	

public:

	Person(int x = 0, int y = 0, int radius = 0) : m_x(x), m_y(y), m_radius(radius)
	{

	}

	virtual void Draw();


};