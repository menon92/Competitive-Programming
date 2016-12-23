/**
  * Problem : 572 - Oil Deposits
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 23.12.16.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 105;
int m, n;
char grid[mx][mx];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c)
{
	if(r < 0 || r >= m || c < 0 || c >= n) {
		return ;
	}
	if(grid[r][c] != '@') {
        return ;
	}
	grid[r][c] = '*';

	for(int i = 0; i < 8; i++)
	{
		int new_row = r + dr[i];
		int new_col = c + dc[i];

		dfs(new_row, new_col);
	}
}

int main()
{
	freopen("input.txt", "r+", stdin);

	while(scanf("%d %d", &m, &n) && m != 0 && n != 0)
	{
		getchar();

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%c", &grid[i][j]);
			}
			getchar();
		}

		int deposits = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(grid[i][j] == '@')
				{
					dfs(i, j);
					deposits += 1;
				}
			}
		}

		cout << deposits << endl;
	}

	return 0;
}
