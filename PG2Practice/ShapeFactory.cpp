#include "ShapeFactory.h"

const Point2D ShapeFactory::RandomPoint()
{


	int x = (rand() % (Console::GetWindowWidth() - 1)) + 1;
	int y = (rand() % (Console::GetWindowHeight() - 1)) + 1;

	Point2D randomPoint(x, y);

	return randomPoint;

}

const ConsoleColor ShapeFactory::RandomColor()
{

	ConsoleColor randomColor = (ConsoleColor)((rand() % 7) + 1);

	return randomColor;
}


std::unique_ptr<Line> ShapeFactory::RandomLine()

{

	Point2D firstPoint = RandomPoint();
	Point2D secondPoint = RandomPoint();

	return std::make_unique<Line>(firstPoint, secondPoint, RandomColor());

}

//std::unique_ptr<Triangle> ShapeFactory::RandomTriangle()
//{
//
//	Point2D firstVertex = RandomPoint();
//	Point2D secondVertex = RandomPoint();
//	Point2D thirdVertex = RandomPoint();
//
//	return std::make_unique<Triangle>(firstVertex, secondVertex, thirdVertex, RandomColor());
//}
//
//std::unique_ptr<Rectangle> ShapeFactory::RandomRectangle()
//{
//
//	Point2D startPoint(0, 0);
//	int recWidth;
//	int recHeight;
//
//	//stays in loop until rectangle fits in screen
//	while (true)
//	{
//		startPoint = RandomPoint();
//
//		recWidth = rand() % (Console::GetWindowWidth() - 1) + 1;
//		recHeight = rand() % (Console::GetWindowHeight() - 1) + 1;
//
//		int Width = startPoint.x + recWidth;
//		int Height = startPoint.y + recHeight;
//
//		if (Width < Console::GetWindowWidth() && Width > 0 && Height < Console::GetWindowHeight() && Height > 0)
//		{
//			break;
//		}
//	}
//
//	return std::make_unique<Rectangle>(recWidth, recHeight, startPoint, RandomColor());
//
//}

std::unique_ptr<Circle> ShapeFactory::RandomCircle()
{
	//Did not use RandomPoint() because location of circle radius is more limited than other shapes

	//center x coordinate 3 to WindowWidth -3 (gives room for a circle with a radius of two)
	int x0 = rand() % (Console::GetWindowWidth() - 5) + 3;

	//center y coordinate 3 to WindowHeight -3 (gives room for a circle with a radius of two)
	int y0 = rand() % (Console::GetWindowHeight() - 5) + 3;

	Point2D circleCenter(x0, y0);
	int rad = 0;

	//stays in loop until circle fits in screen
	while (true)
	{
		//rad is 2 to half the height minus 1 (biggest circle would stretch from top of screen + 1 to bottom of screen minus 1, smallest radius is 2)
		rad = (rand() % ((Console::GetWindowHeight() - 6) / 2) + 2);

		//checks if combo of radius and center point would put circle edge outside of screen
		if (x0 - rad > 0 && x0 + rad < Console::GetWindowWidth() && y0 - rad > 0 && y0 + rad < Console::GetWindowHeight())
		{
			break;
		}

	}

	return std::make_unique<Circle>(rad, circleCenter, RandomColor());

}


