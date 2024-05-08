#include <iostream>
#include "Tic_Tac_Toe.h"
int main()
{
	string player;
	cin >> player;
	Tic_Tac_Toe t(player);
	t.printBoard();
	int a, b;
	while (1)
	{
		cin >> a >> b;
		t.play(a, b);
		if (t.judge() == 100)
		{
			cout << "Pc wins!" << endl;
			break;
		}
		else if (t.judge() == -100)
		{
			cout << "Pl wins!" << endl;
			break;
		}
		else if (t.isMovesLeft() == 0)
		{
			cout << "No one wins!" << endl;
			break;
		}
		t.printBoard();
	}
}