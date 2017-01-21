/**
  * Problem : 341 - Non-Stop Travel.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : 0.00 ms.
  **/
#include <iostream>
#include <cstdio>
using namespace std;

const int inf = 100000007;
int region[12][12];
int p[12][12];

void floyd_warshall(int node)
{
    for(int k = 1; k <= node; k++)
    {
        for(int i = 1; i <= node; i++)
        {
            for(int j = 1; j <= node; j++)
            {
                if(region[i][k] + region[k][j] < region[i][j])
                {
                    region[i][j] = region[i][k] + region[k][j];
                    p[i][j] = p[i][k];
                }

            }
        }
    }
}
void print_path(int i, int j)
{
    printf(" %d", i);
    while(i != j)
    {
        i = p[i][j];
        printf(" %d", i);
    }
}
int main()
{
    freopen("input.txt", "r+", stdin);

    int ni, streets, u, v, time, tc;
    tc = 1;
    while(scanf("%d", &ni) && ni != 0)
    {
        for(int i = 1; i <= ni; i++)
        {
            for(int j = 1; j <= ni; j++)
            {
                region[i][j] = inf;
            }
        }
        for(u = 1; u <= ni; u++)
        {
            scanf("%d", &streets);
            for(int i = 0; i < streets; i++)
            {
                scanf("%d %d", &v, &time);

                // IMPORTANT :D
                region[u][v] = min(region[u][v], time);
                p[u][v] = v;
            }
        }
        floyd_warshall(ni);
        int src, des;

        scanf("%d %d", &src, &des);

        printf("Case %d: Path =", tc++);
        print_path(src, des);
        printf("; %d second delay\n", region[src][des]);

    }
    return 0;
}
