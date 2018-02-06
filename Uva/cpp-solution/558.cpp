/**
  * Problem : 558 - Wormholes.
  * Author : Mehadi Hasan Menon.
  * Algorithm : Bellman Ford.
  * Verdict : Accepted.
  * Date : 17-06-2016.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

#define inf  10000000007

void bellman()
{
    int n, m, t;
    int edge_u[2007], edge_v[2007], d[2007], costs[2007];

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        d[i] = inf;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> edge_u[i] >> edge_v[i] >> costs[i];
    }

    bool neg_cycle = false;
    int u, v;

    d[0] = 0;
    for(int step = 0; step < n; step++)
    {
        bool update = false;

        for(int i = 0; i < m; i++)
        {
            u = edge_u[i];
            v = edge_v[i];

            if(d[u] + costs[i] < d[v])
            {
                update = true;

                //cout << step << " " << n << endl;
                if(step == n - 1)
                {
                    neg_cycle = true;
                }

                d[v] = d[u] + costs[i];
            }
        }
        if(update == false)
        {
            break;
        }
    }
    if(neg_cycle == true)
    {
        cout << "possible" << endl;
    }
    else
    {
        cout << "not possible" << endl;
    }
}

int main()
{
    //freopen("558.txt", "r+", stdin);

    int t_case;

    cin >> t_case;
    while(t_case--)
    {
        bellman();
    }

    return 0;
}
