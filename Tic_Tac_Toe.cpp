#include "Tic_Tac_Toe.h"

void Tic_Tac_Toe::printBoard()
{
	for (int i = 0; i < 13; i++)
		cout << '_';
	cout << endl;
	for (int m = 0; m < 3; m++)
	{
		
		cout << '|';
		for (int n = 0; n < 3; n++)
		{
			if (board[m][n] == 0)
				cout << "   |";
			if (board[m][n] == 1)
				cout << " * |";
			if (board[m][n] == 2)
				cout << " # |";
		}
		cout << endl;
		for (int i = 0; i < 13; i++)
			cout << '_';
		cout << endl;
	}
}
int Tic_Tac_Toe::judge()//用于帮AI递归判断胜负
{
	for (int i = 0; i < 3; i++)//检查行与列
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] )
		{
			if (board[i][0] == 1)
			{
				//Games::addplWin();
				return -100;
			}
			else if (board[i][0] == 2)
			{
				//Games::addpcWin();
				return 100;
			}
		}
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] )
		{
			if (board[0][i] == 1)
			{
				//Games::addplWin();
				return -100;
			}
			else if (board[0][i] == 2)
			{
				//Games::addpcWin();
				return 100;
			}
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] )
	{
		if (board[0][0] == 1)
		{
			//Games::addplWin();
			return -100;
		}
		else if (board[0][0] == 2)
		{
			//Games::addpcWin();
			return 100;
		}
	}
	if (board[0][2] == board[2][0] && board[0][2] == board[1][1] )
	{
		if (board[1][1] == 1)
		{
			/*Games::addplWin();
			Games::addTotal();*/
			return -100;
		}
		else if (board[1][1] == 2)
		{
			/*Games::addpcWin();
			Games::addTotal();*/
			return 100;
		}
	}
	//Games::addTotal();
}
bool Tic_Tac_Toe::isMovesLeft()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}
int Tic_Tac_Toe::minimax(int depth, bool isAI)
{
	int score=judge();
	if (score == 100)
	{
		return score;
	}
	if (score == -100)
		return score;
	if (isMovesLeft() == 0)
		return 0;
	if (isAI)
	{
		int best = -1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = 2;
					best=max(best,minimax(depth + 1, !isAI));
					board[i][j] = 0;
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = 1;
					best = min(best, minimax(depth + 1, !isAI));
					board[i][j] = 0;
				}
			}
		}
		return best;
	}
}
void Tic_Tac_Toe::findBestMove()
{
	bestmove.row = -1;
	bestmove.column = -1;
	int best = -1000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 2;
				int moveval=minimax(0, false);
				if (moveval > best)
				{
					bestmove.row = i;
					bestmove.column = j;
					best = moveval;
				}
				board[i][j] = 0;
			}
		}
	}
	board[bestmove.row][bestmove.column] = 2;
}
void Tic_Tac_Toe::play(int a,int b)
{

	while (1)
	{
		if (board[a-1][b-1] == 0)
		{
			board[a-1][b-1] = 1;
			break;
		}
		else
		{
			cout << "False!" << endl;
			cout << "Row:";
			cin >> a;
			cout << "Coloumn:" << endl;
			cin >> b;
		}
	}
	if (judge() != 10 && judge() != -10 && isMovesLeft() != 0)
	{
		findBestMove();
	}
	/*int flag = 0;
	int i;
	int j;
	for (i = 0; i < 3&&flag<2; i++)
	{
		for (j = 0; j < 3&&flag<2; j++)
		{
			if (board[i][j] == 0)
			{
				for (int m = 0; m < 3; m++)
				{
					if (board[i][m] == 1)
					{
						flag++;
					}
					if (flag == 2)
					{
						board[i][j] = 2;
						break;
					}
				}
				if (flag < 2)
					flag = 0;
				for (int n = 0; n < 3; n++)
				{
					if (board[n][j] == 1)
						flag++;
					if (flag == 2)
					{
						board[i][j] = 2;
						break;
					}
				}
				if (flag < 2)
					flag = 0;
				if (i == j)
				{
					for (int e = 0; e < 3; e++)
					{
						if (board[e][e] == 1)
							flag++;
						if (flag == 2)
						{
							board[i][j] = 2;
							break;
						}
					}
				}
				if (flag < 2)
					flag = 0;
				if (i == 2 - j)
				{
					for (int e = 0; e < 3; e++)
					{
						if (board[e][2 - e] == 1)
							flag++;
						if (flag == 2)
						{
							board[i][j] = 2;
							break;
						}
					}
				}
			}
		}
	}
	if (flag < 2)
		board[i][j] = 2;*/
}