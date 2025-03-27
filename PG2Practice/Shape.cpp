#include "Shape.h"


Shape::Shape(Point2D location, ConsoleColor color): m_shapeLocation(location), m_shapeColor(color)
{
	
}

Shape::Shape(int x, int y, ConsoleColor color) : m_shapeLocation(x,y), m_shapeColor(color)
{


}

void Shape::Plot(const int x, const int y) const
{
	Console::SetCursorPosition(x, y);
	Console::Write(" ");

}
