//-----------------------------------------------
// Problem : 10653 - Bombs! NO they are Mines!!
// Status  : Accepted.
// Author  : Md.Mehadi Hasan Menon.
// Submission time : 26-01-2016.
//-----------------------------------------------
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int fx[] = {-1, 0, 1, 0};
int fy[] = {0, 1, 0, -1};
int cell[1002][1002];
//-----------------------------------------------------
// the second dymension of 2D arra must be declare as
// Macro or as a Global Constan variable
//-----------------------------------------------------
int bfs(int srow, int scol, int erow, int ecol, int M, int N)
{
	queue < pair <int, int> > QQ;
	int distance[M][N], visited[M][N];

	memset(visited, 0, sizeof(visited));

	QQ.push(pair <int, int> (srow, scol));
	cell[srow][scol] = 1; // cell[i][j] = 1; then cell is visited
	distance[srow][scol] = 0;

	while(!QQ.empty())
	{
		pair <int, int> top;
		int px, py, cx, cy;

		top = QQ.front();
		px = top.first;
		py = top.second;

		for(int i = 0; i < 4; i++)
		{
			cx = px + fx[i];
			cy = py + fy[i];
			
			// check wheather the position is valid or not;

			if(cx >= 0 && cx < M && cy >= 0 && cy < N)
			{
				// the position is not block and not visited.
				if(cell[cx][cy] != -1 && visited[cx][cy] != 1)
				{
					visited[cx][cy] = 1;
					distance[cx][cy] = distance[px][py] + 1;

					QQ.push(pair <int, int> (cx, cy));
				}
			}
		}
		QQ.pop();
	}

	return distance[erow][ecol];
}

int main()
{
	int nRows, row, col, rowNumber, bombs;
	int srow, scol, erow, ecol, moves;
	int M, N, c;

  // freopen("10653.txt", "r+", stdin);

	while(cin >> M >> N)
	{
		if(M == 0 && N == 0)
            break;

		cin >> nRows;
		for(int i = 0; i < nRows; i++)
		{
			cin >> row >> bombs;
			for(int i = 0; i < bombs; i++)
			{
				cin >> c;
				cell[row][c] = -1; // if cell[i][j] = -1 there is a bombs;
			}
		}

		cin >> srow >> scol;
		cin >> erow >> ecol;

		moves = bfs(srow, scol, erow, ecol, M, N);

		cout << moves << endl;

		memset(cell, 0, sizeof(cell)); // reset the cell.
	}

	return 0;
}
