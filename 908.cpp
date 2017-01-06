/**
  * Problem : 908 - Re-connecting Computer Sites
  * Verdict : Accepted.
  * Time    : 0.00 ms.
  * Writer  : Mehadi Hasan Menon.
  ****/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w;
    bool operator < (const edge &p) const {
        return w < p.w;
    }
};

const int mx = 1000005;
int boss[mx];
vector <edge> edge_list;

void init_boss(int n) {
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

    int n, u, v, cost;
    bool flag = false;

    while(scanf("%d", &n) == 1)
    {
        int total = 0;

        for(int i = 0; i < n - 1; i++) {
            scanf("%d %d %d", &u, &v, &cost);
            total += cost;
        }
        int k, m;
        scanf("%d", &k);

        for(int i = 0; i < k; i++) {
            scanf("%d %d %d", &u, &v, &cost);
            edge e;
            e.u = u, e.v = v, e.w = cost, edge_list.push_back(e);
        }
        scanf("%d", &m);

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &cost);
            edge e;
            e.u = u, e.v = v, e.w = cost, edge_list.push_back(e);
        }
        sort(edge_list.begin(), edge_list.end());
        init_boss(n);
        int sz = edge_list.size(), min_cost = 0;

        for(int i = 0; i < sz; i++) {
            int u = find_boss(edge_list[i].u), v = find_boss(edge_list[i].v);
            if(u != v) {
                boss[v] = u;
                min_cost += edge_list[i].w;
            }
        }
        if(flag) {
            puts("");
        }
        flag = true;

        printf("%d\n%d\n", total, min_cost);

        edge_list.clear();
    }

    return 0;
}
