/**
  * Problem : 722 - Lakes.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 24.12.16
  **/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m, n;
const int mx = 105;
char grid[mx][mx];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(int r, int c)
{
	if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '1') {
		return 0;
	}

	grid[r][c] = '1';

	int ans = 1;
	for(int i = 0; i < 4; i++)
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
	char number1[5], number2[5];

	scanf("%d\n", &tc);
	for(int t = 0; t < tc; t++)
	{
		scanf("%s %s", &number1, &number2);
		getchar();

		int row = atoi(number1);
		int col = atoi(number2);

		int i = 0;
		char str[mx - 1];

		while(gets(str) && strcmp(str, "") != 0)
		{
			strcpy(grid[i], str);
			i++;
		}
		m = i;
		n = strlen(grid[0]);

        if(t > 0) {
            printf("\n");
        }
		cout << dfs(row - 1, col - 1) << endl;

	}

	return 0;
}
