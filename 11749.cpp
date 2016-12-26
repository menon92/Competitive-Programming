/**
  * Problem : 11749 - Poor Trade Advisor.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 26.12.16.
  **/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

const int mx = 505;

vector <int> network[mx];

int road_ppa[mx][mx];
bool visited[mx];
int max_ppa;

int dfs_count_node(int src_node)
{
    stack <int> si;
    int number_of_city = 1;

    si.push(src_node);
    visited[src_node] = true;

    while(!si.empty())
    {
        int u = si.top();
        si.pop();

        for(int i = 0; i < network[u].size(); i++)
        {
            int v = network[u][i];

            if( road_ppa[u][v] != max_ppa)
            {
                continue; // skip this road :)
            }

            if(visited[v] == false)
            {
                si.push(v);
                visited[v] = true;

                number_of_city += 1;
            }
        }
    }

    return number_of_city;
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int n, m, x, y;
    int ppa;

    while(scanf("%d %d", &n, &m) && n != 0 && m != 0)
    {
        max_ppa = -2147483648;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                road_ppa[i][j] = max_ppa;
            }
        }

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &ppa);

            network[x].push_back(y);
            network[y].push_back(x);

            road_ppa[x][y] = road_ppa[y][x] = max(road_ppa[x][y], ppa);

            max_ppa = max(max_ppa, ppa);
        }

        int max_number_of_city = 0;

        for(int node = 1; node <= n; node++)
        {
            if(visited[node] == false)
            {
                int new_number_of_city = dfs_count_node(node);

                max_number_of_city = max(max_number_of_city, new_number_of_city);
            }
        }

        printf("%d\n", max_number_of_city);

        for(int i = 1; i <= n; i++)
        {
            visited[i] = false;
            network[i].clear();
        }
    }

    return 0;
}
