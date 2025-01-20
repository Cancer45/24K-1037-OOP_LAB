#include <iostream>

using namespace std;

int main ()
{
    int checkPrime;

    cout << "Input Number: ";
    cin >> checkPrime;
    
    for (int i = 2; i < checkPrime; i++)
    {
        if (checkPrime % i == 0)
        {
            cout << "NOT PRIME" << endl;
            return 0;    
        }
        
    }

    cout << "PRIME" << endl;
    return 0;
}