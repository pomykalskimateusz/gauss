#include "ResultUtil.hpp"
#include <iostream>

using namespace std;

ResultUtil::ResultUtil() {}

map<int, double> ResultUtil::initialResultMap(int columnSize)
{
    map<int, double> resultMap;

    for(int i = columnSize - 1; i > 0; i--)
    {
        resultMap.insert(make_pair(i, 0));
    }

    return resultMap;
}

map<int, double> ResultUtil::calculateResult(map<int, double> resultMap, double** matrix, int rowSize, int columnSize)
{
    int key = columnSize;
    double searchedValue;

    for(int i = rowSize-1; i >= 0; i--)
    {
        searchedValue = 0;
        key = key - 1;

        for(int j = columnSize - 1; j >= 0; j--) 
        {
            if((j + 1) != key)
            {
                if(j == columnSize - 1)
                {
                    searchedValue = searchedValue + matrix[i][columnSize - 1];
                }
                else 
                {
                    searchedValue = searchedValue - matrix[i][j]*resultMap[j+1];
                }
            }
        }
        resultMap[key] = searchedValue/matrix[i][key-1];
    }

    return resultMap;
}

void ResultUtil::printResultMap(map<int, double> resultMap)
{
    cout << "Result : " << endl;

    for (map<int, double>::iterator it = resultMap.begin(); it != resultMap.end(); ++it)
    {
        cout << "x" << it->first << " = " << it->second << endl;
    }
}