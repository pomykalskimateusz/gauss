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

void CommonUtil::printMenu()
{
    cout << "****** MENU ******" << endl;

    cout << "1 - WCZYTAJ DANE Z PLIKU" << endl;
    cout << "2 - METODA ELIMINACJI GAUSSA BEZ WYBORU ELEMENTU" << endl;
    cout << "3 - METODA ELIMINACJI GAUSSA Z WYBOREM ELEMENTU W WIERSZACH" << endl;
    cout << "4 - METODA ELIMINACJI GAUSSA Z WYBOREM ELEMENTU W KOLUMNACH" << endl;
    cout << "5 - METODA ELIMINACJI GAUSSA Z PELNEMY WYBOREM ELEMENTU" << endl;
    cout << "6 - WYJSCIE Z PROGRAMU" << endl;

    cout << "TWOJ WYBOR : ";
}
