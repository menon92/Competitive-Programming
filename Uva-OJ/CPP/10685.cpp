//------------------------------------
// Problem : Nature-10685.
// Status  : Accepted.
// Author  : ~menon.
// Date    : 05-03-2016.
//------------------------------------
#include <bits/stdc++.h>

using namespace std;

map <string, string> parent;
map <string, int> cnt;
map <string, int> :: iterator it;
int max_count = -1;

string find_representative(string s)
{
    if(parent[s] == s)
        return s;

    parent[s] = find_representative(parent[s]);

    return parent[s];
}

void make_friend(string s1, string s2)
{
    string f1, f2;

    f1 = find_representative(s1);
    f2 = find_representative(s2);
    
    if(f1 != f2)
    {
        parent[f1] = f2; // make parent f2;
        cnt[f2] += cnt[f1];
    }
}

int main()
{
   // freopen("10685.txt", "r+", stdin);
    int c, r;
    while(cin >> c >> r)
    {
        if(c == 0 && r == 0)
            break;

        string animal;
        max_count = -1;
        parent.clear();
        cnt.clear();

        for(int i = 0; i < c; i++)
        {
            cin >> animal;
            parent[animal] = animal;
            cnt[animal] = 1;
        }
        if(r == 0)
            cout << 1 << endl;
        else
        {
            string s1, s2;

            for(int i = 0; i < r; i++)
            {
                cin >> s1 >> s2;
                make_friend(s1, s2);
            }

            for(it = cnt.begin(); it != cnt.end(); ++it)
            {
                if(it->second > max_count)
                    max_count = it->second;
            }

            cout << max_count << endl;
        }
    }

    return 0; 
}
