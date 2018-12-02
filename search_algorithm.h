#ifndef SEARCH_ALGORITHM_H
#define SEARCH_ALGORITHM_H
#include <vector>
#include <stack>
#include "direction.h"

class Block;
class GameControl;

class Search_algorithm
{
public:
    Search_algorithm(GameControl* game);
    void BFS(std::vector<std::vector<Block*>> *board, int i, int j, int x, int y);

private :
    // queue node used in BFS
    struct Node
    {
        // (x, y) represents matrix cell coordinates
        // dist represent its minimum distance from the source
        int x, y, dist;
    };

    // Below arrays details all 4 possible movements from a cell
    int row[4] = { -1, 1, 0, 0 };
    int col[4] = { 0, 0, -1, 1 };

    static const int MAX_ROW = 20;
    static const int MAX_COL = 20;

    GameControl* game;

    bool isValid(std::vector<std::vector<Block*>> *board, bool visited[MAX_ROW][MAX_COL], int row, int col);
    std::vector<int> checkEndPoint(std::vector<std::vector<Block*>> *board, int curRow, int curCol);
    std::vector<int> checkEndPoint(std::vector<std::vector<Block*>> *board, int curRow, int curCol, DIRECTION dir);
    bool findStp(std::vector<std::vector<int>> choice,int n, int endRow, int endCol ,std::stack<std::vector<int>> &stp, std::vector<std::vector<Block*>> *board);
};

#endif // SEARCH_ALGORITHM_H
