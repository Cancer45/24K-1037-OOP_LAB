#include <iostream>

class Position
{
    public:
    float X, Y;
};

class Shape
{
    protected:
    Position position;
    std::string color;
    float borderThickness;

    public:
    Shape () {}
    Shape (float X, float Y, std::string color, float borderThickness) : color(color), borderThickness(borderThickness) 
    {
        position.X = X;
        position.Y = Y;
    }    

    void draw ()
    {
        std::cout << "drawing shape" << std::endl;
    }

    void calculateArea ()
    {
        std::cout << "calculating shape area" << std::endl;
    }

    void calculatePerimeter ()
    {
        std::cout << "calculating perimeter" << std::endl;
    }
};

class Circle : public Shape
{
    float Radius;

};

class Rectangle : public Shape
{

};

class Triangle : public Shape
{

};

class Polygon : public Shape
{
    
};
