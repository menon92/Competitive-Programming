/**
  * Problem : 469-Wetlands of Florida.
  * Verdict : Accepted.
  * Author: Mehadi Hasan Menon.
  * Algorithm : DFS.
  * Date: 10.07.16.
  **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using std :: cin;
using std :: cout;
using std :: endl;

const int mx = 100;
char grid[mx][mx];
int ans, row, col;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c, char c1, char c2)
{
    if(r < 0 || c < 0 || r >= row || c >= col) {
        return;
    }
    if(grid[r][c] != c1) {
        return;
    }

    int x, y;

    grid[r][c] = c2;
    ans = ans + 1;

    for(int i = 0; i < 8; i++)
    {
        x = r + dr[i];
        y = c + dc[i];

        dfs(x, y, c1, c2);
    }
}

int main()
{
//    freopen("469.txt", "r+", stdin);
//    freopen("out.txt", "r+", stdout);

    int tc, r, c;
    int n, m;

    scanf("%d", &tc);
    getchar();
    getchar();

    for(int t = 0; t < tc; t++)
    {
        bool f = true;
        int i = 0; row = 0;
        char s[mx];

        if(t > 0) {
            printf("\n");
        }

        while(gets(s) && strlen(s) > 0)
        {

            if(f)
            {
                col = strlen(s);
                f = false;
            }

            if(s[0] == 'L' || s[0] == 'W')
            {
                strcpy(grid[i], s);
                row++;
                i++;
            }
            else
            {
                sscanf(s, "%d %d", &r, &c);

                ans = 0;
                dfs(r - 1, c - 1, 'W', '.');

                printf("%d\n", ans);

                dfs(r - 1, c - 1, '.', 'W'); // restore the graph.
            }
        }
    }
    return 0;
}

