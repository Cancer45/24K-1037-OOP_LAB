#include <iostream>

using namespace std;

int main ()
{
    int numOflines;
    cout << "Size of Lines Array: ";
    cin >> numOflines;
    
    cout << endl;
    float* height = new float [numOflines];
    
    //fill array (with line heights)
    for (int i = 0; i < numOflines; i++)
    {
        cout << "LINE NUMBER " << i + 1 << endl;
        cout << "Height: ";
        cin >> height[i];
    }
    
    float lowerHeight, width, max = 0;
    
    //find nums
    for (int i = 0; i < numOflines; i++)
    {
        for (int j = i + 1; j < numOflines; j++)
        {
            if (height[i] > height[j])
            lowerHeight = height[j];
            
            else
            lowerHeight = height[i];
            
            width = j - i;
            
            if (lowerHeight * width > max)
            max = lowerHeight * width;
        }
    }

    cout << endl << "Max Area b/w lines (container capacity) is " << max;
}
