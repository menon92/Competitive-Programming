/**
  * Problem : 10066 - The Twin Towers
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Algorithm : LCS, DP
  **/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 101;
int a[N], b[N];
int dp[N][N];
bool visited[N][N];
int N1, N2;

void init_vis(int n1, int n2)
{
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            visited[i][j] = 0;
        }
    }
}
int get_common_tiles_num(int i, int j)
{
    if(i >= N1 || j >= N2) {
        return 0;
    }
    if(visited[i][j]) {
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + get_common_tiles_num(i + 1, j + 1);
    }
    else {
        int val1 = get_common_tiles_num(i + 1, j);
        int val2 = get_common_tiles_num(i, j + 1);

        ans = max(val1, val2);
    }
    visited[i][j] = 1;
    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    //freopen("input.txt", "r+", stdin);
    //freopen("out.txt", "r+", stdout);

    int tc = 1;

    while(scanf("%d %d", &N1, &N2))
    {
        if(N1 == 0 && N2 == 0) {
            break;
        }
        // take input
        for(int i = 0; i < N1; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < N2; i++) {
            scanf("%d", &b[i]);
        }
        // get calculate answer
        int common_tiles = get_common_tiles_num(0, 0);
        // print answer.
        printf("Twin Towers #%d\n", tc);
        printf("Number of Tiles : %d\n", common_tiles);
        printf("\n");
        init_vis(N1, N2);
        tc++;
    }

    return 0;
}
