#include <iostream>

class Position
{
    public:
    float X, Y;
};

class Shape
{
    Position position;
    std::string color;
    float borderThickness;    
}