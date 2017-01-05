/**
  * Problem :  10600 - ACM Contest and Blackout.
  * Verdict : Accepted.
  * Time    : 0.00 ms.
  * Write   : Mehadi Hasan Menon.
  **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mx = 105;
const int inf = 10000007;
int father[mx];

struct edge {
    int u, v, w;
    bool taken;
    bool operator < (const edge &p) const{
        return w < p.w;
    }
};
vector <edge> edge_list;

int make_set(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}
int find_father(int x) {
   return (father[x] == x) ? x : father[x] = find_father(father[x]);
}
bool is_same_set(int x, int y) {
    return ( find_father(x) == find_father(y) ) ? true : false;
}
int get_1st_mst(int n)
{
    int tcost = 0;

    make_set(n);
    sort(edge_list.begin(), edge_list.end());

    int sz = edge_list.size();
    for(int i = 0; i < sz; i++)
    {
        edge e = edge_list[i];

        int u = find_father(e.u);
        int v = find_father(e.v);

        if(u != v)
        {
            father[v] = u;

            tcost += e.w;

            // flag this edge is taken in our MST
            edge_list[i].taken = true;
        }
    }
    return tcost;
}

int get_2nd_mst(int n)
{
    int min_cost = inf;
    int sz = edge_list.size();

    for(int i = 0; i < sz; i++)
    {
        if(edge_list[i].taken == true)
        {
            int tmp_w = edge_list[i].w;
            edge_list[i].w = inf; // set this edge weight to inf for not to take it
            int tmp_cost = 0;

            make_set(n);

            for(int j = 0; j < sz; j++)
            {
                edge e = edge_list[j];

                int u = find_father(e.u); int v = find_father(e.v);

                if(u != v && e.w != inf)
                {
                    father[v] = u;
                    tmp_cost += e.w;
                }
            }
            // reset w;
            edge_list[i].w = tmp_w;

            // check the edge excluding which we can't make MST
            // we can chacke by confirm that all the node is in same set
            for(int i = 1; i <= n; i++)
            {
                if(is_same_set(i, 1) == false)
                {
                    // we cant take this mst cost to set it inf
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

    int tc, n, m, x, y, cost;

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &cost);

            edge new_edge;

            new_edge.u = x;
            new_edge.v = y;
            new_edge.w = cost;

            new_edge.taken = false;

            edge_list.push_back(new_edge);
        }
        int best1 = get_1st_mst(n);
        int best2 = get_2nd_mst(n);

        printf("%d %d\n", best1, best2);

        edge_list.clear();
    }

    return 0;
}
