/**
  * Problem : 11953 - Battleships.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 26.12.16.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 105;
char grid[mx][mx];
int n;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == '.')
    {
        return;
    }
    grid[r][c] = '.';

    for(int i = 0; i < 4; i++)
    {
        int new_row = r + dr[i];
        int new_col = c + dc[i];

        dfs(new_row, new_col);
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc;

    scanf("%d", &tc);
    for(int t = 1; t <= tc; t++)
    {
        scanf("%d", &n);


        for(int i = 0; i < n; i++)
        {
            scanf("%s", grid[i]);
        }

        int number_of_ships = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != '.' && grid[i][j] == 'x')
                {
                    dfs(i, j);

                    number_of_ships += 1;
                }
            }
        }
        printf("Case %d: %d\n", t, number_of_ships);
    }

    return 0;
}
