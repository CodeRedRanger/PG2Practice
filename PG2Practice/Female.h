#pragma once
#include "Person.h"

class Female : public Person
{

private:

	std::string m_hairColor; 

protected:

public:

	Female(std::string eyeColor = "Blue", std::string hairColor = "Blond") : Person(eyeColor), m_hairColor(hairColor)
	{

	}

	//Getters and setters
	const std::string& GetHairColor()
	{
		return m_hairColor;
	}

	void SetHairColor(const std::string& hairColor)
	{
		m_hairColor = hairColor;
	}

	void Draw() override; 


};
