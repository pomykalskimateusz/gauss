#include <iostream>
#include <map>

#include "GaussUtil.hpp"
#include "ResultUtil.hpp"

using namespace std;

int main()
{   
    int rowSize = 4;
    int columnSize = 5;

    int rowIndex = 0;
    int columnIndex = 0;

    int stepNumber = 1;

    MatchematicalMatrix* matchematicalMatrix = new MatchematicalMatrix();
    GaussUtil* gaussUtil = new GaussUtil();
    ResultUtil* resultUtil = new ResultUtil();
    CommonUtil* commonUtil = new CommonUtil();

    double **matrix = matchematicalMatrix->createMatrix(rowSize, columnSize);

    matchematicalMatrix->initializeMatrix(matrix, rowSize, columnSize);

    int* orderTable = new int[columnSize-1];

    for(int i = 0; i < columnSize - 1; i++)
    {
        orderTable[i] = i;
    }

    //gaussUtil->countChooseInRowGauss(commonUtil, matchematicalMatrix, orderTable, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
    //gaussUtil->countChooseInColumGauss(commonUtil, matchematicalMatrix, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
    //gaussUtil->countStandardGauss(matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
    
    gaussUtil->countAnyChooseGauss(commonUtil, matchematicalMatrix, orderTable, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);

    map<int, double> resultMap = resultUtil->initialResultMap(columnSize);

    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);

    resultUtil->printResultMap(resultMap, orderTable, columnSize - 1);

    delete [] orderTable;

    matchematicalMatrix->deleteMatrix(matrix, rowSize);

    return 0;
}
