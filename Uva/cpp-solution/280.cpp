//--------------------------------------
// Problem : Vertex - 280.
// Status  : Accepted.
// Author  : Mehadi Hasan Menon.
// Date    : 10.04.16.
//--------------------------------------
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int const max_size = 105;
vector <int> edge[max_size];
int visited[max_size];
int count = 0;

void dfs(int p)
{
    for(int i = 0; i < edge[p].size(); i++)
    {
        if(!visited[edge[p][i]])
        {
            count++;

            visited[edge[p][i]] = 1;

            dfs(edge[p][i]); // recursive call to go more dipper
        }
    }
}

int main()
{
    freopen("280.txt", "r+", stdin);

    int n, x, y;
    int vertices, starting_node;

    while(cin >> n && n != 0)
    {
        while(cin >> x && x != 0)
        {
            while(cin >> y && y != 0)
            {
                edge[x].push_back(y);
            }
        }

        cin >> vertices;
        for(int i = 0; i < vertices; i++)
        {
            cin >> starting_node;

            dfs(starting_node);

            printf("%d", n - count); // number of inaccessible node from source.
            for(int i = 1; i <= n; i++)
            {
                if(visited[i] == 0)
                {
                    printf(" %d", i);
                }
            }
            printf("\n");

            for(int i = 1; i <= n; i++) {
                visited[i] = 0;
            }

            count = 0;
        }

        // clear the graph;
        for(int i = 0; i <= n; i++)
        {
            edge[i].clear();
        } 
    }
}
