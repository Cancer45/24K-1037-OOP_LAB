#include <iostream>

int absoluteValue (int n)
{
    if (n < 0)
    return n * -1;

    return n;
}

using namespace std;
int main ()
{
    int numOfnum;
    cout << "Number of Inputs: ";
    cin >> numOfnum;

    float* numArray = new float [numOfnum];

    //get inputs
    for (int i = 0; i < numOfnum; i++)
    {
        cout << "Number " << i + 1 << ": ";
        cin >> numArray [i];
    }

    float avg = 0, diff, closest;

    //calculate average
    for (int i = 0; i < numOfnum; i++)
    avg += numArray [i];

    avg /= numOfnum; 

    cout << "Average: " << avg << endl;

    //find num closest to avg
    closest = numArray [0];
    diff = absoluteValue(avg - numArray [0]);

    for (int i = 1; i < numOfnum; i++)
    {
        if (absoluteValue(avg - numArray [i]) < diff)
        {
            closest = numArray [i];
            diff = absoluteValue(avg - numArray [i]);
        }
    }

    cout << "Closest: " << closest << endl;
}

