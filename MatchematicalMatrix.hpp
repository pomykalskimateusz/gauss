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
};
