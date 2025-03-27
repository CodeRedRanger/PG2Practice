#include "Line.h"

Line::Line(const Point2D& point1, const Point2D& point2, const ConsoleColor& color) : Shape(point1, color), m_endpoint(point2)
{



}

void Line::Draw() const
{
	Console::SetBackgroundColor(GetShapeColor());
	this->PlotLine(GetShapeLocation().x, GetShapeLocation().y, m_endpoint.x, m_endpoint.y);  
	Console::Reset(); 
	

}


void Line::PlotLine(int x0, int y0, const int x1, const int y1) const
{
	int dx = abs(x1 - x0); 
	int sx = x0 < x1 ? 1 : -1; 

	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy; 


	while (true)
	{
		this->Plot(x0, y0); 

		if (x0 == x1 && y0 == y1)
		{
			break; 
		}

		int e2 = 2 * error; 

		if (e2 >= dy)
		{
			if (x0 == x1)
			{
				break;
			}

			error = error + dy; 
			x0 = x0 + sx;

		}

		if (e2 <= dx)
		{
			if (y0 == y1)
			{
				break;
			}
			error = error + dx;
			y0 = y0 + sy; 
		}

	}


}
