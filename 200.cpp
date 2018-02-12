/**
  * Problem : 200 - Rare Order 
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 13.02.2018
  */
#include <iostream>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector <vector <char> > adj_list;
vector <char> top_sort;
bool is_vis[256];

void dfs(char u)
{
    is_vis[u] = true;
    int sz = adj_list[u].size();
    for(int i = 0; i < sz; i++)
    {
        char v = adj_list[u][i];
        if(is_vis[v] == false) {
            dfs(v);
        }
    }
    top_sort.push_back(u);
}


int main()
{
    freopen("input.txt", "r+", stdin);

    string str1, str2;
    adj_list.resize(256);
    set <char> nodes;
    cin >> str1;
    while(cin >> str2 && str2 != "#")
    {
        for(int i = 0; i < str1.length() && i < str2.length(); i++)
        {
            if(str1[i] != str2[i])
            {
                adj_list[str1[i]].push_back(str2[i]);
                nodes.insert(str1[i]);
                nodes.insert(str2[i]);
                break;
            }
        }
        str1 = str2;
    }
    // cout << "node size: " << nodes.size() << endl;
    for(auto it = nodes.begin(); it != nodes.end(); ++it) {
        if(is_vis[*it] == false) {
            dfs(*it);
        }
    }

    for(int i = top_sort.size() - 1; i >= 0; i--) {
        cout << top_sort[i];
    }
    cout << endl;

    return 0;
}
