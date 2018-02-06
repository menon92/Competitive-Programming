//-------------------------------------------
// Problem : 1112-Mice and Maze.
// Status  : Accepted. Algorithm : Dijkstra.
// Author  : Mehadi Hasan Menon.
// Time    : 0.00 ms.
// Date    : 25.03.16.
//-------------------------------------------

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int infinity = 100000000;
const int max_size = 100 + 5;

vector <int> maze[max_size];
vector <int> cost[max_size];

struct data
{
	int cell, time_cost;

	bool operator < (const data &p) const {
		return time_cost > p.time_cost;
	}
};

int dijkstra_find_shortest_path(int src, int size, int max_time_limit)
{
	int distance[size + 5];

	for(int i = 1; i <= size + 5; i++) {
		distance[i] = infinity;
	}

	priority_queue <data> pq;
	data u, v;

	u.cell = src;
	u.time_cost = 0;

	pq.push(u);
	distance[src] = 0;

	while(!pq.empty())
	{
		u = pq.top();
		pq.pop();

		int ucost = distance[u.cell];

		for(int i = 0; i < maze[u.cell].size(); i++)
		{
			v.cell = maze[u.cell][i];
			v.time_cost = ucost + cost[u.cell][i];

			if(v.time_cost < distance[v.cell])
			{
				distance[v.cell] = v.time_cost;

				pq.push(v);
			}
		}
	}

	int count = 0;

	for(int i = 1; i <= size; i++)
	{
		if(distance[i] <= max_time_limit) {
			count++;
		}
	}

	return count;
}

int main()
{
    freopen("1112.txt", "r+", stdin);

    int tcase, number_of_cells, number_of_exit_cell, max_time_limit;
    int maze_connections, x, y, time;

    cin >> tcase;

    while(tcase--)
    {
    	cin >> number_of_cells;
    	cin >> number_of_exit_cell;
    	cin >> max_time_limit;
    	cin >> maze_connections;

    	for(int i = 0; i < maze_connections; i++)
    	{
    		cin >> x >> y >> time;

              // this is for reverse connection of the graph.
    		maze[y].push_back(x);
    		cost[y].push_back(time);
    	}

        int passing_mices;

        passing_mices = dijkstra_find_shortest_path(number_of_exit_cell, number_of_cells, max_time_limit);

    	cout << passing_mices << endl;

    	// this is for skips last new line;
    	if(tcase) {
    		  cout << endl;
    	}

    	// clear the maze and cost it's vary important;
    	for(int i = 1; i <= number_of_cells; i++)
    	{
            maze[i].clear();
            cost[i].clear();
    	}
    }

    return 0;
}
