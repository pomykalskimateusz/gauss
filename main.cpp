#include <iostream>
#include <map>

#include "MatchematicalMatrix.hpp"
#include "GaussUtil.hpp"
#include "ResultUtil.hpp"

using namespace std;

void countMatrix(GaussUtil* gaussUtil, double **matrix, int rowSize, int columnSize, int rowIndex, int columnIndex, int stepNumber)
{
    double* coefficients = gaussUtil->countCoefficients(matrix, rowIndex, columnIndex, rowSize); 

    int coeIndex = 0;

    for(int i = rowIndex + 1; i < rowSize; i++)
    {
        gaussUtil->modifyRow(matrix, coefficients[coeIndex], i, columnIndex + 1, columnSize, stepNumber);
        coeIndex++;
    }

    delete[] coefficients;

    if(stepNumber < rowSize - 1) 
    {
        countMatrix(gaussUtil, matrix, rowSize, columnSize, rowIndex + 1, columnIndex + 1, stepNumber + 1);   
    }
}

int main()
{   
    int rowSize = 3;
    int columnSize = 4;

    int rowIndex = 0;
    int columnIndex = 0;

    int stepNumber = 1;

    MatchematicalMatrix* matchematicalMatrix = new MatchematicalMatrix();
    GaussUtil* gaussUtil = new GaussUtil();
    ResultUtil* resultUtil = new ResultUtil();

    double **matrix = matchematicalMatrix->createMatrix(rowSize, columnSize);

    matchematicalMatrix->initializeMatrix(matrix, rowSize, columnSize);
 
    countMatrix(gaussUtil, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);

    matchematicalMatrix->printMatrix(matrix, rowSize, columnSize);

    map<int, double> resultMap = resultUtil->initialResultMap(columnSize);

    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);
    
    resultUtil->printResultMap(resultMap);

    matchematicalMatrix->deleteMatrix(matrix, rowSize);

    return 0;
}
