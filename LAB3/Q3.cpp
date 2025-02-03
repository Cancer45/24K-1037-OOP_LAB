#include <iostream>

using namespace std;

class Serial
{
    private:
    static int totalInstance;
    int myInstance;

    public:
    //constructors
    Serial ()
    {
        ++totalInstance;
        myInstance = totalInstance;
    }

    ~Serial ()
    {
        --totalInstance;
        myInstance = totalInstance;
    }

    //method
    void myNumber ()
    {
        cout << "I am OBJECT " << myInstance << endl;
    }
};
int Serial::totalInstance = 0;
int main ()
{
    Serial* obj = new Serial [3];

    for (int i = 0; i < 3; i++)
    Serial obj[i];

    for (int i = 0; i < 3; i++)
    obj[i].myNumber();
}