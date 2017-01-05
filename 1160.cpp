/**
  * Problem : 1160 - X-Plosives.
  * Verdict : Accepted.
  * Time    : 0.00 ms.
  * Writer  : Mehadi Hasan Menon.
  ****/
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

const int mx = 100005;
int boss[mx];

void make_boss(int n) {
    for(int i = 1; i <= n; i++) {
        boss[i] = i;
    }
}
int find_boss(int x) {
    return (boss[x] == x) ? x : boss[x] = find_boss(boss[x]);
}
int main()
{
    freopen("input.txt", "r+", stdin);

    char s1[20], s2[20];
    int x, y, cnt;

    cnt = 0;
    make_boss(mx);
    while(scanf("%s", &s1) != EOF)
    {
        if(strcmp(s1, "-1") == 0) {
            printf("%d\n", cnt);
            cnt = 0;
            make_boss(mx);

        }
        else{
            scanf("%s", &s2);

            int x = atoi(s1);
            int y = atoi(s2);
            int u = find_boss(x);
            int v = find_boss(y);

            if(u != v) {
                boss[v] = u;
            }
            else {
                cnt += 1;
            }
        }
    }
    return 0;
}
