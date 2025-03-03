#include <iostream>
//TO BE COMPLETED
class Engine
{
    int ON;

    public:
    Engine () : ON(0) {}

    void start ()
    {
        if (!ON)
        {
            ON = 1;
            std::cout << "SWITCHED ON" << std::endl;
            return;
        }

        std::cout << "ALREADY ON" << std::endl;
    }

    void stop ()
    {
        if (ON)
        {
            ON = 0;
            std::cout << "SWITCHED OFF" << std::endl;
            return;
        }

        std::cout << "ALREADY OFF" << std::endl;
    }
};

class Wheels;
class Headlight;
class Steering;

class Car
{

};