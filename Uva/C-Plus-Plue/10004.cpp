#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

vector <int> graph[200 + 5];

bool bfs(int src)
{
	queue <int> Q;
	int visited[200 + 5];

        memset(visited, -1, sizeof(visited));

	Q.push(src); // hare 0 is src node.
	visited[src] = 0;

	while(!Q.empty())
	{
		int parent = Q.front();
                int vsize = graph[parent].size();
		for(int i = 0; i < vsize; i++)
		{
			int child = graph[parent][i];

			if(visited[child] == -1) // if not visited.
			{
				// 0 is to colour1 and 1 is to colour2;
				// if parent node is 0 then child node must be 1;
				// otherwise it is not bicolour;
                                Q.push(child);
				if(visited[parent] == 0)
				{
					visited[child] = 1;
				}
				else if(visited[parent] == 1)
				{
					visited[child] = 0;
				}
			}
			else {
				// if this node is already visited then check
				// parent and child node is different colour.

				if(visited[parent] == visited[child])
					return false;
			}
		}
		Q.pop();
	}
	return true;
}

int main()
{
	int node, edge;

	//freopen("10004.txt", "r+", stdin);

	while(cin >> node)
	{
		if(node == 0) break;

		cin >> edge;
		int x, y;
		memset(graph, 0, sizeof(graph));

		for(int i = 0; i < edge; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		if(bfs(0) == true)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;

	}

	return 0;  
}
