/**
  * Problem : 11244 - Counting Stars
  * Verdict : Accepted.
  * Write   : Mehadi Hasann Menon.
  * Date    : 25.12.16.
  **/
#include <iostream>
#include <cstdio>

const int mx = 105;

char sky[mx][mx];

int r, c;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int ans;

void dfs_count_star(int row, int col)
{
	if(row < 0 || row >= r || col < 0 || col >= c || sky[row][col] == '.') {
		return ;
	}
	sky[row][col] = '.';

	ans += 1;

	for(int i = 0; i < 8; i++)
	{
		int new_row = row + dr[i];
		int new_col = col + dc[i];

		dfs_count_star(new_row, new_col);
	}
}

int main()
{
	freopen("input.txt", "r+", stdin);
	freopen("output.txt", "r+", stdout);

	while(scanf("%d %d", &r, &c) && r != 0 && c != 0)
	{
		for(int i = 0; i < r; i++)
		{
			scanf("%s", sky[i]);
		}

		int count_stars = 0;

		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				// if sky is not faka then search for star :P
				if(sky[i][j] != '.')
				{
					dfs_count_star(i, j);

					if(ans == 1) {
						count_stars += 1;
					}
					ans = 0;
				}
			}
		}

		printf("%d\n", count_stars);
	}

	return 0;
}
