#pragma once
#include "Point2D.h"
#include "Console.h"

class Pixel
{
private:
	Point2D m_pixelLocation; 
	ConsoleColor m_pixelColor; 


protected:

public:

	Pixel(Point2D pixelLocation, ConsoleColor pixelColor) :
		m_pixelLocation(pixelLocation), m_pixelColor(pixelColor)
	{

	}

	//Getters and setters
	const Point2D& GetPixelLocation() const
	{
		return m_pixelLocation; 
	}

	void SetPixelLocation(const Point2D& newPixelLocation)
	{
		m_pixelLocation = newPixelLocation; 
	}

	const ConsoleColor& GetPixelColor() const
	{
		return m_pixelColor; 
	}

	void SetPixelColor(const ConsoleColor& newPixelColor)
	{
		m_pixelColor = newPixelColor; 
	}

	void Draw() const; 

};

