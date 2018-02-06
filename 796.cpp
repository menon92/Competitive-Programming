/**
  * Problem : 796 - Critical Links 
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 06.02.2018
  */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 7;
vector <int> adj_list[MAX];
vector <pair <int, int> > links;
pair <int, int> pii;
bool is_vis[MAX];
int dfs_num[MAX], dfs_low[MAX], parent[MAX], dfs_num_counter;

void critical_links(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_num_counter++;
	is_vis[u] = true;

	int sz = adj_list[u].size();
	for(int i = 0; i < sz; i++)
	{
		int v = adj_list[u][i];
		if(is_vis[v] == false)
		{
			parent[v] = u;
			critical_links(v);

			if(dfs_low[v] > dfs_num[u])
			{
				pii.first = u;
				pii.second = v;
				if(u > v) {
                    swap(pii.first, pii.second);
				}
				links.push_back(pii);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}


int main()
{
	freopen("input.txt", "r+", stdin);
    freopen("out.txt", "r+", stdout);

	int n, u, v, n_v;
	char bracs;

	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> u >> bracs >> n_v >> bracs;
			// cout << u << " " << n_v;
			for(int j = 0; j < n_v; j++)
			{
				cin >> v;
				// cout << " " << v;
				adj_list[u].push_back(v);
				adj_list[v].push_back(u);
			}
		}

		for(int i = 0; i < n; i++) {
			is_vis[i] = false;
		}

		for(int i = 0; i < n; i++)
		{
			if(is_vis[i] == false)
			{
				critical_links(i);
			}
		}
        sort(links.begin(), links.end());

		cout << links.size() << " critical links" << endl;
		for(vector <pair <int, int> > :: iterator it = links.begin(); it != links.end(); ++it) {
			cout << it->first << " - " << it->second << endl;
		}
		cout << endl;

		// reset
		dfs_num_counter = 0;
		links.clear();
		for(int i = 0; i < n; i++) {
			adj_list[i].clear();
		}
	}

	return 0;
}
