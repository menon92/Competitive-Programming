/**
  * Problem : 10842 - Traffic Flow.
  * Verdict : Accepted.
  * Time    : 0.060 ms.
  * Writer  : Mehadi Hasan Menon.
  **/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

const int mx = 105;
int graph[mx][mx];
int root[mx];

struct edge {
    int u, v, w;
    bool operator < (const edge &p) const {
        return w > p.w;
    }
};
void init(int n) {
    for(int i = 0; i < n; i++) {
        root[i] = i;
    }
}
int find_root(int x) {
    return (root[x] == x) ? x : root[x] = find_root(root[x]);
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc, n, m, x, y, c;

    scanf("%d", &tc);
    for(int t = 1; t <= tc; t++)
    {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &c);

            if(graph[x][y] != 0)
                graph[x][y] = max(graph[x][y], c);
            else {
                graph[x][y] = c;
            }
        }
        vector <edge> edge_list;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && graph[i][j] != 0) {
                    edge e;

                    e.u = i, e.v = j, e.w = graph[i][j];
                    edge_list.push_back(e);
                }
            }
        }
        sort(edge_list.begin(), edge_list.end());

        int sz, min_cost;

        sz = edge_list.size();
        min_cost = INT_MAX;

        init(n);

        for(int i = 0; i < sz; i++)
        {
            int u = find_root(edge_list[i].u);
            int v = find_root(edge_list[i].v);

            if(u != v) {
                root[v] = u;
                min_cost = min(min_cost, edge_list[i].w);
            }
        }
        printf("Case #%d: %d\n", t, min_cost);
    }

    return 0;
}
