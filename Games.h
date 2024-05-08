#include <string>
using namespace std;
#ifndef GAMES
#define GAMES
class Games
{
	string player;
	int plWin, pcWin, total;
public:
	Games(string &a):player(a)
	{
		plWin = 0;
		pcWin = 0;
		total = 0;
	}
	void addplWin()
	{
		plWin++;
	}
	void addpcWin()
	{
		pcWin++;
	}
	void addTotal()
	{
		total++;
	}
	int getPlWin()
	{
		return plWin;
	}
	int getPcWIn()
	{
		return pcWin;
	}
	int getTotal()
	{
		return total;
	}
};
#endif