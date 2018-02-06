//------------------------------------------------
// Problem : 11518-Dominos - 2.
// Verdict : Accepted.
// Write: Mehadi Hasan Menon.
// Algorithm : DFS
// Time taken : scanf() 0.010 ms, cout 0.030 ms
// -----------------------------------------------
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int max_lim = 10005;
int total_dominos_fall = 0;
vector <int> edge[max_lim];
bool vis[max_lim] = {false};

void DFS(int node)
{
	vis[node] = true;

	total_dominos_fall++;

	for(int i = 0; i < edge[node].size(); i++)
	{
		if(vis[edge[node][i]] == false)
		{
			DFS(edge[node][i]);
		}
	}
}

int main()
{
	freopen("11518.txt", "r+", stdin);

	int tcase, n, m, l;
	int x, y, domino;

	//cin >> tcase;
	scanf("%d", &tcase);

	for(int i = 0; i < tcase; i++)
	{
		//cin >> n >> m >> l;
		scanf("%d %d %d", &n, &m, &l);

		for(int e = 0; e < m; e++)
		{
			//cin >> x >> y;
			scanf("%d %d", &x, &y);

			edge[x].push_back(y);
		}

		for(int d = 0; d < l; d++)
		{
			//cin >> domino;
			scanf("%d", &domino);

			if(!vis[domino])
			{
				DFS(domino);
			}
		}

		//cout << total_dominos_fall << endl;
		printf("%d\n", total_dominos_fall);

		// reset everything

		total_dominos_fall = 0;
		for(int j = 0; j <= n; j++)
		{
			vis[j] = false;
			edge[j].clear();
		}
	}

	return 0;
}
