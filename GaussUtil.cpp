#include "GaussUtil.hpp"

using namespace std;

GaussUtil::GaussUtil(){}

void GaussUtil::countStandardGauss(double **matrix, int rowSize, int columnSize, int rowIndex, int columnIndex, int stepNumber)
{
    double* coefficients = countCoefficients(matrix, rowIndex, columnIndex, rowSize); 

    int coeIndex = 0;

    for(int i = rowIndex + 1; i < rowSize; i++)
    {
        modifyRow(matrix, coefficients[coeIndex], i, columnIndex + 1, columnSize, stepNumber);
        coeIndex++;
    }

    delete[] coefficients;

    if(stepNumber < rowSize - 1) 
    {
        countStandardGauss(matrix, rowSize, columnSize, rowIndex + 1, columnIndex + 1, stepNumber + 1);   
    }
}

void GaussUtil::countChooseInColumGauss(MatchematicalMatrix* matchematicalMatrix, double **matrix, int rowSize, int columnSize, int rowIndex, int columnIndex, int stepNumber)
{
    double* singleColumn = new double[rowSize - rowIndex];
    for(int i = 0; i < rowSize; i ++)
    {
        singleColumn[i] = matrix[i][columnIndex];
    }
    
    int index = indexOfMaxValue(singleColumn, rowSize - rowIndex);

    delete [] singleColumn;

    if(index != rowIndex)
    {
        matchematicalMatrix->exchangeRow(matrix, rowIndex, index);
    }

    double* coefficients = countCoefficients(matrix, rowIndex, columnIndex, rowSize); 

    int coeIndex = 0;

    for(int i = rowIndex + 1; i < rowSize; i++)
    {
        modifyRow(matrix, coefficients[coeIndex], i, columnIndex + 1, columnSize, stepNumber);
        coeIndex++;
    }

    delete[] coefficients;

    if(stepNumber < rowSize - 1) 
    {
    countChooseInColumGauss(matchematicalMatrix, matrix, rowSize, columnSize, rowIndex + 1, columnIndex + 1, stepNumber + 1);
    }
}

int GaussUtil::indexOfMaxValue(double* table, int tableSize)
{   
    int indexOfMaxValue = 0;
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] > table[indexOfMaxValue])
        {
            indexOfMaxValue = i;
        }
    }

    return indexOfMaxValue;
}

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
