#include <iostream>
#include<BoardGame.h>
#include<MineSweeper.h>
#include<iostream>

using namespace std;

int main(){


	BoardGame* game = new Minesweeper(9, 9, 10);
	std::cout<<"RESETTING"<<std::endl;
	game->reset();

	return 0;
}
