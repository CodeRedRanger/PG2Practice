#include "Male.h"

void Male::Draw()
{
	Person::Draw(); 

	Point2D topHair1(57, 5);
	Point2D topHair2(63, 5);

	Line topHair(topHair1, topHair2, ConsoleColor::Yellow);
	topHair.Draw();

	Point2D leftHair1(57, 5);
	Point2D leftHair2(57, 7);

	Line leftHair(leftHair1, leftHair2, ConsoleColor::Yellow);
	leftHair.Draw();

	Point2D midHair1(60, 5);
	Point2D midHair2(60, 7);

	Line midHair(midHair1, midHair2, ConsoleColor::Yellow);
	midHair.Draw();

	Point2D rightHair1(63, 5);
	Point2D rightHair2(63, 7);

	Line rightHair(rightHair1, rightHair2, ConsoleColor::Yellow);
	rightHair.Draw();

	Point2D leftDiagHair1(57, 5);
	Point2D leftDiagHair2(50, 11);

	Line leftDiagHair(leftDiagHair1, leftDiagHair2, ConsoleColor::Yellow);
	leftDiagHair.Draw();

	Point2D rightDiagHair1(63, 5);
	Point2D rightDiagHair2(70, 11);

	Line rightDiagHair(rightDiagHair1, rightDiagHair2, ConsoleColor::Yellow);
	rightDiagHair.Draw();


	//Point2D center(60, 15);
	//int radius = 10;


}