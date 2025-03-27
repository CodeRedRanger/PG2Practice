#include "Person.h"

void Person::Draw()
{

	std::string eyeColorStr = this->GetEyeColor();

	ConsoleColor eyeColor; 

	if (eyeColorStr == "Blue") eyeColor = ConsoleColor::Blue;
	if (eyeColorStr == "Brown") eyeColor = ConsoleColor::Red;
	if (eyeColorStr == "Green") eyeColor = ConsoleColor::Green;


	Point2D center(60, 15); 
	int radius = 10; 
	
	Circle circle(radius, center, ConsoleColor::White); 

	circle.Draw(); 

	Point2D eye1(57, 13);
	Point2D eye2(63, 13); 

	Pixel eyeL(eye1, eyeColor); 
	Pixel eyeR(eye2, eyeColor); 

	eyeL.Draw();
	eyeR.Draw(); 

	Point2D mouth1(57, 19);
	Point2D mouth2(63, 19); 

	Line mouth(mouth1, mouth2, ConsoleColor::Red); 
	mouth.Draw(); 

	Point2D mouthL(56,20); 
	Point2D mouthR(64,20); 

	Pixel mouthLL(mouthL, ConsoleColor::Red); 
	Pixel mouthRR(mouthR, ConsoleColor::Red);

	mouthLL.Draw(); 
	mouthRR.Draw(); 

	Point2D nose1(60, 16);

	Pixel nose(nose1, ConsoleColor::White);

	nose.Draw();


}