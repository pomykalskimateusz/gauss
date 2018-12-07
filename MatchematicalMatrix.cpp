#include "MatchematicalMatrix.hpp"

using namespace std;

MatchematicalMatrix::MatchematicalMatrix(){}

double** MatchematicalMatrix::createMatrix(int rowSize, int columnSize)
{
	double** matrix = new double *[rowSize];

    for(int i = 0; i < rowSize; i++)
    {
        matrix[i] = new double[columnSize];
    }

	return matrix;
}

void MatchematicalMatrix::deleteMatrix(double** matrix, int rowSize)
{
	for(int i = 0; i < rowSize; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void MatchematicalMatrix::initializeMatrix(double** matrix, int rowSize, int columnSize)
{
	matrix[0][0] = 3;
	matrix[0][1] = -1;
	matrix[0][2] = -1;
	matrix[0][3] = 4; 

	matrix[1][0] = -1;
	matrix[1][1] = 2;
	matrix[1][2] = 1;
	matrix[1][3] = -1;

	matrix[2][0] = 1;
	matrix[2][1] = -3;
	matrix[2][2] = -2;
	matrix[2][3] = -1;


}

void MatchematicalMatrix::printMatrix(double** matrix, int rowSize, int columnSize)
{
	for(int i = 0; i < rowSize; i++)
	{
		for(int j = 0; j < columnSize; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

void MatchematicalMatrix::exchangeRow(double** matrix, int firstRow, int secondRow)
{
	swap(matrix[firstRow], matrix[secondRow]);
}

void MatchematicalMatrix::exchangeColumn(int* orderTable, double** matrix, int firstColumn, int secondColumn, int rowSize)
{
	for(int i = 0; i < rowSize; i++)
	{
		swap(matrix[i][firstColumn], matrix[i][secondColumn]);
	}

	swap(orderTable[firstColumn], orderTable[secondColumn]);
}