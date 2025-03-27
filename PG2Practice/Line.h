#pragma once
#include "Shape.h"

class Line :
    public Shape
{

private:

    Point2D m_endpoint; 

protected:

public:

    Line(const Point2D& point1, const Point2D& point2, const ConsoleColor& color); 

    void PlotLine(int x0, int y0, const int x1, const int y1) const;

    void Draw() const override;


    //Getter and setter

    const Point2D& GetEndpoint() const
    {
        return m_endpoint; 
    }

    void SetEndPoint(const Point2D& newEndpoint)
    {
        m_endpoint = newEndpoint; 
    }

    


};

