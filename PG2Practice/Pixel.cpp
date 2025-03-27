#include "Pixel.h"
#include "Console.h"

void Pixel::Draw() const
{

	Console::SetBackgroundColor(GetPixelColor());
	Console::SetCursorPosition(GetPixelLocation().x, GetPixelLocation().y);
	Console::Write(" ");

	//Resets console 
	Console::Reset();


}

