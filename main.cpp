#include <iostream>
#include <map>

#include "GaussUtil.hpp"
#include "ResultUtil.hpp"

using namespace std;

void orderAsc(MatchematicalMatrix* matchematicalMatrix, int* orderTable, int tableSize, double** matrix, int rowSize)
{
    int value = orderTable[0];
    int valueIndex = 0;

    for(int i = 0; i < tableSize - 1; i++)
    {
        if(value > orderTable[i]) 
        {
            matchematicalMatrix->exchangeColumn(orderTable, matrix, valueIndex, i, rowSize);
            value = orderTable[i];
            valueIndex = i;
        }
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
    CommonUtil* commonUtil = new CommonUtil();

    double **matrix = matchematicalMatrix->createMatrix(rowSize, columnSize);

    matchematicalMatrix->initializeMatrix(matrix, rowSize, columnSize);

    matchematicalMatrix->printMatrix(matrix, rowSize, columnSize);
    cout << endl; 
    int* orderTable = new int[columnSize-1];

    for(int i = 0; i < columnSize - 1; i++)
    {
        orderTable[i] = i;
    }

    //gaussUtil->countChooseInRowGauss(commonUtil, matchematicalMatrix, orderTable, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
    //gaussUtil->countChooseInColumGauss(commonUtil, matchematicalMatrix, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
    gaussUtil->countStandardGauss(matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);

    orderAsc(matchematicalMatrix, orderTable, columnSize - 1, matrix, rowSize);

    matchematicalMatrix->printMatrix(matrix, rowSize, columnSize);

    map<int, double> resultMap = resultUtil->initialResultMap(columnSize);

    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);

    resultUtil->printResultMap(resultMap);

    delete [] orderTable;

    matchematicalMatrix->deleteMatrix(matrix, rowSize);

    return 0;
}
