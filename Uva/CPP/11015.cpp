//--------------------------------------------
// Problem : 11015 - 05-2 Rendezvous
// Verdict : Accepted.
// Writer : Mehadi Hasan Menon.
// Algorithm : Floyd Warshall. Time : 0.00 ms
// Date : 29.04.16.
//---------------------------------------------
// trick : edge = 0
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 25;
const int infinity = 10000008;
int graph[N][N];

void reset(int node)
{
    for(int i = 1; i <= node; i++)
    {
        for(int j = 1;  j <= node; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = infinity;
            }
        }
    }
}

void floyd_warshall(int node)
{
    int i, j, k;

    for(k = 1; k <= node; k++)
    {
        for(i = 1; i <= node; i++)
        {
            for(j = 1; j <= node; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int calculate_min_cost(int node)
{
    int sum, min_cost = infinity;
    int i, j, index;

    index = 1;
    for(i = 1; i <= node; i++)
    {
        sum = 0;

        for(j = 1; j <= node; j++)
        {
            if(graph[i][j] != infinity && i != j)
            {
                sum += graph[i][j];
            }
        }
        if(sum < min_cost)
        {
            min_cost = sum;
            index = i;
        }
    }
    return index;
}

int main()
{
    freopen("11015.txt", "r+", stdin);
    freopen("11015_out.txt", "r+", stdout);

    int node, edge, tcase;
    int u, v, cost;
    tcase = 1;

    while(cin >> node >> edge)
    {
        if(node == 0 && edge == 0)
            break;

        reset(node);

        string str, name[node + 3];

        for(int i = 1; i <= node; i++)
        {
            cin >> str;
            name[i] = str;
        }

        for(int i = 0; i < edge; i++)
        {
            cin >> u >> v >> cost;

            graph[u][v] = cost;
            graph[v][u] = cost;
        }
        floyd_warshall(node);
        int index = calculate_min_cost(node);

        cout << "Case #" << tcase << " : " << name[index] << endl;
        tcase++;
    }

    return 0;
}
