/**
  * Problem : 11463 - Commandos.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : 0.010 ms.
  ***/
#include <iostream>
using namespace std;

const int mx = 105;
const int inf = 1000007;
int quarter[mx][mx];

void floyd(int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                quarter[i][j] = min(quarter[i][j], quarter[i][k] + quarter[k][j]);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r+", stdin);
    int tc, n, r;

    scanf("%d", &tc);
    for(int t = 1; t <= tc; t++)
    {
        scanf("%d %d", &n, &r);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                quarter[i][j] = quarter[j][i] = inf;
                if(i == j) {
                    quarter[i][j] = 0;
                }
            }
        }
        int u, v;
        for(int i = 0; i < r; i++)
        {
            scanf("%d %d", &u, &v);
            quarter[u][v] = quarter[v][u] = 1;
        }
        floyd(n);

        int ans = 0;
        scanf("%d %d\n", &u, &v);

        for(int i = 0; i < n; i++)
        {
            if(quarter[u][i] != inf && quarter[i][v] != inf) {
                ans = max(ans, quarter[u][i] + quarter[i][v]);
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
