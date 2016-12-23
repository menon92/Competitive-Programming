/**
  * Problem : 657 - The die is cast
  * Verdict : Accepted.
  * Write   : Mehadi Hasan Menon.
  * Date    : 23.12.16
  **/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int mx = 55;

char board[mx][mx];
int m, n, points;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs_for_x(int r, int c)
{
	if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '.' || board[r][c] == '*') {
		return ;
	}
    // if we set '.' in place of '.' then we get WA.
    // because by set '.' it causes the connected '*' area
    // to disconnected area. I got 6 time WA for this :(
	board[r][c] = '*';

	for(int i = 0; i < 4; i++)
	{
		int new_row = r + dr[i];
		int new_col = c + dc[i];

		dfs_for_x(new_row, new_col);
	}

}

void dfs_for_star(int r, int c)
{
	if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '.') {
		return ;
	}
	if(board[r][c] == 'X')
	{
		points += 1;
		dfs_for_x(r, c);
	}
	board[r][c] = '.';

	for(int i = 0; i < 4; i++)
	{
		int new_row = r + dr[i];
		int new_col = c + dc[i];

		dfs_for_star(new_row, new_col);
	}

}

int main()
{
	freopen("input.txt", "r+", stdin);

	int w, h, tc;

    tc = 1;
	while(scanf("%d %d", &w, &h) && w != 0 && h != 0)
	{
		m = h;
		n = w;
        getchar();
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%c", &board[i][j]);
			}
			getchar();
		}

        vector <int> vi;
		for(int i = 0; i < m; i++)
		{
			for(int j =0; j < n; j++)
			{
				points = 0;
				if(board[i][j] == '*')
				{
					dfs_for_star(i, j);

					vi.push_back(points);
				}
			}
		}

		for(int i =0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'X')
                {
                    dfs_for_x(i, j);
                    vi.push_back(1);
                }
            }
        }

		sort(vi.begin(), vi.end());
		int sz = vi.size();


		printf("Throw %d\n", tc);
		for(int i = 0; i < sz; i++)
        {
			if(i > 0) {
                printf(" ");
			}
            printf("%d", vi[i]);
		}
		printf("\n\n");
		tc++;
	}

	return 0;
}
