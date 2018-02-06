#include <iostream>
#include <cstdio>
#include <algorithm>
#include <exception>

using namespace std;

const int M = 101;
const int infinity = 100000000;
int graph[M][M];

void reset()
{
    for(int i = 1; i < M; i++)
    {
        for(int j = 1; j < M; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = infinity;
        }
    }
}

void floyd_warshall(int max_node)
{
    int i, j, k;

    for(int k = 1; k <= max_node; k++)
    {
        for(int i = 1; i <= max_node; i++)
        {
            for(int j = 1; j <= max_node; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

// average shortest path length between every pair of nodes

double average_path_length(int max_node)
{
    double sum = 0;
    double number_of_total_edge = 0;

    for(int i = 1; i <= max_node; i++)
    {
        for(int j = 1; j <= max_node; j++)
        {
            if(graph[i][j] != infinity && graph[i][j] != 0)
            {
                sum += graph[i][j];

                number_of_total_edge++;
            }
        }
    }

    return sum / number_of_total_edge;
}

int main()
{
    freopen("821.txt", "r+", stdin);

    int tcase, u, v;
    tcase = 1;

    while(scanf("%d %d", &u, &v) && u != 0 && v != 0)
    {
        reset();

        int max_node = 1;

        max_node = max(max_node, max(u, v));

        graph[u][v] = 1;

        while(scanf("%d %d", &u, &v) && u != 0 && v != 0)
        {
            graph[u][v] = 1;

            max_node = max(max_node, max(u, v));
        }

        floyd_warshall(max_node);

        printf("Case %d: average length between pages = ", tcase);
        printf("%.3lf clicks\n", average_path_length(max_node));

        tcase++;
    }

    return 0;
}
