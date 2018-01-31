/**
  * Problem : 11838 - Come and Go 
  * Writer  : Mehadi Hasan Menon
  * Verdict : Accepted.
  * Date    : 31.01.2018
  */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 2000 + 10;
vector <int> adjList[MAX];
vector <int> adjListT[MAX];
vector <int> top_sort;
bool vis[MAX];

void kosaraju(int u, int pass)
{
	vis[u] = true;
	vector <int> neighbor;

	pass == 1 ? neighbor = adjList[u] : neighbor = adjListT[u];

	for(int i = 0; i < neighbor.size(); i++) {
		int v = neighbor[i];
		if(vis[v] == false) {
			kosaraju(v, pass);
		}
	}
	top_sort.push_back(u);
}


int main()
{
	// freopen("input.txt", "r+", stdin);

	int n, m, v, w, p;

	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) {
			break;
		}

		for(int i = 0; i < m; i++)
		{
			cin >> v >> w >> p;
			adjList[v].push_back(w);
			adjListT[w].push_back(v);

			if(p == 2) {
				adjList[w].push_back(v);
				adjListT[v].push_back(w);
			}
		}

		for(int i = 1; i <= n; i++) {
			vis[i] = false;
		}

		for(int i = 1; i <= n; i++) {
			if(vis[i] == false) {
				kosaraju(i, 1);
			}
		}

		for(int i = 1; i <= n; i++) {
			vis[i] = false;
		}

		int scc = 0;
		for(int i = top_sort.size() - 1; i >= 0; i--)
		{
			int u = top_sort[i];
			if(vis[u] == false)
			{
				scc += 1;
				kosaraju(u, 2);

				if(scc > 1) {
					break;
				}
			}
		}

		// printf("scc = %d\n", scc);
		scc == 1 ? puts("1") : puts("0");

		for(int i = 1; i <= n; i++) {
			adjList[i].clear();
			adjListT[i].clear();
		}
		top_sort.clear();

	}


	return 0;
}
