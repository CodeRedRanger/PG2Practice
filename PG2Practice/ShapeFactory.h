#pragma once
#include "Shape.h"
#include "Line.h"
//#include "Triangle.h"
//#include "Rectangle.h"
#include "Circle.h"


class ShapeFactory
{

private:

protected:

public:

	//static functions cannot be made const, since const refers to object instances
	static const Point2D RandomPoint(); 

	static const ConsoleColor RandomColor(); 

	static std::unique_ptr<Line> RandomLine(); 

	//static std::unique_ptr<Triangle> RandomTriangle(); 

	//static std::unique_ptr<Rectangle> RandomRectangle(); 

	static std::unique_ptr<Circle> RandomCircle(); 


};


