/**********************
 * Problem : Risk-567
 * Status : Accepted.
 * Date : 25.01.2016.
 *********************/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

vector <int> graph[25];
const int infinity = 10;

int bfs(int source, int destination)
{
    int d[25];

    memset(d, infinity, sizeof(d));

    queue <int> QQ;

    QQ.push(source);
    d[source] = 0;

    while(!QQ.empty())
    {
        int p = QQ.front(); int vsize = graph[p].size();
        for(int i = 0; i < vsize; i++)
        {
            int child = graph[p][i];

            if(d[child] > d[p] + 1)
            {
                d[child] = d[p] + 1;

                QQ.push(child);
            }
        }
        // kaj sesh :) now pop it out;
        QQ.pop();
    }

    return d[destination];
}


int main()
{
    int x, y, i, tcase;

   // freopen("567.txt", "r+", stdin);

    i = 1; tcase = 1;
    while(cin >> x)
    {
        for(int j = 0; j < x; j++)
        {
            cin >> y;
            graph[i].push_back(y);
            graph[y].push_back(i);
        }

        if(i == 19)
        {
            int n, source, destination, pathDistance;

            cin >> n;
            cout << "Test Set #" << tcase++ << endl;
            for(int k = 0; k < n; k++)
            {
                cin >> source >> destination;

                pathDistance = bfs(source, destination);

                // print number as right justify.
                printf("%2d to %2d: %d\n", source, destination, pathDistance);
            }
            printf("\n");
            i = 0;

            // clear graph data;
            for(int k = 0; k < 25; k++) {
                graph[k].clear();
            }

        }
        i++;
    }

	return 0;
}
