//-------------------------------------
// Problem : 11060-Beverage.
// Verdict : Accepted, Time : 0.00 ms.
// Write : Mehadi Hasan Menon.
// Date : 17.04.16.
//-------------------------------------
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
    freopen("11060.txt", "r+", stdin);

    int n, tcase;

    tcase = 1;

    while(cin >> n)
    {
        bool graph[n][n];
        bool is_visited[n];
        int indegree[n];

        // reset everything

        for(int i = 0; i < n; i++)
        {
            indegree[i] = 0;
            is_visited[i] = false;

            for(int j = 0; j < n; j++)
            {
                graph[i][j] = false;
            }
        }

        // take input 1st part

        string beverage_list[n], beverage_name;
        map <string, int> index;

        for(int i = 0; i < n; i++)
        {
            cin >> beverage_name;

            beverage_list[i] = beverage_name;
            index[beverage_name] = i;

        }

        // take input 2nd part

        int edge;
        string b1, b2;

        cin >> edge;
        for(int e = 0; e < edge; e++)
        {
            cin >> b1 >> b2;

            // b1 --> b2 so indegree of b2 must increment by 1

            // TRIK- This if for skip duplicate edge
            // EX- a->b, a->b, in this case b must increment only 1st time
            if(graph[index[b1]][index[b2]] == false)
            {
                graph[index[b1]][index[b2]] = true;

                indegree[index[b2]]++; // calculate indegree of each node
            }

        }

        // topologica sort iterative version

        vector <string> top_sorting_list;

        for(int i = 0; i < n; i++) // coz.. we have to take n item.
        {
            // every time we start from the 1st item.
            for(int j = 0; j < n; j++)
            {
                if(indegree[j] == 0 && is_visited[j] == false)
                {
                    top_sorting_list.push_back(beverage_list[j]);

                    is_visited[j] = true;


                    // decrease indegree of all node which is connected to node j
                    for(int k = 0; k < n; k++)
                    {
                        if(graph[j][k] == true)  // if j-->k = true;
                        {
                            indegree[k]--;
                        }
                    }
                    // we have take one item. new break the loop
                    // and start from the 1st item;
                    break;
                }
            }
        }

        // print the sorted list.

        printf("Case #%d: Dilbert should drink beverages in this order:", tcase++);
        for(int i = 0; i < top_sorting_list.size(); i++) {
            cout << " " << top_sorting_list[i];
        }
        printf("."); printf("\n"); printf("\n");
    }

    return 0;
}
