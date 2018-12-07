#include <string>
#include <iostream>

using namespace std;

class GaussUtil
{
  public:
    GaussUtil();

    double* countCoefficients(double **matrix, int rowIndex, int columnIndex, int rowSize);

    void modifyRow(double** matrix, double coefficient, int startRowIndex, int startColumnIndex, int columnSize, int stepNumber);

    void printTable(double* table, int size);
};
