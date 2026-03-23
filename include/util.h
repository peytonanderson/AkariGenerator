#include <vector>
#include "cell.h"

using namespace std;

class Util {
    public:
        static vector<vector<Cell>> placeBulb(vector<vector<Cell>> board, int x, int y);

        static int countNearbyBulbs(vector<vector<Cell>> board, int x, int y);

        static int countTotalOpenCells(vector<vector<Cell>> board);

        static void printPuzzle(vector<vector<Cell>> board);
};