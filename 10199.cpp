/**
  * Problem : 10199 - Tourist Guide
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 9.01.2018
  */
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 100 + 7;
int dfs_number_counter, dfs_root_child;

unordered_map <string, vector <string> > adj_list;
unordered_map <string, bool> is_vis;
unordered_map <string, int> dfs_num;
unordered_map <string, int> dfs_low;
unordered_map <string, string> parent;
map <string, bool> articulation_vertix;

string dfs_root;
string routes[MAX];


void get_articulation_vertex(string u)
{
	dfs_low[u] = dfs_num[u] = dfs_number_counter++;
	is_vis[u] = true;
	int sz = adj_list[u].size();

	for(int i = 0; i < sz; i++)
	{
		string v = adj_list[u][i];
		if(is_vis[v] == false)
		{
			parent[v] = u;
			if(u == dfs_root) {
				dfs_root_child++;
			}

			get_articulation_vertex(v);

			if(dfs_low[v] >= dfs_num[u]){
                // cout << "AP: " <<  u << endl;
				articulation_vertix[u] = true;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u])
		{
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main()
{
	// freopen("input.txt", "r+", stdin);
	// freopen("out.txt", "r+", stdout);

	int n, r, tc;
	string u, v;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	tc = 1;

	while(cin >> n)
	{
		if(!n) {break;}

		for(int i = 0; i < n; i++)
		{
			cin >> routes[i];
			is_vis[routes[i]] = false;
			// cout << routes[i] << endl;
		}

		cin >> r;
		for(int i = 0; i < r; i++)
		{
			cin >> u >> v;
			// cout << "u = " << u << " v " << v << endl;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		dfs_number_counter = 0;
		for(int i = 0; i < n; i++)
		{
			if(is_vis[routes[i]] == false)
			{
				dfs_root = routes[i];
				dfs_root_child = 0;
				get_articulation_vertex(routes[i]);

                // if root has more then 1 childe then it is AP otherwise not AP
				articulation_vertix[dfs_root] = (dfs_root_child > 1);
			}
		}

		int total_articulation_points = 0;
		for(int i = 0; i < n; i++) {
            if(articulation_vertix[routes[i]]) {
                total_articulation_points += 1;
            }
		}


        if(tc > 1) {
            cout << endl;
        }

		cout << "City map #"<< tc++ << ": " << total_articulation_points;
        cout << " camera(s) found" << endl;
        //sort(articulation_vertix.begin(), articulation_vertix.end());

        for(auto i = articulation_vertix.begin(); i != articulation_vertix.end(); ++i) {
            if(i->second == true) {
                cout << i->first << endl;
            }
        }

        // clear.
        articulation_vertix.clear();
        adj_list.clear();
        dfs_low.clear();
        dfs_num.clear();
	}

	return 0;
}
