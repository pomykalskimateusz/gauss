#include <string>
#include <iostream>

#include "MatchematicalMatrix.hpp"

using namespace std;

class GaussUtil
{
  public:
    GaussUtil();

    void countStandardGauss(double **matrix, int rowSize, int columnSize, int rowIndex, int columnIndex, int stepNumber);

    void countChooseInColumGauss(MatchematicalMatrix* matchematicalMatrix, double **matrix, int rowSize, int columnSize, int rowIndex, int columnIndex, int stepNumber);

  private:
    double* countCoefficients(double **matrix, int rowIndex, int columnIndex, int rowSize);
    
    void modifyRow(double** matrix, double coefficient, int startRowIndex, int startColumnIndex, int columnSize, int stepNumber);

    int indexOfMaxValue(double* table, int tableSize);

    void printTable(double* table, int size);
};
