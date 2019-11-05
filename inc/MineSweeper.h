#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <vector>
#include <stdlib.h>
#include <BoardGame.h>
class Minesweeper : public BoardGame
{
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> adjNum;
    int row;
    int col;
    int numOfMine;
    bool terminateState;

public:
    Minesweeper(int, int, int);
    ~Minesweeper();
    void init(int, int, int);
    void reset();
    void handle(int, int, MouseButton = left);
    void reveal(int, int);
    void flag(int, int);
    void expand(int, int);
    ucm::json getBoard();
};

#endif
