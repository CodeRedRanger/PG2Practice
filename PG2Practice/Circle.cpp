#include "Circle.h"
#include <algorithm>

Circle::Circle(const int& radius, const Point2D& centerPoint, const ConsoleColor& color) :
	Shape(centerPoint, color), m_radius(radius)

{
	
}

void Circle::DrawCirclePoints(int xc, int yc, int x, int y) const
{
	Plot(xc + x, yc + y);
	Plot(xc - x, yc + y); 
	Plot(xc + x, yc - y); 
	Plot(xc - x, yc - y); 
	Plot(xc + y, yc + x); 
	Plot(xc - y, yc + x);
	Plot(xc + y, yc - x); 
	Plot(xc - y, yc - x); 

}

void Circle::DrawCircle(int xc, int yc, int r) const
{
	

	int x = 0;
	int y = r; 
	int d = 3 - 2 * r; 
	DrawCirclePoints(xc, yc, x, y); 

	while (y >= x)
	{
		x += 1; 
		if (d > 0)
		{
			y -= 1; 
			d = d + 4 * (x - y) + 10;

		}
		else
		{
			d = d + 4 * x + 6; //order of operations?
		}

		DrawCirclePoints(xc, yc, x, y); 
	}

}

void Circle::Draw() const
{
	Console::SetBackgroundColor(GetShapeColor());
	DrawCircle(GetShapeLocation().x, GetShapeLocation().y, m_radius);
	Console::Reset();
}
