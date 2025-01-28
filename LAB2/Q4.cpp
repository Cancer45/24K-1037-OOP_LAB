#include <iostream>

using namespace std;

void printArray (int* array, int size)
{
    for (int i = 0; i < size; i++)
    cout << array[i] << " ";
    
    cout << endl;
}

int unique (int* array, int size)
{
    int* tmp = new int [size];
    
    tmp[0] = array[0];
    int tmpElements = 1;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < tmpElements; j++)
        {
            if (tmp[j] == array[i])
            break;
            
            if (j == (tmpElements - 1))
            {
                tmp[tmpElements] = array[i];
                tmpElements++;
            }
        }
    }
    
    //override
    for (int i = 0; i < size; i++)
    {
        if (i < tmpElements)
        {
            array[i] = tmp[i];
            continue;
        }
    }
    
    delete [] tmp;

    return tmpElements;
}

int main()
{
    int n, newSize;
    cout << "Number of Inputs: ";
    cin >> n;
    
    int* numArray = new int [n];
    
    //take input
    for (int i = 0; i < n ; i++)
    {
        cout << "Number " << i + 1 << ": ";
        cin >> numArray[i];
    }
    
    //before unique
    printArray(numArray, n);
    
    newSize = unique(numArray, n);
    
    //after unique
    printArray(numArray, newSize);
    
    delete [] numArray;
}
