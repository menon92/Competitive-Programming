/**
  * Problem : 871 - Counting Cells in a Blob 
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 25.12.16.
  **/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mx = 30;

char grid[mx][mx];
int m, n;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dfs(int r, int c)
{
	if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
		return 0;
	}
	grid[r][c] = '0';

    int ans = 1;

	for(int i = 0; i < 8; i++)
	{
		int new_row = r + dr[i];
		int new_col = c + dc[i];

		ans += dfs(new_row, new_col);
	}
	return ans;
}


int main()
{
	freopen("input.txt", "r+", stdin);

	int tc;

	scanf("%d\n", &tc);
	for(int t = 1; t <= tc; t++)
	{
		int r = 0;
		char line[mx];

		while(gets(line) && strcmp(line, "") != 0)
		{
			strcpy(grid[r], line);
			r += 1;
		}
		int c = strlen(grid[0]);

		m = r;
		n = c;

		int max_blob = 0;

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(grid[i][j] != '0')
				{
					int new_blob = dfs(i, j);

					if(new_blob > max_blob) {
						max_blob = new_blob;
					}
				}
			}
		}

		if(t > 1) {
			cout << endl;
		}

		cout << max_blob << endl;

	}

	return 0;
}
