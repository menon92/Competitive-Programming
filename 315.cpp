/**
  * Problem : 315 - Network 
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 06.02.2018
  */
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

const int MAX = 100 + 7;
vector <int> adjList[MAX];
bool is_visited[MAX], is_artculation_vertex[MAX];
int dfs_num[MAX], dfs_low[MAX], dfs_parent[MAX];
int dfs_root, dfs_root_child, dfs_num_counter;


void articulation_points(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_num_counter++;
	is_visited[u] = true;
	int sz = adjList[u].size();

	for(int i = 0; i < sz; i++)
	{
		int v = adjList[u][i];
		if(is_visited[v] == false)
		{
			if(u == dfs_root) {
				dfs_root_child += 1;
			}
			dfs_parent[v] = u;
			articulation_points(v);

			// check u is articulation point or not
			if(dfs_low[v] >= dfs_num[u]) {
				is_artculation_vertex[u] = true;
			}
			// update dfs_low[u]
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);

		}
		else if(v != dfs_parent[u]) {
			// this is back edge
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main()
{
//	 freopen("input.txt", "r+", stdin);
//	 freopen("out.txt", "r+", stdout);

	int n, u, v;
	int tc = 1;

	while(cin >> n)
	{
		cin.ignore();
		if(n == 0) {
			break;
		}
        string line;
		for(int i = 0; i <= n; i++)
		{
            getline(cin, line);
            if(line == "0") {
                break;
            }
            stringstream ss(line);
            ss >> u;
            // cout << "u = " << u << endl;
            // cout << "vs = ";
            while(ss >> v) {
                // cout << v << " ";
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            // cout << endl;
		}

		for(int i = 1; i <= n; i++) {
			is_visited[i] = false;
		}

		for(int i = 1; i <= n; i++)
		{
			if(is_visited[i] == false)
			{
				dfs_root = i;
				dfs_root_child = 0;

				articulation_points(i);

				is_artculation_vertex[dfs_root] = dfs_root_child > 1;
			}
		}

		int critical_points = 0;
		for(int i = 1; i <= n; i++)
		{
			if(is_artculation_vertex[i] == true) {
				critical_points += 1;
			}
		}
		// cout << "Case " << tc++ << ": " << critical_points << endl;
        cout << critical_points << endl;
		// reset everything.
		for(int i = 1; i <= n; i++) {
			adjList[i].clear();
			dfs_low[i] = dfs_num[i] = dfs_parent[i] = 0;
			is_artculation_vertex[i] = false;
			dfs_num_counter = 0;
		}
	}


	return 0;
}
