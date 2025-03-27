#pragma once
#include "Pixel.h"
#include "Line.h"
#include "Circle.h"

class Person
{
private:

protected:
 
	std::string m_eyeColor; 
	

public:

	Person(std::string eyeColor = "Blue") : m_eyeColor(eyeColor) 
	{

	}

	virtual void Draw();


	const std::string& GetEyeColor()
	{
		return m_eyeColor;
	}

	void SetEyeColor(const std::string& eyeColor)
	{
		m_eyeColor = eyeColor;
	}

};