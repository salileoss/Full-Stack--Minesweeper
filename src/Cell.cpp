#include <Cell.h>
#include <string>

Cell::Cell()
{
    state = "Empty";
    adjNum = 0;
    revealed = false;
    preveal = false;
    pstate = "Empty";
}

Cell::Cell(std::string str)
{
    state = str;
}

Cell::~Cell() {}

void Cell::setPstate(std::string str)
{
    pstate = str;
}

void Cell::setPreveal(bool b)
{
    preveal = b;
}

bool Cell::checkPreveal(){
    if(preveal == true){
        return true;
    }
    return false;
}

std::string Cell::checkPstate()
{
    return pstate;
}

bool Cell::isBomb()
{
    if (state == "Bomb")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Cell::isFlag()
{
    if (state == "Flag")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Cell::isEmpty()
{
    if (state == "Empty")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Cell::isExplode()
{
    if (state == "Explode")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Cell::isRevealed()
{
    if (revealed == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Cell::setRevealed(bool b)
{
    revealed = b;
}

void Cell::set(std::string str)
{
    state = str;
}

void Cell::setExplode()
{
    state = "Explode";
}

void Cell::setBomb()
{
    state = "Bomb";
}

void Cell::setFlag()
{
    state = "Flag";
}

void Cell::setEmpty()
{
    state = "Empty";
}

void Cell::setAdjNum(int num)
{
    adjNum = num;
}

int Cell::getAdjNum()
{
    return adjNum;
}

bool Cell::isAdjNum()
{
    if (adjNum == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Cell::setAdjState()
{
    state = "AdjNum";
}

std::string Cell::checkState()
{
    return state;
}