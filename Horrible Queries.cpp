/**
  * Problem : Horrible Queries [SPOJ]
  * Verdict : Accepted
  * Writer  : Mehadi Hasan Menon
  * Date    : 25.11.16
  **/
#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 1000005; // SIZE MUST 10^6 NOT 10^5

struct tree {
    long long int prop, sum;
}tree[mx * 3];


void update(int node, int b, int e, int p, int q, long long int v)
{
    if(b > q || e < p) {
        return;
    }
    if(b >= p && e <= q) {
        tree[node].sum += (e - b + 1) * v; // this line was (p - q + 1)
        tree[node].prop += v;
        return ;
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    update(left, b, mid, p, q, v);
    update(right, mid + 1, e, p, q, v);

    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;

}


long long int quary(int node, int b, int e, int p, int q, long long int carry = 0)
{
    if(b > q || e < p) {
        return 0;
    }
    if(b >= p && e <= q) {
        return tree[node].sum + carry * (e - b + 1);
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    long long int p1 = quary(left, b, mid, p, q, carry + tree[node].prop);
    long long int p2 = quary(right, mid + 1, e, p, q, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int  tc, n, c, p, q, v;
    int  command;

    scanf("%d", &tc);
    for(int a = 1; a <= tc; a++)
    {
        scanf("%d %d", &n, &c);

        for(int d = 1; d <= c; d++)
        {
            scanf("%d %d %d", &command, &p, &q);

            if(command == 0) {
                scanf("%d", &v);
                update(1, 1, n, p, q, v);
            }
            else {
                printf("%lld\n", quary(1, 1, n, p, q));
            }
        }
        for(int i = 0; i <= mx; i++) { // IMPORTANT : Reset tree
            tree[i].prop = tree[i].sum = 0;
        }

    }

    return 0;
}
