/***************************************
* Problem : 11503-Virtual Friends
* Status  : Accepted. Time : 1.659ms.
* Author  : Mehadi Hasan Menon.
* Date    : 07-03-2016.
****************************************/
#include <bits/stdc++.h>

using namespace std;

map <string, string> parent;
map <string, int> cnt;

string find_representative(string s)
{
    if(parent[s] == "") // coz first time it will get null:)
        return s;

    parent[s] = find_representative(parent[s]);
    return parent[s];
}

int make_friend(string f1, string f2)
{
    string x, y;

    x = find_representative(f1);
    y = find_representative(f2);

    if(x != y) // they are not friend yet.
    {
        parent[x] = y;

        return cnt[y] += cnt[x];
    }
    return cnt[x]; // or cnt[y] same :)
}

int main()
{
    freopen("11503.txt", "r+", stdin);

    int tcase, f;
    string friend1, friend2;

    cin >> tcase;
    while(tcase--)
    {
        cin >> f;
        parent.clear();
        cnt.clear();

        for(int i = 0; i < f; i++)
        {
            cin >> friend1 >> friend2;

            if(cnt[friend1] < 1)
            {
                cnt[friend1] = 1;
            }
            if(cnt[friend2] < 1)
            {
                cnt[friend2] = 1;
            }

            cout << make_friend(friend1, friend2) << endl;
        }
    }

    return 0;
}
