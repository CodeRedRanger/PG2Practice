#include "Female.h"


void Female::Draw()
{
	Person::Draw();


	Point2D topHair1(57, 4);
	Point2D topHair2(63, 4);

	Line topHair(topHair1, topHair2, ConsoleColor::Yellow);
	topHair.Draw();

	Point2D leftHair1(49, 11);
	Point2D leftHair2(49, 27);

	Line leftHair(leftHair1, leftHair2, ConsoleColor::Yellow);
	leftHair.Draw();

	Point2D leftDiagHair1(58, 4);
	Point2D leftDiagHair2(49, 11);

	Line leftDiagHair(leftDiagHair1, leftDiagHair2, ConsoleColor::Yellow);
	leftDiagHair.Draw();

	Point2D rightHair1(71, 11);
	Point2D rightHair2(71, 27);

	Line rightHair(rightHair1, rightHair2, ConsoleColor::Yellow);
	rightHair.Draw();

	Point2D rightDiagHair1(62, 4);
	Point2D rightDiagHair2(71, 11);

	Line rightDiagHair(rightDiagHair1, rightDiagHair2, ConsoleColor::Yellow);
	rightDiagHair.Draw();


	//Point2D center(60, 15);
	//int radius = 10;



	



}