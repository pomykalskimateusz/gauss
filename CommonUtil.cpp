#include "CommonUtil.hpp"

using namespace std;

CommonUtil::CommonUtil() {}

void CommonUtil::printTable(double* table, int size)
{
    for(int i=0; i < size; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}

int CommonUtil::indexOfMaxValue(double* table, int tableSize)
{   
    int indexOfMaxValue = 0;
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] > table[indexOfMaxValue])
        {
            indexOfMaxValue = i;
        }
    }

    return indexOfMaxValue;
}
