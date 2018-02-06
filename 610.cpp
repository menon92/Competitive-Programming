#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000 + 7;
vector <int> adj_list[MAX];
vector <pair <int, int> > bridges, edge_list;
int dfs_num[MAX], dfs_low[MAX], parent[MAX], dfs_num_counter;
bool is_vis[MAX], roads[MAX][MAX];

void get_bridges(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_num_counter++;
	int sz = adj_list[u].size();
	is_vis[u] = true;

	for(int i = 0; i < sz; i++)
	{
		int v = adj_list[u][i];
		if(is_vis[v] == false)
		{
			parent[v] = u;
			get_bridges(v);
			if(dfs_low[v] > dfs_num[u]) {
				// bridges.push_back(make_pair(u, v));
				roads[u][v] = roads[v][u] = true;
			}
			else if(roads[v][u] == false) {
                roads[u][v] = true;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if(v != parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			if(roads[v][u] == false) {
                roads[u][v] = true;
			}
		}
	}

}


int main()
{
	 freopen("input.txt", "r+", stdin);
	 freopen("out.txt", "r+", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, u, v;
	int tc = 1;

	while(cin >> n >> m)
	{
		if(!n && !m) {break;}

		for(int i = 0; i < m; i++)
		{
			cin >> u >> v;
			// edge_list.push_back(make_pair(u, v));
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		for(int i = 1; i <= n; i++) {
			is_vis[i] = false;
		}

		dfs_num_counter = 0;
		for(int i = 1; i <= n; i++)
		{
			if(is_vis[i] == false)
			{
				get_bridges(i);
			}
		}

		cout << tc++ << endl;
		cout << endl;
//		for(vector <pair <int, int> > :: iterator it = edge_list.begin(); it != edge_list.end(); ++it) {
//			int u = it->first;
//			int v = it->second;
//			cout << u << " " << v << endl;
//			if(find(bridges.begin(), bridges.end(), make_pair(u, v)) != bridges.end() ||
//				find(bridges.begin(), bridges.end(), make_pair(v, u)) != bridges.end()) {
//				cout << v << " " << u << endl;
//			}
//
//		}

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(roads[i][j] == true)
                {
                    cout << i << " " << j << endl;
                }
            }
        }

		cout << "#" << endl;

		// reset
		bridges.clear();
		// edge_list.clear();
		for(int i = 1; i <= n; i++) {
			adj_list[i].clear();
			dfs_num[i] = dfs_low[i] = parent[i] = -1;
		}
		memset(roads, 0, sizeof(roads));
	}

	return 0;
}
