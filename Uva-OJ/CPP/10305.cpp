//------------------------------------
// Problem : 10305 - Ordering Tasks.
// Verdict : Accepted.
// Write   : Mehadi Hasan Menon.
// Algorithm : DFS, Topological Sort.
// Date : 15.04.16, Time : 0.00 ms.
//------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int max_size = 105;

vector <int> edge[max_size];
bool is_visited[max_size] = {false}; // default false;
vector <int> top_list;

void topological_sort_using_DFS(int node)
{
	is_visited[node] = true;

	int child;

	for(int i = 0; i < edge[node].size(); i++)
	{
		child = edge[node][i];

		if(is_visited[child] == false)
		{
			topological_sort_using_DFS(child);
		}
	}

	top_list.push_back(node);
}


int main()
{
	freopen("10305.txt", "r+", stdin);

	int n, m; // m is the precedence relations

	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) {
			break;
		}

		int i, j;

		for(int r = 0; r < m; r++)
		{
			cin >> i >> j;

			edge[i].push_back(j);
		}

        // TRICK ..
        // The whole graph may not be connected on a single node
        // this why we have to check each graph separately :)

		for(int r = 1; r <= n; r++)
		{
			if(is_visited[r] == false)
			{
				topological_sort_using_DFS(r);
			}
		}

		reverse(top_list.begin(), top_list.end());

		for(int i = 0; i < top_list.size(); i++)
		{
			if(i > 0) // skip last space.
			{
				printf(" ");
			}
			cout << top_list[i];
		}
		printf("\n");

		// reset everything :)

		top_list.clear();

		for(int i = 0; i <= n; i++)
		{
			is_visited[i] = false;

			edge[i].clear();
		}
	}

	return 0;  
}
