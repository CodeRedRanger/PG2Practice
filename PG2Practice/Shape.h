#pragma once
#include "Point2D.h"
#include "Console.h"

class Shape
{
private:

	Point2D m_shapeLocation; 
	ConsoleColor m_shapeColor; 

protected:

public:

	Shape(Point2D location, ConsoleColor color); 

	Shape(int x, int y, ConsoleColor color); 

	virtual void Draw() const = 0;

	void Plot(const int x, const int y) const; 

	const Point2D& GetShapeLocation() const
	{
		return m_shapeLocation;
	}

	void SetShapeLocation(const Point2D& newLocation) 
	{
		m_shapeLocation = newLocation; 
	}

	const ConsoleColor& GetShapeColor() const
	{
		return m_shapeColor;
	}

	void SetShapeColor(const ConsoleColor& newColor)
	{
		m_shapeColor = newColor;
	}



};

