#include <iostream>

using namespace std;

int main ()
{
    int numOfnums, target;
    cout << "Size of Number Array: ";
    cin >> numOfnums;
    int* numbers = new int [numOfnums];
    
    //fill array
    for (int i = 0; i < numOfnums; i++)
    {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }
    
    //get target
    cout << "Target: ";
    cin >> target;
    
    //find nums
    for (int i = 0; i < numOfnums; i++)
    {
        for (int j = 0; j < numOfnums; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                 cout << endl << "[" << i << ", " << j << "]" << endl;
                 return 0;
            }
           
        }
        
    }
}
