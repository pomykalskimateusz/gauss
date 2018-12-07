#include "GaussUtil.hpp"

using namespace std;

GaussUtil::GaussUtil(){}

double* GaussUtil::countCoefficients(double **matrix, int rowIndex, int columnIndex, int rowSize)
{
    int coefficientsSize = rowSize - (rowIndex + 1);

    double *coefficientsTab = new double[coefficientsSize];

    int coefficientsIndex = rowIndex + 1;

    for(int i = 0; i < coefficientsSize; i++)
    {
        coefficientsTab[i] = matrix[coefficientsIndex][columnIndex]/matrix[rowIndex][columnIndex];

        coefficientsIndex++;
    }

    for(int i = rowIndex+1; i < rowSize; i++)
    {
        matrix[i][columnIndex] = 0;
    }

    return coefficientsTab;
}

void GaussUtil::modifyRow(double** matrix, double coefficient, int startRowIndex, int startColumnIndex, int columnSize, int stepNumber)
{
    for(int i = startColumnIndex; i < columnSize; i++)
    {
        matrix[startRowIndex][i] =  matrix[startRowIndex][i] - coefficient*matrix[stepNumber-1][i];
    }
}


void GaussUtil::printTable(double* table, int size)
{
    for(int i=0; i < size; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}
