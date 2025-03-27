#pragma once
#include "Person.h"

class Female : public Person
{


private:
	int m_hairX;
	int m_hairY; 

protected:

public:

	Female(int x = 0, int y = 0, int radius = 0, int hairX = 0, int hairY = 0) : Person(x, y, radius), 
		m_hairX(hairX), m_hairY(hairX)
	{

	}

	void Draw() override; 


};
