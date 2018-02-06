//-------------------------------
// Problem : 10449 - Traffic .
// Verdict : Accepted.
// Author : Mehadi Hasan Menon.
// Algorithm : Bellman Ford.
// Date : 06-18-16.
//-------------------------------
#include <iostream>
#include <cstdio>
using namespace std;

#define inf 100000007
#define mx 4007
#define pow(x) ((x) * (x) * (x))

int r, q, edge_cost, x, y, u, v;
int busyness[mx], edge_u[mx], edge_v[mx], costs_uv[mx];
int d[mx];

void bellman_ford(int n)
{
	for(int i = 1; i <= n; i++) {
		d[i] = inf;
		scanf("%d", &busyness[i]);
	}

	scanf("%d", &r);
	for(int i = 1; i <= r; i++)
	{
		scanf("%d %d", &x, &y);

		edge_u[i] = x;
		edge_v[i] = y;
		edge_cost = pow(busyness[y] - busyness[x]);
		costs_uv[i] = edge_cost;
	}

    d[1] = 0;
    for(int k = 1; k <= n - 1; k++)
    {
        bool update = false;
        for(int i = 1; i <= r; i++)
        {
            u = edge_u[i];
            v = edge_v[i];

            if(d[u] != inf && d[u] + costs_uv[i] < d[v])
            {
                update = true;
                d[v] = d[u] + costs_uv[i];
            }
        }
        if(update == false) {
            break;
        }
    }
    // if have any cycle then put those value to -inf;
    for(int i = 1; i <= r; i++) // not fucking r++, it is i++
    {
        u = edge_u[i]; v = edge_v[i];
        if(d[u] != inf && d[u] + costs_uv[i] < d[v]) {
            d[v] = -inf;
        }
    }
}

int main()
{
	freopen("10449.txt", "r+", stdin);

	int n, tc, des;
	tc = 1;
    while(scanf("%d", &n) == 1)
    {
        bellman_ford(n);

        printf("Set #%d\n", tc++);
        scanf("%d", &q);
        for(int i = 1; i <= q; i++)
        {
            scanf("%d", &des);

            if(d[des] < 3 || d[des] == inf) {
                printf("?\n");
            }
            else {
                printf("%d\n", d[des]);
            }
        }
    }
	return 0;
}
