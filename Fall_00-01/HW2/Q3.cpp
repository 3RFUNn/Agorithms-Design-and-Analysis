#include <iostream> 
using namespace std;
extern int counter = 0;
void MasirYab(bool **Graph, char **Board, int currentx, int currenty, int x, int y)
{
	if(currenty != (y - 1))
	{
		counter++;
	}
	Graph[currentx][currenty] = true;
	if((currentx + 1) < x && Board[currentx + 1][currenty] == '-' && Graph[currentx + 1][currenty] == false)
	{
		MasirYab(Graph, Board, currentx + 1, currenty, x, y);
	}
	if((currentx - 1) >= 0 && Board[currentx - 1][currenty] == '-' && Graph[currentx - 1][currenty] == false)
	{
		MasirYab(Graph, Board, currentx - 1, currenty, x, y);
	}
	if((currenty - 1) >= 0 && Board[currentx][currenty - 1] == '-' && Graph[currentx][currenty - 1] == false)
	{
		MasirYab(Graph, Board, currentx, currenty - 1, x, y);
	}
	if(Board[currentx][currenty + 1] == '-' && Graph[currentx][currenty + 1] == false)
	{
		MasirYab(Graph, Board, currentx, currenty + 1, x, y);
	}
}
int main()
{
	int x,y;
	cin>>x>>y;
	char *Board[x];
	for(int i = 0; i < x; i++)
	{
		Board[i] = new char[y];
	}
    for(int i = 0;i < x; i++)
    {
        for(int j = 0;j < y; j++)
            cin>>Board[i][j];
    }
   	bool *Graph[x];
	for(int k = 0; k < x; k++)
	{
		Graph[k] = new bool[y];
	}
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			Graph[i][j] = false;
		}
	}
    for(int i = 0;i < x; i++)
    {
   		if(Board[i][y - 1] == '-')
			MasirYab(Graph, Board, i, y - 1, x, y);
    }
	cout<<counter;
	return 0;
}
