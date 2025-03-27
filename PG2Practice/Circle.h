#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
private:

    int m_radius; 

protected:

public:

    //Constructor
    Circle(const int& radius, const Point2D& centerPoint, const ConsoleColor& color); 

    void DrawCirclePoints(int xc, int yc, int x, int y) const;

    void DrawCircle(int xc, int yc, int r) const; 
    
    void Draw() const; 

    //Getter and setter
    const int& GetRadius() const
    {
        return m_radius; 
    }

    void SetRadius(const int& radius)
    {
        m_radius = radius; 
    }


};

