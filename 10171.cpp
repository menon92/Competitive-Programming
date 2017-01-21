/**
  * Problem : 10171 - Meeting Prof. Miguel
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : Accepted.
  **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mx = 27;
const int inf = 1000007;
int city_map_y[mx][mx], city_map_m[mx][mx];

void floyd_for_young(int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                city_map_y[i][j] = min(city_map_y[i][j], city_map_y[i][k] + city_map_y[k][j]);
            }
        }
    }
}
void floyd_for_old(int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                city_map_m[i][j] = min(city_map_m[i][j], city_map_m[i][k] + city_map_m[k][j]);
            }
        }
    }
}
void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) {
                city_map_y[i][j] = 0;
                city_map_m[i][j] = 0;
            }
            else {
                city_map_y[i][j] = inf;
                city_map_m[i][j] = inf;
            }
        }
    }
}
void create_map(int n)
{
    char y_or_m, u_or_b, city1, city2;
    int cost;

    for(int i = 0; i < n; i++)
    {
        cin.ignore();
        scanf("%c %c %c %c %d", &y_or_m, &u_or_b, &city1, &city2, &cost);

        int u = city1 - 'A';
        int v = city2 - 'A';

        // city map for young people.
        if(y_or_m == 'Y')
        {
            if(u_or_b == 'U') {
                city_map_y[u][v] = min(cost, city_map_y[u][v]);
            }
            else {
                city_map_y[u][v] = city_map_y[v][u] = min(cost, city_map_y[u][v]);
            }
        }
        // city map for old people.
        else
        {
            if(u_or_b == 'U') {
                city_map_m[u][v] = min(cost, city_map_m[u][v]);
            }
            else {
                city_map_m[u][v] = city_map_m[v][u] = min(cost, city_map_m[u][v]);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r+", stdin);

    char src, des;
    int n;
    while(scanf("%d", &n) && n != 0)
    {
        init(26);
        create_map(n);

        cin.ignore();
        scanf("%c %c", &src, &des);

        vector <pair<int, char>> vic;
        int u = src - 'A';
        int v = des - 'A';

        floyd_for_young(26); // find shortest path for me
        floyd_for_old(26);   // find shortest path for prof.

        for(int k = 0; k < 26; k++)
        {
            // if I can go from src to k and he can go des to k the save the location k;
            if(city_map_y[u][k] != inf && city_map_m[v][k] != inf) {
                vic.push_back( make_pair(city_map_y[u][k] + city_map_m[v][k], k + 'A') );
            }
        }
        if(vic.size() == 0) {
            printf("You will never meet.\n");
        }
        else
        {
            sort(vic.begin(), vic.end());

            int sz = vic.size();
            int ans = vic[0].first;

            cout << vic[0].first;
            for(int i = 0; i < sz; i++)
            {
                if(vic[i].first != ans) {
                    break;
                }
                cout << " " << vic[i].second;
            }
            cout << endl;
        }
    }
    return 0;
}
