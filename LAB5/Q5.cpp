#include <iostream>
//TO BE COMPLETED

class Wheels //AGGREGATE THIS
{
    int TURN;

    public:
    Wheels () : TURN(0) {}

    void turn ()
    {
        if (!TURN)
        {
            TURN = 1;
            std::cout << "WHEELS TURNING" << std::endl;
            return;
        }

        std::cout << "WHEELS ALREADY TURNING" << std::endl;
    }

    void stop ()
    {
        if (TURN)
        {
            TURN = 0;
            std::cout << "WHEELS STOPPED" << std::endl;
            return;
        }

        std::cout << "WHEELS ALREADY STOPPED" << std::endl;
    }
};

class Headlight //AGGREGATE THIS
{
    int ON;

    public:
    Headlight () : ON(0) {}

    void switchON ()
    {
        if (!ON)
        {
            ON = 1;
            std::cout << "HEADLIGHTS SWITCHED ON" << std::endl;
            return;
        }

        std::cout << "HEADLIGHTS ALREADY ON" << std::endl;
    }

    void switchOFF ()
    {
        if (ON)
        {
            ON = 0;
            std::cout << "HEADLIGHTS SWITCHED OFF" << std::endl;
            return;
        }

        std::cout << "HEADLIGHTS ALREADY OFF" << std::endl;
    }
};

class Engine //COMPOSE THIS
{
    int ON;

    public:
    Engine () : ON(0) {}

    void start ()
    {
        if (!ON)
        {
            ON = 1;
            std::cout << "ENGINE SWITCHED ON" << std::endl;
            return;
        }

        std::cout << "ENGINE ALREADY ON" << std::endl;
    }

    void stop ()
    {
        if (ON)
        {
            ON = 0;
            std::cout << "ENGINE SWITCHED OFF" << std::endl;
            return;
        }

        std::cout << "ENGINE ALREADY OFF" << std::endl;
    }
};

class Steering //COMPOSE THIS
{
    int TURN;

    public:
    Steering () : TURN(0) {}

    void turn ()
    {
        if (!TURN)
        {
            TURN = 1;
            std::cout << "TURNING" << std::endl;
            return;
        }

        std::cout << "ALREADY TURNING" << std::endl;
    }

    void reset ()
    {
        if (TURN)
        {
            TURN = 0;
            std::cout << "RESET" << std::endl;
            return;
        }

        std::cout << "ALREADY RESET" << std::endl;
    }
};

class Car
{
    Engine engine();
    Steering steering();
    Headlight* headlight();
    Wheels* wheels ();

    public:
    Car (Headlight* headlight, Wheels* wheels) : headlight(headlight), wheels(wheels) {}

    //TO BE COMPLETED
};
