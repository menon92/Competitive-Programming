/**
  * Problem : 10130-Super Sale
  * Status  : Accepted.
  * Date    : 05.10.2015.
  **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MAX_W 1000

int n;
int dp[MAX_N + 1][MAX_W + 1];
int weight[MAX_N + 1];
int cost[MAX_N + 1];
int CAP;

int func(int i, int w)
{
    if(i == n+1)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    int profit1 = 0, profit2 = 0;

    if(w+weight[i] <= CAP)
        profit1 = cost[i] + func(i+1, w+weight[i]); // try by taking i'th goods
    
    profit2 = func(i+1, w); // try without i'th goods.
    
    dp[i][w] = max(profit1, profit2);
    return dp[i][w];

}

int main()
{
    int tcaes, g, familyMemberCapacity[100 + 1];

    //freopen("input.txt", "r", stdin);

    scanf("%d", &tcaes);
    while(tcaes--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &cost[i], &weight[i]);
        }

        int totalCost = 0;

        scanf("%d", &g);
        for(int i = 1; i <= g; i++)
        {
            memset(dp, -1, sizeof(dp));

            scanf("%d", &familyMemberCapacity[i]);

            CAP = familyMemberCapacity[i];

            totalCost += func(1, 0);
        }
        printf("%d\n", totalCost);
    }

    return 0;
}
