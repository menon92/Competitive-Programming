/**
  * Problem : 11396 - Claw Decomposition.
  * Verdict : Accepted.
  * Author : Mehadi Hasan Menon.
  * Algorithm : DFS.
  * Date : 27.07.2016.
  **/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: vector;
using std :: queue;

const int mx = 307;
vector <int> graph[mx];

bool isBipartite(int node)
{
    int color[node + 1];
    queue <int> q;
    int u, v;

    for(int i = 1; i <= node; i++) {
        color[i] = -1; // no color.
    }

    q.push(1);
    color[1] = 1;

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i];

            if(color[u] == color[v]) { // same color.
                return false;
            }
            if(color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }
    return true;

}
int main()
{
//    freopen("isBipartite.txt", "r+", stdin);

    int node, u, v;

    while(cin >> node && node != 0)
    {
        while(cin >> u >> v && u != 0 && v != 0)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(isBipartite(node)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        for(int i = 0; i <= node; i++) {
            graph[i].clear();
        }
    }

    return 0;
}
