//-------------------------------------------
// Problem : 10926 - How Many Dependencies?
// Verdict : Accepted. Time : 0.00 ms.
// Writer : Mehadi Hasan Menon.
// Date : 14.04.16.
//-------------------------------------------
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector <int> edge[105];
bool visited[105];
int dependencies  = 0;

void DFS(int node)
{
    for(int i = 0; i < edge[node].size(); i++)
    {

        if(!visited[edge[node][i]])
        {
            visited[edge[node][i]] = true;

            dependencies++;

            DFS(edge[node][i]);
        }
    }
}

int main()
{
    // freopen("10926.txt", "r+", stdin);

    int node, t, n;

    while(cin >> node && node != 0)
    {
        int depen[node + 1];
        for(int i = 1; i <= node; i++)
        {
            cin >> t;
            for(int j = 0; j < t; j++)
            {
                cin >> n;

                edge[i].push_back(n);
            }
        }


        for(int i = 1; i <= node; i++)
        {
            memset(visited, false, sizeof(visited));

            DFS(i);

            depen[i] = dependencies;
            dependencies = 0;
        }

        int max_dependency = depen[1];
        int index = 1;

        for(int i = 2; i <= node; i++)
        {
            if(depen[i] > max_dependency)
            {
                //max_dependency = depen[i];
                index = i;
            }
        }

        cout << index << endl;

        for(int i = 1; i <= node; i++)
        {
            edge[i].clear();
        }

    }

    return 0;
}
