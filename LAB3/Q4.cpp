#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>

using namespace std;

class Angle
{
    int degrees;
    float minutes;
    char direction; 

    public:
    //constructor
    Angle (int deg, float mins, char dir) : degrees(deg), minutes(mins), direction(dir) {}

    //method 1
    void inputValues ()
    {
         do
        {
            cout << "Direction ('N', 'S', 'E', or 'W'): ";
            cin >> direction;
            direction = toupper(direction);
        } while (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W');

        do
        {
            cout << "Degrees: ";
            cin >> degrees;
        } while (((direction == 'N' || direction == 'S') && (degrees < 0 || degrees > 90)) || ((direction == 'E' || direction == 'W') && (degrees < 0 || degrees > 180)));
        
        do
        {
            cout << "Minutes: ";
            cin >> minutes;
        } while (minutes < 0 || minutes > 60);
    }

    //method 2
    void display ()
    {
        cout << degrees << '\xF8' << fixed << setprecision(1) << minutes << endl;
    }
};

int main ()
{
    Angle angle (0, 0, 'N');
    char tmp;
    
    while (1)
    {
        angle.inputValues();
        angle.display();

        cout << "continue? 'Esc' to exit." << endl;
        tmp = _getch();

        if (tmp == 27)
        return 0;
    } 
}