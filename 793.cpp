/**
  * Problem : 793 - Network Connections
  * Verdict : Accepted.
  * Write   : Mehadi Hasan Menon.
  * Date    : 28.12.16.
  **/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector <int> par;

void make_set(int n)
{
    par.assign(n + 1, 0);
    // at the initial stage every node is
    // representative of itself.
    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find_par(int r)
{
    // If a node is parent of itself
    // then it's the representative of the entire set.
    if(par[r] == r) {
        return r;
    }
    // otherwise search for representative of the set.
    par[r] = find_par(par[r]);

    return par[r];
}

void union_ab(int a, int b)
{
    // find parent of a and b.
    int u = find_par(a);
    int v = find_par(b);

    // set u as parent of v.
    if(u != v) {
        par[v] = u;
    }
}

bool is_compters_connected(int a, int b)
{
    int u = find_par(a);
    int v = find_par(b);

    // if both parent is same then they are connected
    // otherwise not.
    if(u == v) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc, computers, a, b, connected, disconnected;
    char command; char line[100];

    scanf("%d\n", &tc);
    for(int t = 0; t < tc; t++)
    {
        scanf("%d", &computers);
        getchar();

        make_set(computers);

        connected = disconnected = 0;
        while(true)
        {
            gets(line);

            if(strcmp(line, "") == 0 || feof(stdin)) {
                break;
            }
            sscanf(line, "%c %d %d",&command, &a, &b);

            if(command == 'c') {
                union_ab(a, b);
            }
            else if(command == 'q')
            {
                if(is_compters_connected(a, b)) {
                    connected += 1;
                }
                else {
                    disconnected += 1;
                }
            }
        }
        if(t > 0) {
            printf("\n");
        }
        printf("%d,%d\n", connected, disconnected);
    }

    return 0;
}
