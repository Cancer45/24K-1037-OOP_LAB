#include <iostream>
#include <conio.h>

using namespace std;

class tollBooth
{
    unsigned int carsPassed;
    double collected;

    public:
    //constructor
    tollBooth () : collected(0), carsPassed(0) {}

    //method 1
    void payingCar ()
    {
        collected += 0.5;
        carsPassed++;
    }

    //method 2
    void noPayCar ()
    {
        carsPassed++;
    }

    //method 3
    void display ()
    {
        cout << endl << "Cars Passed: " << carsPassed << endl;
        cout << "Total Collected: " << collected << endl;
    }
};

int main ()
{
    tollBooth booth;
    char input;

    cout << "Press 'c' to record a collection. Press 'p' to record a car passed." << endl;

    while (1)
    {
        input = _getch();
        
        switch (input)
        {
            case 'c':    
            booth.payingCar();
            cout << "COLLECTED" << endl;
            break;

        case 'p':
            booth.noPayCar();
            cout << "PASSED" << endl;
            break;

        case 27:
            booth.display();
            return 0;
        }

    }

}