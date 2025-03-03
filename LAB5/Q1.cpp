#include <iostream>

class Square
{
    float sideLength, area;
    static float allAreas;

    public:
    //default constructor
    Square () {}

    //parameterized constructor
    Square (float sideLength) : sideLength(sideLength) {}
    
    //method 1
    void addArea ()
    {
        area = sideLength * sideLength;

        allAreas += area;
    }

    float getSide ()
    {
        return sideLength;
    }

    float getArea ()
    {
        return area;
    }

    float getAllAreas ()
    {
        return allAreas;
    }

    void setSide (float sideLength)
    {
        this -> sideLength = sideLength;
    }
};

float Square::allAreas = 0;

int main ()
{
    Square sq1(3.7), sq2(2.5), sq3(11.1);

    sq1.addArea();
    std::cout << "Area: " << sq1.getArea() << " | All Areas: " << sq1.getAllAreas() << std::endl;
    
    sq2.addArea();
    std::cout << "Area: " << sq2.getArea() << " | All Areas: " << sq2.getAllAreas() << std::endl;
    
    sq3.addArea();
    std::cout << "Area: " << sq3.getArea() << " | All Areas: " << sq3.getAllAreas() << std::endl;

}