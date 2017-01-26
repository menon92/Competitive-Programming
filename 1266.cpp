/**
  * Problem : 1266 - Magic Square.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : 0.00 ms.
  **/
#include <iostream>
using namespace std;

int magic[20][20];

int main()
{
    freopen("input.txt", "r+", stdin);

    int n;
    bool flag = false;

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                magic[i][j] = 0;
            }
        }
        int sz = n * n;
        int r = 1;
        int c = n / 2 + 1;
        for(int i = 1; i <= sz; )
        {
            // both row & col is out of square
            if(r == 0 && c == n + 1) {
                r = 2;
                c = n;
            }
            else if(r == 0) {
                // only row is out of square
                r = r + n;
            }
            else if(c == n + 1) {
                // only col is out of square
                c = c - n;
            }
            if(magic[r][c] == 0) {
                // go through upper right corner
                magic[r][c] = i;
                r = r - 1;
                c = c + 1;
                // increment value;
                i += 1;
            }
            else {
                // if magic square is already fill then
                // back to original and go down
                r = r + 2;
                c = c - 1;
            }
        }
        int sum = 0;

        for(int c = 1; c <= n; c++) {
            sum += magic[1][c];
        }
        if(flag) {
            printf("\n");
        }
        flag = true;
        printf("n=%d, sum=%d\n", n, sum);

        for(r = 1; r <= n; r++)
        {
            for(int c = 1; c <= n; c++)
            {
                if(n == 3) {
                    printf("%2d", magic[r][c]);
                }
                else if(n < 10) {
                    printf("%3d", magic[r][c]);
                }
                else {
                    printf("%4d", magic[r][c]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

