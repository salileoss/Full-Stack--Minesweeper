#include <MineSweeper.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

//Init the board, 0 means empty cell, 1 means there's a mine, 2 means theres' a flag
Minesweeper::Minesweeper(int row, int col, int numOfMine)
{
    this->row = row;
    this->col = col;
    this->numOfMine = numOfMine;
    init(row, col, numOfMine);
}

void Minesweeper::init(int row, int col, int numOfMine)
{
    terminateState = false;
    std::vector<std::vector<int>> temp(row, std::vector<int>(col, 0));
    std::vector<std::vector<int>> adjtemp(row, std::vector<int>(col, 0));
    adjNum = adjtemp;

    int count = 0;
    while (count < numOfMine)
    {
        int randRow = rand() % temp.size();
        int randCol = rand() % temp[0].size();
        if (temp[randRow][randCol] == 1)
        { //already has a mine here, skip this iter
            continue;
        }
        else
        {
            temp[randRow][randCol] = 1;
            count++;
        }
    }
    board = temp;
    for (auto i : board)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    //Generate adjacent table
    int rLimit = board.size();
    for (int row = 0; row < rLimit; row++)
    {
        int cLimit = board[row].size();
        for (int col = 0; col < cLimit; col++)
        {
            int counter = 0;
            //check at most 8 neighbor cells given any cell
            for (int i = std::max(0, row - 1); i <= std::min(row + 1, rLimit - 1); i++)
            {
                for (int j = std::max(0, col - 1); j <= std::min(col + 1, cLimit - 1); j++)
                {
                    if (i != row || j != col)
                    {
                        //count how many live neighbor cells given cell has
                        if (board[i][j] == 1)
                        {
                            counter++;
                        }
                    }
                }
            }
            adjNum[row][col] = counter;
            counter = 0;
        }
    }
    //Make the cell that is a mine marked 9 in adjacent table to distinguish
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 1){
                adjNum[i][j] = 9;
            }
        }
    }

    std::cout << std::endl;

    for (auto i : adjNum)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

ucm::json Minesweeper::getBoard()
{
    ucm::json result;
    for (int row = 0; row < adjNum.size(); row++)
    {
        std::vector<int> temp = adjNum[row];
        std::vector<int> temprow;
        for (int col = 0; col < temp.size(); col++)
        {
            temprow.push_back(temp[col]);
        }
        result.push_back(temprow);
    }
    return result;
}

void Minesweeper::reset()
{
    init(this->row, this->col, this->numOfMine);
}

void Minesweeper::handle(int x, int y, MouseButton btn)
{
    if (btn = left)
    {
        reveal(x, y);
    }
}

void Minesweeper::reveal(int x, int y)
{
    if (board[x][y] == 1)
    {
        terminateState = true;
    }
}

void Minesweeper::expand(int x, int y)
{
}

Minesweeper::~Minesweeper() {}
