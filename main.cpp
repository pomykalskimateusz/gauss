#include <iostream>
#include <map>

#include "GaussUtil.hpp"
#include "ResultUtil.hpp"
#include "CommonUtil.hpp"

using namespace std;

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
   
    gaussUtil->countChooseInColumGauss(commonUtil, matchematicalMatrix, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
   
    matchematicalMatrix->printMatrix(matrix, rowSize, columnSize);

    map<int, double> resultMap = resultUtil->initialResultMap(columnSize);

    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);

    resultUtil->printResultMap(resultMap);

    matchematicalMatrix->deleteMatrix(matrix, rowSize);

    return 0;
}
