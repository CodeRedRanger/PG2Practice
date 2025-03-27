#pragma once
#include "Person.h"


class Male : public Person
{

private:
	int m_hairX;
	int m_hairY; 

protected:

public:

	Male(int x = 0, int y = 0, int radius = 0, int hairX = 0, int hairY = 0) : Person(x, y, radius), 
		m_hairX(hairX), m_hairY(hairY)
	{

	}

	void Draw() override; 


};
