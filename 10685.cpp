/**
  * Problem : 10685 - Nature
  * Verdict : Accepted.
  * Time    : 490 ms.
  * Write   : Mehadi Hasan Menon.
  * Date    : 29.12.16.
  **/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map <string, string> rep;
unordered_map <string, int> number_of_creature;

int max_elimentary_chain = 1;

string find_rep(string s)
{
    if(rep[s] == s) {
        return s;
    }

    rep[s] = find_rep(rep[s]);

    return rep[s];
}

int union_ab(string a, string b)
{
    string u = find_rep(a); string v = find_rep(b);

    if(u != v)
    {
        rep[u] = v;
        number_of_creature[v] = number_of_creature[v] + number_of_creature[u];
        max_elimentary_chain = max(max_elimentary_chain, number_of_creature[v]);
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int c, r;
    string s1, s2;

    while(cin >> c >> r)
    {
        if(c == 0 && r == 0) {
            break;
        }

        // make initial set
        for(int i = 0; i < c; i++)
        {
            cin >> s1;

            rep[s1] = s1;
            number_of_creature[s1] = 1;
        }

        for(int i = 0; i < r; i++)
        {
            cin >> s1 >> s2;

            union_ab(s1, s2);
        }

        cout << max_elimentary_chain << endl;
        max_elimentary_chain = 1;

        for(int i = 0; i < c; i++)
        {
            rep.clear();
            number_of_creature.clear();
        }
    }

    return 0;
}
