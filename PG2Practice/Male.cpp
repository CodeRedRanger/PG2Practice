#include "Male.h"

void Male::Draw()
{
	Person::Draw(); 

	std::string hairColorStr = this->GetHairColor();
	ConsoleColor hairColor;

	if (hairColorStr == "Blond") hairColor = ConsoleColor::Yellow;
	if (hairColorStr == "Brown") hairColor = ConsoleColor::Red;
	if (hairColorStr == "Bald") hairColor = ConsoleColor::White;

	Point2D topHair1(57, 5);
	Point2D topHair2(63, 5);

	Line topHair(topHair1, topHair2, hairColor);
	topHair.Draw();

	Point2D leftHair1(57, 5);
	Point2D leftHair2(57, 7);

	Line leftHair(leftHair1, leftHair2, hairColor);
	leftHair.Draw();

	Point2D midHair1(60, 5);
	Point2D midHair2(60, 7);

	Line midHair(midHair1, midHair2, hairColor);
	midHair.Draw();

	Point2D rightHair1(63, 5);
	Point2D rightHair2(63, 7);

	Line rightHair(rightHair1, rightHair2, hairColor);
	rightHair.Draw();

	Point2D leftDiagHair1(57, 5);
	Point2D leftDiagHair2(50, 11);

	Line leftDiagHair(leftDiagHair1, leftDiagHair2, hairColor);
	leftDiagHair.Draw();

	Point2D rightDiagHair1(63, 5);
	Point2D rightDiagHair2(70, 11);

	Line rightDiagHair(rightDiagHair1, rightDiagHair2, hairColor);
	rightDiagHair.Draw();


}