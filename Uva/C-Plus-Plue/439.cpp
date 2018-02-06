//------------------------------
// Problem : 439-Knight Moves.
// Status  : Accepted.
// Author  : Mehadi Hasan Menon.
// Date    : 25.01.2016.
//------------------------------
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int infinity = 10;
int fx[] = {-2, -2, -1, 1, 2, 2, 1, -1}; // direction array for knight (row)
int fy[] = {-1, 1, 2, 2, 1, -1, -2, -2}; // (coll)

// s = start point; e = end pint; t = temporiry;
// pii = pair of int, int;

int bfs(int sx, int sy, int ex, int ey)
{
	queue <pair <int, int> > QQ;
	int d[8][8];

	memset(d, infinity, sizeof(d));
	// put the starting cell index in the pari.
	// put the staring cell in the QUEUE for processing.
	QQ.push(pair <int, int>(sx,sy));
	d[sx][sy] = 0;

	while(!QQ.empty())
	{
		pair <int, int> top;
		int tx, ty;
		int px, py; // p = parent.

		top = QQ.front();
		px = top.first;
		py = top.second;

		// generally we can go from cell[tx][ty] into 8 different location
		// coz a knight can go 8 different locaton.
		for(int i = 0; i < 8; i++)
		{
			tx = top.first + fx[i];
			ty = top.second + fy[i];

			if(tx >= 0 && tx < 8 && ty >= 0 && ty < 8) // max row/col size is 8;
			{
				if(d[tx][ty] > d[px][py] + 1)
				{
					d[tx][ty] = d[px][py] + 1;

					QQ.push(pair <int, int> (tx, ty));
				}
			}
		}

		// kaj sesh :) now dele the top element;
		QQ.pop();
	}

	return d[ex][ey];
}


int main()
{
	char s[3], e[3];

	//freopen("439.txt", "r+", stdin);

	while(scanf("%s %s", &s, &e) != EOF)
	{
		int srow, scol, erow, ecol;
		int moves;

		scol = s[0] - 'a';
		srow = s[1] - '0' - 1;
		ecol = e[0] - 'a';
		erow = e[1] - '0' - 1;

		moves = bfs(srow, scol, erow, ecol);

		printf("To get from %s to %s takes %d knight moves.\n", s, e, moves);
	}

	return 0; 
}
