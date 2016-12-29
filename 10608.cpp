/**********************************
  * Problem : 10608 - Friends.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 29.12.16.
  ********************************/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mx = 30007;
int parent[mx];
int friend_size[mx];

int max_friend_size = 1;
// if M = 0 then friend size = 1

int make_set(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        friend_size[i] = 1;
    }
}

int find_parent(int r)
{
    if(parent[r] == r) {
        return r;
    }
    parent[r] = find_parent(parent[r]);

    return parent[r];
}

void union_ab(int a, int b)
{
    int u = find_parent(a);
    int v = find_parent(b);

    if(u != v)
    {
        parent[v] = u;
        friend_size[u] = friend_size[u] + friend_size[v];

        max_friend_size = max(max_friend_size, friend_size[u]);
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc, m, n, a, b;

    scanf("%d", &tc);
    for(int i = 0; i < tc; i++)
    {
        scanf("%d %d", &n, &m);

        make_set(n);

        for(int j = 0; j < m; j++)
        {
            scanf("%d %d", &a, &b);

            union_ab(a, b);
        }

        printf("%d\n", max_friend_size);

        max_friend_size = 1;
    }

    return 0;
}
