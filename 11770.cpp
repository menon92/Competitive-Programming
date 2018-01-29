/**
  * Problem : 11770 - Lighting Away 
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 29.01.2018
  */ 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 10000 + 10;
vector <int> adjList[MAX], top_sort;
bool vis[MAX];

void dfs(int u, int pass)
{
	vis[u] = true;

	int len = adjList[u].size();
	for(int i = 0; i < len; i++) 
	{
		int v = adjList[u][i];
		if(vis[v] == false) {
			dfs(v, pass);
		}
	}
	if(pass == 1) {
		top_sort.push_back(u);
	}
}

int get_min_num_of_light_need_to_on(int n)
{
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
	}

	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == false) {
			dfs(i, 1);
		}
	}

	// rest vis
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
	}

	int light_counter = 0;
	for(int i = top_sort.size() - 1; i >= 0; i--)
	{
		int u = top_sort[i];
		if(vis[u] == false) {
			light_counter += 1;
			dfs(u, 2);
		}
	}

	return light_counter;
}


int main()
{
	// freopen("input.txt", "r+", stdin);
	// freopen("out.txt", "r+", stdout);

	int t, n, m, a, b;

	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			adjList[a].push_back(b);
		}

		printf("Case %d: %d\n", tc, get_min_num_of_light_need_to_on(n));

		for(int i = 1; i <= n; i++) {
			adjList[i].clear();
		}
		top_sort.clear();
	}

	return 0;
}
