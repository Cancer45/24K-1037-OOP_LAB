#include <iostream>

using namespace std;

struct namespace
{
    float x, y;
} line;
int main ()
{
    int numOflines, max = 0;
    cout << "Size of Lines Array: ";
    cin >> numOflines;
    line* lines = new line [numOflines];
    
    //fill array (with line heights)
    for (int i = 0; i < numOflines; i++)
    {
        cout << "LINE NUMBER " << i + 1 << endl;
        cout << "Height: ";
        cin >> lines.y[i];
        cout << "Position: ";
        cin >> lines.x[i];
    }
    
    float lowerHeight;
    
    //find nums
    for (int i = 0; i < numOflines; i++)
    {
        for (int j = 0; j < numOflines; j++)
        {
            if (lines.y[i] > lines.y[j])
            lowerHeight = lines.y[j];
            
            else
            lowerHeight = lines.y[i];l
        }
    }
    //toComplete
}
