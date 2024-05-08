#include <iostream>
#include "Games.h"
#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
struct Move
{
	int row;
	int column;
};
class Tic_Tac_Toe:public Games
{
	int board[3][3];
	Move bestmove;
public:
	Tic_Tac_Toe(string& a) :Games(a)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = 0;
			}
		}
		bestmove.row = -1;
		bestmove.column = -1;
	}
	void printBoard();
	void play(int,int);
	int minimax(int, bool);
	int judge();
	bool isMovesLeft();
	void findBestMove();
	void battle();
};
#endif