#ifndef CELL_H
#define CELL_H
#include <server.h>
#include<string>

class Cell
{
    std::string state;
    int adjNum;
    bool revealed;
    bool preveal;
    std::string pstate;
public:
    Cell();
    Cell(std::string);
    ~Cell();
    void setPstate(std::string);
    std::string checkPstate();
    void setPreveal(bool);
    bool checkPreveal();
    bool isBomb();
    bool isFlag();
    bool isEmpty();
    bool isAdjNum();
    bool isExplode();
    bool isRevealed();
    void setRevealed(bool);
    void set(std::string);
    void setExplode();
    void setBomb();
    void setFlag();
    void setEmpty();
    void setAdjNum(int);
    void setAdjState();
    int getAdjNum();
    std::string checkState();
};

#endif