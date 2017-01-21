/**
  * Problem : 423 - MPI Maelstrom
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : 0.00 ms.
  **/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int mx = 105;
const int inf = 100000007;
int network[mx][mx];

void floyd_warshall(int n)
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                network[i][j] = min(network[i][j], network[i][k] + network[k][j]);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r+", stdin);

    int n, time;
    char str[15];

    while(cin >> n)
    {
        for(int r = 1; r <= n; r++)
        {
            for(int c = 1; c <= r; c++)
            {
                if(r == c) {
                    network[r][c] = 0;
                }
                else {
                    scanf("%s", str);
                    if(str[0] == 'x') {
                        network[r][c] = network[c][r]= inf;
                    }
                    else {
                        network[r][c] = network[c][r] = atoi(str);
                    }
                }
            }
        }
        floyd_warshall(n);

        int min_cost = 0;
        for(int r = 2; r <= n; r++) {
            min_cost = max(min_cost, network[1][r]);
        }
        printf("%d\n", min_cost);

    }
    return 0;
}
