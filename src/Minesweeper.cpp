#include <MineSweeper.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>

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
    std::vector<std::vector<Cell>> temp(row, std::vector<Cell>(col, Cell()));
    // std::vector<std::vector<int>> adjtemp(row, std::vector<int>(col, 0));
    // adjNum = adjtemp;

    int count = 0;
    while (count < numOfMine)
    {
        int randRow = rand() % temp.size();
        int randCol = rand() % temp[0].size();
        if (temp[randRow][randCol].isBomb())
        { //already has a mine here, skip this iter
            continue;
        }
        else
        {
            temp[randRow][randCol].setBomb();
            count++;
        }
    }
    board = temp;

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
                        //count how many bomb neighbor cells given cell has
                        if (board[i][j].isBomb())
                        {
                            counter++;
                        }
                    }
                }
            }
            if (!board[row][col].isBomb())
            {
                board[row][col].setAdjNum(counter);
                if (board[row][col].getAdjNum() != 0)
                {
                    board[row][col].setAdjState();
                }
            }
            counter = 0;
        }
    }
    for (auto i : board)
    {
        for (auto j : i)
        {
            std::cout << j.checkState() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (auto i : board)
    {
        for (auto j : i)
        {
            std::cout << j.getAdjNum() << " ";
        }
        std::cout << std::endl;
    }
}

ucm::json Minesweeper::getBoard()
{
    ucm::json result;
    for (int row = 0; row < board.size(); row++)
    {
        std::vector<Cell> temp = board[row];
        std::vector<std::string> temprow;
        for (int col = 0; col < temp.size(); col++)
        {
            if (board[row][col].isRevealed())
            {
                if (temp[col].isBomb())
                {
                    temprow.push_back(temp[col].checkState());
                }
                else if (temp[col].isExplode())
                {
                    temprow.push_back(temp[col].checkState());
                    terminateState = true;
                }
                else if (temp[col].isFlag())
                {
                    temprow.push_back(temp[col].checkState());
                }
                else if (temp[col].isEmpty())
                {
                    temprow.push_back(temp[col].checkState());
                }
                else if (temp[col].isAdjNum())
                {
                    temprow.push_back(std::to_string(temp[col].getAdjNum()));
                }
            }
            else
            {
                std::string str = "Covered";
                temprow.push_back(str);
            }
        }
        result["board"].push_back(temprow);
    }
    result["state"] = (terminateState);
    return result;
}

void Minesweeper::reset()
{
    init(this->row, this->col, this->numOfMine);
}

void Minesweeper::handle(int x, int y, MouseButton btn)
{
    if (btn == left)
    {
        if (board[x][y].isFlag())
        {
        }
        else
        {
            // for (auto i : board)
            // {
            //     for (auto j : i)
            //     {
            //         if (j.isRevealed())
            //         {
            //             std::cout << "Revealed"
            //                       << " ";
            //         }
            //         else
            //         {
            //             std::cout << "Not Rev"
            //                       << " ";
            //         }
            //     }
            //     std::cout << std::endl;
            // }
            reveal(x, y);
        }
    }
    else if (btn == right)
    {
        //If not flagged
        if (board[x][y].checkState() != "Flag")
        {
            board[x][y].setPreveal(board[x][y].isRevealed());
            board[x][y].setPstate(board[x][y].checkState());
            board[x][y].setFlag();
        }
        else if (board[x][y].checkState() == "Flag")
        {
            board[x][y].set(board[x][y].checkPstate());
            board[x][y].setRevealed(board[x][y].checkPreveal());
        }
    }
}

void Minesweeper::reveal(int x, int y)
{
    if (board[x][y].isBomb())
    {
        board[x][y].setRevealed(true);
        terminateState = true;
        board[x][y].setExplode();
    }
    else
    {
        expand(x, y);
    }
}

void Minesweeper::expand(int x, int y)
{
    std::cout << "Expand: " + std::to_string(x) + ", " + std::to_string(y) << std::endl;
    int rlimit = board.size();
    int climit = board[0].size();

    if (board[x][y].isRevealed())
    {
        std::cout << "reveal b" << std::endl;
        return;
    }
    else
    {
        board[x][y].setRevealed(true);

        for (int i = std::max(0, x - 1); i <= std::min(x + 1, rlimit - 1); i++)
        {
            for (int j = std::max(0, y - 1); j <= std::min(y + 1, climit - 1); j++)
            {
                if (i != x || j != y)
                {

                    //check if the given neighbor is expandable
                    std::cout
                        << "CHecking" << std::endl;
                    if (board[i][j].isEmpty() || board[i][j].isAdjNum())
                    {
                        std::cout << "Expanding: " + std::to_string(i) + ", " + std::to_string(j) << std::endl;
                        expand(i, j);
                    }
                }
            }
        }
    }
}

Minesweeper::~Minesweeper() {}
