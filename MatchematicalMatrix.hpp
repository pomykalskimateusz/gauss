#include <string>
#include <iostream>

using namespace std;

class MatchematicalMatrix
{
  public:
    MatchematicalMatrix();
    
    double** createMatrix(int rowSize, int columnSize);

    void deleteMatrix(double** matrix, int rowSize);

    void initializeMatrix(double** matrix, int rowSize, int columnSize);

    void printMatrix(double** matrix, int rowSize, int columnSize);

    void exchangeRow(double** matrix, int firstRow, int secondRow);

    void exchangeColumn(int* orderTable, double** matrix, int firstColumn, int secondColumn, int rowSize);
};
