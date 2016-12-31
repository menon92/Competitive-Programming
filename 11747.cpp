/**
  * Problem : 11747 - Heavy Cycle Edges.
  * Verdict : Accepted.
  * Time    : 0.000 ms.
  * Write   : Mehadi Hasan Menon.
  * Date    : 01.01.2017.
  **/
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
const int mx = 1005;
int father[mx];
vector <int> max_weight;
vector <edge> edge_list;

int find_rep(int r)
{
    if(father[r] == r) {
        return r;
    }
    father[r] = find_rep(father[r]);
    return father[r];
}

void mst_kruskal(int n)
{
    // initialize father 1st time.
    for(int i = 0; i < n; i++) {
        father[i] = i;
    }
    edge new_edge;
    int sz = edge_list.size();

    for(int i = 0; i < sz; i++) {
        new_edge = edge_list[i];
        int u = find_rep(new_edge.u);
        int v = find_rep(new_edge.v);

        if(u == v) {
            // we meet with cycle. so take the weight of the new edge.
            max_weight.push_back(new_edge.w);
        }
        else {
            // set u as father of v.
            father[v] = u;
        }
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int n, m, u, v, w;

    while(scanf("%d %d", &n, &m))
    {
        if(n == 0 && m == 0) {
            break;
        }
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            edge_list.push_back(get);
        }
        sort(edge_list.begin(), edge_list.end());

        mst(n);

        int sz = max_weight.size();
        if(sz == 0) {
            cout << "forest" << endl;
        }
        else {
            for(int i = 0; i < sz; i++) {
                if(i > 0) {
                    printf(" ");
                }
                printf("%d", max_weight[i]);
            }
            puts("");
        }
        max_weight.clear();
        edge_list.clear();
    }
    return 0;
}
