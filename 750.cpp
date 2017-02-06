/**
  * Problem : 750 - 8 Queens Chess Problem.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : 0.00 ms.
  **/
#include <iostream>
using namespace std;

int column[20], diagonal1[40], diagonal2[40], queen[20];
int given_row, given_col, cnt;
int ans[93][8];
int r = 1;

void n_queen(int at, int n)
{
    if(at == n + 1)
    {
        for(int i = 1; i <= n; i++) {
            ans[r][i] = queen[i];
        }
        r += 1;
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(column[i] || diagonal1[i + at] || diagonal2[i - at + n])
        {
            // we have a queen in column || diagonal1 || diagonal2
            // so we can't put a new queen at this position
            continue;
        }
        queen[at] = i;

        column[i] = diagonal1[i + at] = diagonal2[i - at + n] = 1; // have a queen.

        n_queen(at + 1, n);
        // backtrack ;
        column[i] = diagonal1[i + at] = diagonal2[i - at + n] = 0; // reset.
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc;

    // generate all possible square position;
    n_queen(1, 8);

    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        cin >> given_row >> given_col;

        if(i > 0) {
            printf("\n");
        }
        // process the output and print as described in problem description;
        cout << "SOLN       COLUMN"  << endl;
        cout << " #      1 2 3 4 5 6 7 8"  << endl;
        cout << endl;
        cnt = 1;

        for(int k = 1; k < 93; k++)
        {
            // if this is the desire position then print this row;
            if(ans[k][given_col] == given_row)
            {
                printf("%2d     ", cnt++);
                for(int l = 1; l <= 8; l++)
                {
                    printf(" %d", ans[k][l]);
                }
                printf("\n");
            }
        }
        cnt = 1;
    }
    return 0;
}
