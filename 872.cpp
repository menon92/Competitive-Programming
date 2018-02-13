/**
  * Problem : 872 - Ordering
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 10.02.2018
  */
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector <vector <char> > adj_list;
vector <char> variables;
bool is_vis[200];
bool is_possible = false;

bool is_valid_path(char u)
{
    int sz = adj_list[u].size();
    for(int i = 0; i < sz; i++)
    {
        char v = adj_list[u][i];
        if(is_vis[v]) {
            return false;
        }
    }
    return true;
}

void generate_comb(string comb)
{
    if(comb.length() == variables.size())
    {
        is_possible = true;
        int sz = comb.length();
        for(int i = 0; i < sz; i++)
        {
            if(i > 0) {
                cout << " ";
            }
            cout << comb[i];
        }
        cout << endl;
    }

    for(int i = 0; i < variables.size(); i++)
    {
        if(is_vis[variables[i]] == false)
        {
            is_vis[variables[i]] = true;
            if(is_valid_path(variables[i])) {
                generate_comb(comb + variables[i]);
            }
            is_vis[variables[i]] = false;
        }
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("out.txt", "r+", stdout);

    ios_base::sync_with_stdio();
    cin.tie();

    int tc;
    string nodes;
    string tmp;
    char u, v, c;
    while(cin >> tc)
    {
        cin.ignore();
        getchar();
        for(int t = 1; t <= tc; t++)
        {
            getline(cin, nodes);
            // cout << "nodes: " << nodes << endl;
            stringstream ss(nodes);
            while(ss >> c) {
                // cout << "c: " << c << endl;
                variables.push_back(c);
            }

            ss.clear();
            adj_list.resize(variables.size() + 7);
            string data;
            getline(cin, tmp);
            cin.ignore();
            ss.str(tmp);
            // cout << "data: " << tmp << endl;
            while(ss >> data) {
                u = data[0];
                v = data[2];
                // cout << "data: " << data << endl;
                adj_list[u].push_back(v);
            }

            int sz = variables.size();
            for(int i = 0; i < sz; i++) {
                is_vis[variables[i]] = false;
            }

            sort(variables.begin(), variables.end());
            is_possible = false;

            if(t > 1) {
                cout << endl;
            }

            generate_comb("");
            if(is_possible == false) {
                cout << "NO" << endl;
            }
            adj_list.clear();
            variables.clear();
        }
    }

    return 0;
}
