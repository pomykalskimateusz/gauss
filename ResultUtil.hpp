#include <map>

using namespace std;

class ResultUtil
{
  public:
    ResultUtil();

    map<int, double> initialResultMap(int columnSize);
    
    map<int, double> calculateResult(map<int, double> resultMap, double** matrix, int rowSize, int columnSize);

    void printResultMap(map<int, double> resultMap, int* orderTable, int tableSize);
};