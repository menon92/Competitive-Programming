/**
  * Problem : 10946 - You want what filled?
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 25.12.16.
  **/
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int mx = 55;

char island[mx][mx];
int x, y;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct data
{
    int rank_size;
    char name;

} rank_list[2505];
// max different hole may be 50 x 50
// this will will skip run time ERROR :)

bool compare(const data &a, const data &b)
{
    if(a.rank_size == b.rank_size)
    {
        return a.name < b.name;
    }
    else
    {
        return a.rank_size > b.rank_size;
    }
}

int dfs(int r, int c, char new_hole)
{
    if(r < 0 || r >= x || c < 0 || c >= y || island[r][c] != new_hole)
    {
        return 0;
    }
    if(island[r][c] == '.')
    {
        return 0;
    }

    island[r][c] = '.';

    int ans = 1;

    for(int i = 0; i < 4; i++)
    {
        int new_row = r + dr[i];
        int new_col = c + dc[i];

        ans += dfs(new_row, new_col, new_hole);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc = 1;

    while(scanf("%d %d", &x, &y) && x != 0 && y != 0)
    {
        for(int i = 0; i < x; i++)
        {
            scanf("%s", island[i]);
        }

        int index = 0;

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(island[i][j] != '.')
                {
                    rank_list[index].name = island[i][j];
                    rank_list[index].rank_size =  dfs(i, j, island[i][j]);

                    index += 1;
                }
            }
        }

        // sort our rank list structure
        sort(rank_list, rank_list + 2505, compare);

        // finally print result
        printf("Problem %d:\n", tc);
        for(int i = 0; i < 2505; i++)
        {
            if(rank_list[i].rank_size == 0)
            {
                break;
            }
            printf("%c %d\n", rank_list[i].name, rank_list[i].rank_size);
        }
        tc += 1;

        // reset our rank list
        for(int i = 0; i < 2505; i++)
        {
            rank_list[i].rank_size = 0;
        }

    }

    return 0;
}
