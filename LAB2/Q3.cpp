#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void matrixSums (int rows, int cols, int** matrix) //matrix sums function
{
    int rowSum, sum = 0;
    int maxRowSum = 0, maxColSum = 0, maxRowIndex, maxColIndex;

    int* colSums = new int [cols];

    //init colSums array
    for (int i = 0; i < cols; i++)
    colSums[i] = 0;

    //calc and print sums
    for (int i = 0; i < rows; i++) 
    {
        rowSum = 0;

        for (int j = 0; j < cols; j++)
        {
            rowSum += matrix[i][j];
            colSums[j] += matrix[i][j];
        }

        sum += rowSum;

        if (rowSum > maxRowSum)
        {
            maxRowSum = rowSum;
            maxRowIndex = i;
        }
        

        //print row sums
        cout << "Row Sum " << i + 1 << ": " << rowSum << endl;
    }

    //print col sums
    for (int i = 0; i < cols; i++)
    {
        cout << "Column Sum " << i + 1 << ": " << colSums[i] << endl;
        
        if (colSums[i] > maxColSum)
        {
            maxColSum = colSums[i];
            maxColIndex = i;
        }
    }

    //print max row
    cout << "Max Sum Row: ";

    for (int i = 0; i < cols; i++)
    cout << matrix[maxRowIndex][i] << " ";

    cout << endl;

    //print max row
    cout << "Max Sum Column: ";

    for (int i = 0; i < rows; i++)
    cout << matrix[i][maxColIndex] << " ";

    cout << endl;

    cout << "Sum: " << sum << endl;
}

void matrixTransposed (int rows, int cols, int** matrix)
{
    int** matrixTransp = new int* [cols];

    for (int i = 0; i < cols; i++)
    matrixTransp[i] = new int [rows];

    //transpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrixTransp [j][i] = matrix[i][j];
        }
    }

    //print normal
    cout << endl << "Normal: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;

    //print transposed
    cout << "Transposed: " << endl;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << matrixTransp[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    delete[] matrixTransp[i];

    delete[] matrixTransp;
}

int main ()
{
    int rows, cols;

    cout << "Rows: ";
    cin >> rows;
    cout << "columns: ";
    cin >> cols;

    //declare and allocate to matrix
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++)
    matrix[i] = new int [cols];

    //fill with random nums 1 to 100
    srand(time(0)); //seed

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = (rand() % 100) + 1;
        }
    }

    //print stuff
    matrixSums(rows, cols, matrix);
    matrixTransposed(rows, cols, matrix);

    for (int i = 0; i < rows; i++)
    delete[] matrix[i];

    delete[] matrix;
}
