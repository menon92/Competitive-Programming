//---------------------------------
// Problem : 10986-Sending email.
// Status  : Accepted.
// Algorithm : Dijkstra.
// Author : Mehadi Hasan Menon.
// AC Date : 25.03.2016.
//---------------------------------

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_SIZE = 20005;
const int infinity = 1000000000;

vector <int> graph[MAX_SIZE];
vector <int> cost[MAX_SIZE];


struct data
{
	int server, cost;

	bool operator < (const data &p) const
	{
		return cost > p.cost;
	}
};

int dijkstra(int src, int distination, int nServer)
{
	int d[nServer];

	for(int i = 0; i <= nServer; i++) {
		d[i] = infinity;
	}

	priority_queue <data> pq;
	data u, v;

	u.server = src;
	u.cost = 0;

	pq.push(u);
	d[src] = 0;

	int ucost;

	while(!pq.empty())
	{
		u = pq.top();
		pq.pop();

		ucost = d[u.server];

		for(int i = 0; i < graph[u.server].size(); i++)
		{
			v.server = graph[u.server][i];
			v.cost = ucost + cost[u.server][i];

			if(d[v.server] > v.cost)
			{
				d[v.server] = v.cost;

				pq.push(v);
			}
		}
	}

	return d[distination];
}

int main()
{
	//freopen("10986.txt", "r+", stdin);

	int tcase, nServer, mCables, s, t;

	cin >> tcase;

	for(int i = 0; i < tcase; i++)
	{
        cin >> nServer >> mCables;
        cin >> s >> t;

        cout << "Case #" << i + 1 << ": ";

        int server_x, server_y;
        int w;

        while(mCables--)
        {
            cin >> server_x >> server_y;
            cin >> w;

            graph[server_x].push_back(server_y);
            graph[server_y].push_back(server_x);

            cost[server_x].push_back(w);
            cost[server_y].push_back(w);
        }

        int distance;

        distance = dijkstra(s, t, nServer);

        if(distance == infinity)
        {
            cout << "unreachable" << endl;
        }
        else {
            cout << distance << endl;
        }

        // clear the full graph ans cost;

        for(int i = 0; i <= nServer; i++)
        {
            graph[i].clear();
            cost[i].clear();
        }

	}

	return 0;
}
