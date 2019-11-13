#include <iostream>
#include<BoardGame.h>
#include<MineSweeper.h>
#include<iostream>

using namespace std;

int main(){


	BoardGame* game = new Minesweeper(9, 9, 10);
	// game->handle(0,4,"right");

	return 0;
}
