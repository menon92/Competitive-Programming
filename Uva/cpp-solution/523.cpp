//-----------------------------------------
// Problem : 523 - Minimum Transport Cost.
// Verdict : Accepted.
// Write : Mehadi Hasan Menon.
// Algorithm : Floyd Warshall, Time : 0.00.
//-----------------------------------------
#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

const int M = 150;
const int infinity = 99999999;
int graph[M][M];
int next[M][M];
int tax[M];

void print_matrix(int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall(int n)
{
    int i, j, k;

    for(k = 1; k < n; k++)
    {
        for(i = 1; i < n; i++)
        {
            for(j = 1; j < n; j++)
            {
                if(graph[i][j] > graph[i][k] + tax[k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + tax[k] + graph[k][j];

                    next[i][j] = next[i][k]; // track the path;
                }
            }
        }
    }
}

void print_shortest_path(int src, int destination)
{
    printf("From %d to %d :\n", src, destination);
    printf("Path: %d", src);
    int index = src;

    while(src != destination)
    {
        src = next[src][destination];

        printf("-->%d", src);
    }
    printf("\n");
    printf("Total cost : %d\n", graph[index][destination]);
}

int main()
{
    freopen("523.txt", "r+", stdin);

    int tcase;
    bool flag = false;

    cin >> tcase;
    cin.ignore(); // skipe 1st new line;
    cin.ignore(); // skipe 2nd new line;

    while(tcase--)
    {
        int cost, n;
        string first_line;
        istringstream iss;

        if(flag) // skip last extra new line
        {
            printf("\n");
        }
        flag = true;

        getline(cin, first_line);

        iss.str( first_line); // write data into iss;
        n = 1;
        while(iss >> cost)
        {
            if(cost == -1)
            {
                graph[1][n] = infinity;
            }
            else
            {
                graph[1][n] = cost;
            }
            next[1][n] = n;
            n++; // find length of our matrix :)
        }
        int u, v;
        for(int r = 2; r < n; r++)
        {
            for(int c = 1; c < n; c++)
            {
                cin >> cost;

                if(cost == -1)
                {
                    graph[r][c] = infinity;
                }
                else
                {
                    graph[r][c] = cost;
                }
                next[r][c] = c;
            }
        }

        for(int r = 1; r < n; r++)
        {
            cin >> tax[r];
        }
        floyd_warshall(n);

        int src, destination;
        string s;
        cin.ignore();
        iss.clear();
        bool flag2 = false;

        while(getline(cin, s))
        {
            if(s == "")
            {
                break;
            }
            iss.str(s);

            iss >> src;
            iss >> destination;

            if(flag2) // skip last extra new line;
            {
                printf("\n");
            }
            flag2 = true;

            print_shortest_path(src, destination);

            iss.clear(); 
        } 
    }
}
