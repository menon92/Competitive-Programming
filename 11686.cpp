/**
  * Problem : 11686 - Pick up sticks
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 14.02.2018
  */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000000 + 7;
vector <vector <int> > adj_list;
vector <int> top_sort;
int is_vis[MAX];
bool is_possible;
bool flag;

void dfs(int u)
{
    is_vis[u] = 1;
    int sz = adj_list[u].size();

    for(int i = 0; i < sz; i++)
    {
        int v = adj_list[u][i];
        if(is_vis[v] == 0) {
            dfs(v);
        }
        else if(is_vis[v] == 1) {
            flag = false;
            return;
        }
    }
    is_vis[u] = 2;
    top_sort.push_back(u);
}

int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("out.txt", "r+", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;

    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) {
            break;
        }

        adj_list.resize(n + 7);
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj_list[u].push_back(v);
        }

        memset(is_vis, 0, sizeof(is_vis));
        flag = true;

        for(int i = 1; i <= n; i++)
        {
            if(is_vis[i] == false) {
                dfs(i);
                if(flag == false) {
                    break;
                }
            }
        }

        if(flag)
        {
            int sz = top_sort.size();
            for(int i = sz - 1; i >= 0; i--) {
                cout << top_sort[i] << endl;
            }
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
        top_sort.clear();
        adj_list.clear();
    }


    return 0;
}
