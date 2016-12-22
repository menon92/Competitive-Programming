/**
  * Problem : 11094 - Continents
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 22.12.16.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 25;
char grid[mx][mx];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int M, N, X, Y;
char watter, land;

int dfs(int r, int c)
{
    if(r < 0 || r >= M || c < 0 || c >= N) {
        return 0;
    }
    if(grid[r][c] != land) {
        return 0;
    }

    grid[r][c] = land - 1; //watter; // set a char different from land char

    int ans = 1;

    if(c ==  0) {
        ans += dfs(r, N - 1);
    }
    for(int i = 0; i < 4; i++) {
        int new_row = r + dr[i];
        int new_col = c + dc[i];

        ans += dfs(new_row, new_col);
    }
    return ans;

}

int main()
{
    freopen("input.txt", "r+", stdin);

    while(cin >> M >> N)
    {
        cin.ignore();
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> grid[i][j];
            }
            cin.ignore();
        }

        cin >> X >> Y;

        land = grid[X][Y];

        dfs(X, Y); // skip self region :) important

        int max_regin, total_region;

        max_regin = 0;
        total_region = 0;

        // find the max region from other part
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {

                total_region = dfs(i, j);

                if(total_region > max_regin) {
                    max_regin = total_region;
                }
            }
        }
        cout << max_regin << endl;
    }

    return 0;
}
