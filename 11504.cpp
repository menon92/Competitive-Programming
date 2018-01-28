/**
  * Problem : 11504 - Dominos 
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 29.01.2018
  */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX = 100000 + 10;
vector <int> adjList[MAX];
vector <int> topological_order;
bool vis[MAX];

void dfs(int u, int pass)
{
	vis[u] = true;

	for(int i = 0; i < adjList[u].size(); i++) {
		int v = adjList[u][i];
		if(vis[v] == false) {
			dfs(v, pass);
		}
	}
	// collect top_sort only for first pass.
	if(pass == 1) {
        topological_order.push_back(u);
	}
}


int get_conected_component(int n)
{
    // init vis
    for(int i = 1; i <= n; i++) {
		vis[i] = false;
	}

	for(int i = 1; i <= n; i++) {
		if(vis[i] == false) {
			dfs(i, 1);
		}
	}
	// reset vis vector
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
	}

	int ans = 0;
	for(int i = topological_order.size() - 1; i >= 0; i--)
	{
		if(vis[topological_order[i]] == false)
		{
			ans += 1;
			dfs(topological_order[i], 2);
		}
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r+", stdin);
	freopen("out.txt", "r+", stdout);

	int tcase, u, v;
	int n, m;

	scanf("%d", &tcase);
	for(int tc = 1; tc <= tcase; tc++)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			adjList[u].push_back(v);
			vis[u] = vis[v] = false;
		}
		printf("%d\n", get_conected_component(n));

		topological_order.clear();
		for(int i = 1; i <= n; i++) {
			adjList[i].clear();
		}
	}

	return 0;
}
