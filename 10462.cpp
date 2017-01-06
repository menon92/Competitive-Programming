/**
  * Problem : 10462 - Is There A Second Way Left?
  * Verdict : Accepted.
  * Time    : 0.010 ms.
  * Writer  : Mehadi Hasan Menon.
  ****/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct edge {
    int u, v, w;
    bool taken;
    bool operator < (const edge &p) const {
        return w < p.w;
    }
};
const int mx = 105;
const int inf = INT_MAX;
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
bool is_same_set(int x, int y) {
    return (find_boss(x) == find_boss(y)) ? true : false;
}
int get_1st_mst(int n)
{
    int min_cost, sz;

    init_boss(n);
    sort(edge_list.begin(), edge_list.end());
    sz = edge_list.size();
    min_cost = 0;

    for(int i = 0; i < sz; i++)
    {
        int u = find_boss(edge_list[i].u);
        int v = find_boss(edge_list[i].v);

        if(u != v) {
            boss[v] = u;
            min_cost += edge_list[i].w;
            edge_list[i].taken = true;
        }
    }
    return min_cost;
}

int get_2nd_mst(int n)
{
    int sz, min_cost;

    sz = edge_list.size();
    min_cost = inf;

    for(int i = 0; i < sz; i++)
    {
        if(edge_list[i].taken == true)
        {
            int tmp_cost = 0, tmp = edge_list[i].w;
            edge_list[i].w = inf;
            init_boss(n);

            for(int j = 0; j < sz; j++)
            {
                int u = find_boss(edge_list[j].u), v = find_boss(edge_list[j].v);

                if(u != v && edge_list[j].w != inf) {
                    boss[v] = u;
                    tmp_cost += edge_list[j].w;
                }
            }
            edge_list[i].w = tmp;

            // check is it possible to create MST or not
            for(int i = 2; i <= n; i++) {
                if(is_same_set(i, 1) == false) {
                    tmp_cost = inf;
                    break;
                }
            }
            min_cost = min(min_cost, tmp_cost);
        }
    }
    return min_cost;
}
int main()
{
    freopen("input.txt", "r+", stdin);

    int tc, v, e, start, end, cost;

    scanf("%d", &tc);
    for(int t = 1; t <= tc; t++)
    {
        scanf("%d %d", &v, &e);

        for(int i = 0; i < e; i++)
        {
            scanf("%d %d %d", &start, &end, &cost);

            edge e;
            e.u = start, e.v = end, e.w = cost, e.taken = false;
            edge_list.push_back(e);
        }
        int cost1 = get_1st_mst(v);
        bool flag = false;

        for(int i = 2; i <= v; i++) {
            if(is_same_set(i, 1) == false) {
                flag = true;
                break;
            }
        }
        printf("Case #%d : ", t);
        if(flag) {
            printf("No way\n");
        }
        else {
            if(v == e + 1) {
                printf("No second way\n");
            }
            else {
                // if cost1 == cost2 then it's treated as 2nd Way :)
                int cost2 = get_2nd_mst(v);

                printf("%d\n", cost2);
            }
        }
        edge_list.clear();
    }
    return 0;
}
