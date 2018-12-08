#include <iostream>
#include <fstream>
#include <map>

#include "GaussUtil.hpp"
#include "ResultUtil.hpp"

using namespace std;

int main()
{   
                    double** A;
                    double* b;
                    unsigned matrix_size;
                    ifstream source_file("test.csv");
                    if (!source_file.is_open())
                    {
                        cout <<"The file has not been open!"<<endl;
                        return -1;
                    }
                    source_file >> matrix_size;
                    A = new double*[matrix_size];
                    A[0] = new double[matrix_size*matrix_size];
                    for(unsigned i = 1; i< matrix_size; i++)
                        A[i] = A[i-1] + matrix_size;
                    b = new double[matrix_size];
                    char semicolumn;
                    for (unsigned i = 0; i < matrix_size+1; i++)
                        source_file >> semicolumn;

                    for (unsigned i = 0; i < matrix_size; i++)
                    {
                        for (unsigned j = 0; j < matrix_size; j++)
                        {
                            source_file >> A[i][j];
                            source_file >> semicolumn;
                        }
                        source_file >> semicolumn;
                        source_file >> b[i];
                    }
                    source_file.close();


    MatchematicalMatrix* matchematicalMatrix = new MatchematicalMatrix();
    GaussUtil* gaussUtil = new GaussUtil();
    ResultUtil* resultUtil = new ResultUtil();
    CommonUtil* commonUtil = new CommonUtil();

    double** matrix;

    int rowSize = 0;
    int columnSize = 0;
    int rowIndex = 0;
    int columnIndex = 0;
    int stepNumber = 1;
    map<int, double> resultMap;
    int* orderTable;

    bool shouldReloadMatrix = false;

    int choice = -1;

    while(choice != 6)
    {
        commonUtil->printMenu();
        cin >> choice;

        switch(choice)
        {
            case 1:
                rowSize = matrix_size;
                columnSize = matrix_size + 1;
                rowIndex = 0;
                columnIndex = 0;
                stepNumber = 1;
                orderTable = new int[columnSize-1];
                shouldReloadMatrix = false;
                for(int i = 0; i < columnSize - 1; i++)
                {
                    orderTable[i] = i;
                }
                matrix = matchematicalMatrix->constructMatrix(A, b, matrix_size);
                cout << "Macierz wczytana poprawnie " << endl;
            break;

            case 2:
                if(!shouldReloadMatrix)
                {
                    gaussUtil->countStandardGauss(matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
                    
                    resultMap = resultUtil->initialResultMap(columnSize);
                    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);
                    resultUtil->printResultMap(resultMap, orderTable, columnSize - 1);

                    shouldReloadMatrix = true;
                }
                else 
                    cout << "Nie wczytałeś macierzy, wybierz opcje 1 w menu" << endl;
            break;

            case 3: 
                if(!shouldReloadMatrix)
                {
                    gaussUtil->countChooseInRowGauss(commonUtil, matchematicalMatrix, orderTable, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
                    
                    resultMap = resultUtil->initialResultMap(columnSize);
                    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);
                    resultUtil->printResultMap(resultMap, orderTable, columnSize - 1);

                    shouldReloadMatrix = true;
                }
                else 
                    cout << "Nie wczytałeś macierzy, wybierz opcje 1 w menu" << endl;
            break;

            case 4:
                if(!shouldReloadMatrix)
                {
                    gaussUtil->countChooseInColumGauss(commonUtil, matchematicalMatrix, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
                
                    resultMap = resultUtil->initialResultMap(columnSize);
                    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);
                    resultUtil->printResultMap(resultMap, orderTable, columnSize - 1);

                    shouldReloadMatrix = true;
                }
                else 
                    cout << "Nie wczytałeś macierzy, wybierz opcje 1 w menu" << endl;
            break;

            case 5:
                if(!shouldReloadMatrix)
                {
                    gaussUtil->countAnyChooseGauss(commonUtil, matchematicalMatrix, orderTable, matrix, rowSize, columnSize, rowIndex, columnIndex, stepNumber);
                    
                    resultMap = resultUtil->initialResultMap(columnSize);
                    resultMap = resultUtil->calculateResult(resultMap, matrix, rowSize, columnSize);
                    resultUtil->printResultMap(resultMap, orderTable, columnSize - 1);

                    shouldReloadMatrix = true;
                }
                else 
                    cout << "Nie wczytałeś macierzy, wybierz opcje 1 w menu" << endl;
            break;

            case 6:
                choice = 6;
                // matchematicalMatrix->deleteMatrix(A, matrix_size);  
                delete A;
                matchematicalMatrix->deleteMatrix(matrix, matrix_size);
                delete [] orderTable;
                delete [] b;
            break;
        }
    }

    return 0;
}
