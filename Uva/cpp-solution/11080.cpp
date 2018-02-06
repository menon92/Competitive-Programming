/**
  * Problem : 11080 - Place the Guards.
  * Verdict : Accepted.
  * Author : Mehadi Hasan Menon.
  * Algorithm : DFS.
  * Date : 07.01.2016.
  **/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mx = 201;
int color[mx];
vector<int> graph[mx];

int BFS(int src)
{
    queue <int> q;
    int u, v, cnt_one, cnt_zero;
    bool adj_node = false;

    q.push(src);
    color[src] = 1;
    cnt_one = 1;
    cnt_zero = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i];
            adj_node = true;

            if(color[u] == color[v]) {
                return 0;
            }
            if(color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
                if(color[v] == 0) {
                    cnt_zero++;
                }
                else {
                    cnt_one++;
                }
            }
        }
    }
    if(adj_node == false) {
        return 1;
    }
    else {
        return min(cnt_one, cnt_zero);
    }
}

int main()
{
//    freopen("11080.txt", "r+", stdin);
//    freopen("out.txt", "r+", stdout);

    int tc, v, e;
    int x, y, ans;

    cin >> tc;
    while(tc--)
    {
        cin >> v >> e;
        for(int i = 0; i < e; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if(e == 0) {
            cout << v << endl;
        }
        else
        {
            for(int i = 0; i < v; i++) {
                color[i] = -1;
            }

            int tmp;
            ans = 0;
            for(int i = 0; i < v; i++)
            {
                if(color[i] == -1)
                {
                    tmp = BFS(i);
                    if(tmp == 0) {
                        break;
                    }
                    ans += tmp;
                }

            }
            if(tmp == 0) {
                cout << -1 << endl;
            }
            else {
                cout << ans << endl;
            }
            for(int i = 0; i < v; i++) {
                graph[i].clear();
            }
        }
    }
    return 0;
}
