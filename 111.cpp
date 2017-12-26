/**
  * Problem : 111 - History Grading
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Algorithm : LCS, DP
  **/
#include <iostream>
#include <cstdio>
using namespace std;

const int MX = 21;
int a[MX], b[MX];
bool vis[MX][MX];
int dp[MX][MX];
int N;

void init_vis(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            vis[i][j] = 0;
        }
    }
}

int lcs(int i, int j)
{
    if(i > N || j > N) {
        return 0;
    }
    if(vis[i][j]) {
        return dp[i][j];
    }
    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + lcs(i + 1, j + 1);
    }
    else {
        int x = lcs(i + 1, j);
        int y = lcs(i, j + 1);
        ans = max(x, y);
    }
    vis[i][j] = 1;
    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int item;
    scanf("%d", &N);
    // taking input and mapping input with item.
    for(int i = 1; i <= N; i++) {
        scanf("%d", &item);
        a[item] = i;
    }
    while(scanf("%d", &item) == 1) {
        b[item] = 1;
        for(int i = 2; i <= N; i++) {
            scanf("%d", &item);
            b[item] = i;
        }
        printf("%d\n", lcs(1, 1));
        init_vis(N);
    }
    return 0;
}
