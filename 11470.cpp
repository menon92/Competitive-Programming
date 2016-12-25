/**
  * Problem : 11470 - Square Sums.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 25.12.16.
  **/
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r+", stdin);

    int square[11][11];
    int n_square;
    int n, tc = 1;

    while(scanf("%d", &n) && n != 0)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &square[i][j]);
            }
        }

        n_square = ceil(n / 2.0);

        printf("Case %d:", tc++);
        for(int i = 0; i < n_square; i++)
        {
            int new_row = n - i;
            int new_col = n - i;
            int sum = 0;

            for(int row = i; row < new_row; row++)
            {
                for(int col = i; col < new_col; col++)
                {
                    if(row == i || row == new_row - 1 || col == i || col == new_col - 1)
                    {
                        sum += square[row][col];
                    }
                }
            }
            printf(" %d", sum);
        }
        puts("");
    }

    return 0;
}
