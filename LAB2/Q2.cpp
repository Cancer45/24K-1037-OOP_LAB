#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void printRvrsStr (string toReverse)
{
    int strLength = toReverse.length();
    string tmp(strLength, '\0');
    char* getFrom = &toReverse[strLength - 1]; 

    //reverse
    for (int i = 0; i < strLength; i++)
    {
        tmp[i] = *getFrom;
        getFrom--;
    }

    //print
    cout << tmp;
}

int isVowel (char lett)
{
    char vowels [5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++)
    {
        if (lett == vowels [i])
        return 1;
    }

    return 0;
}

int main ()
{
    int numOfStr;
    cout << "Number of Strings: ";
    cin >> numOfStr;

    string* strArray = new string [numOfStr];
    fflush(stdout);

    //get inputs
    for (int i = 0; i < numOfStr; i++)
    {
        cout << "String " << i + 1 << ": ";
        cin >> strArray[i];
    }

    //print reverse
    for (int i = 0; i < numOfStr; i++)
    {
        cout << "Reversed " << i + 1 << ": ";
        printRvrsStr(strArray[i]);
        cout << endl;
    }
    
    //find most vowels str
    int strIndex, numVowels, maxVowels = 0;

    for (int i = 0; i < numOfStr; i++)
    {
        numVowels = 0;

        for (int j = 0; j < strArray[i].length(); j++)
        {
            if (isVowel(strArray[i][j]))
            numVowels++;
        }

        if (numVowels > maxVowels)
        maxVowels = numVowels;
        strIndex = i;
    }

    //print most vowels str
    cout << "Most Vowels: " << strArray[strIndex] << endl;

    //print avg length of all
    int sizeSum = 0;

    for (int i = 0; i < numOfStr; i++)
    {
        sizeSum += strArray[i].length();
    }

    cout << "Average Length: " << sizeSum / numOfStr << endl;
}