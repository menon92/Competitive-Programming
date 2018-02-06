/////////////////////////////////////////////
//  * Problem : 459 - Graph Connectivity.
//  * Status  : Accepted.
//  * Author  : ~menon.
//  * Date    : 04.03.2016.
/////////////////////////////////////////////

#include <iostream>
#include <cstdio>

using namespace std;

int parent[100];

int find_representative_of(int f)
{
    if(parent[f] == f)
        return f;

    parent[f] = find_representative_of(parent[f]); // optimize

    return parent[f];
}

int make_friend(int f1, int f2)
{
    int x, y;

    x = find_representative_of(f1);
    y = find_representative_of(f2);

    if(x != y) {
        parent[x] = y;
        return 1;
    }

    return 0;
}

int main()
{
    freopen("459.txt", "r+", stdin);

    int tcase;
    string s;

    scanf("%d\n\n", &tcase);
    for(int t = 0; t < tcase; t++)
    {
        int ends, cnt;

        getline(cin, s);

        // there can be max maxNode different subgraph.
        cnt = s[0] - 'A' + 1;
        // end point.
        ends =  s[0];

        for(int i = 'A'; i <= ends; i++) {
            parent[i] = i;
        }

        while(1)
        {
            if(!getline(cin, s) || s.empty())
                break;

            int f1, f2;

            f1 = s[0];
            f2 = s[1];

            if(make_friend(f1, f2) == 1)
                cnt--;
        }

        if(t > 0)
            cout << endl;

        cout << cnt << endl;
    }

    return 0;
}
