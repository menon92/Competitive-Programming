#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

const int MAX = 1000;
map <string, vector <string> > adjList;
map <string, vector <string> > adjListT;
map <string, bool> vis;
vector <string> top_sort;

void kosaraju(string u, int pass)
{
	vis[u] = true;
	vector <string> neighbor;

	if(pass == 1) {
		neighbor = adjList[u];
	}
	else {
		neighbor = adjListT[u];
	}

	for(int i = 0; i < neighbor.size(); i++) {
		string v = neighbor[i];
		if(vis[v] == false) {
			kosaraju(v, pass);
		}
	}
	top_sort.push_back(u);
}


int main()
{
	freopen("input.txt", "r+", stdin);
	freopen("out.txt", "r+", stdout);

	int p, t;
	string u, v;

	while(cin >> p >> t)
	{
		cin.ignore();
		if(p == 0 && t == 0) {
			break;
		}

		string names[p + 1];
		for(int i = 0; i < p; i++) {
			getline(cin, names[i]);
			//vis[names[i]] = false;
		}

		for(int i = 0; i < p; i++) {
			vis[names[i]] = false;
			// cout << "names = " << names[i] << endl;
		}

		for(int i = 0; i < t; i++) 
		{
			getline(cin, u);
			getline(cin, v);

			adjList[u].push_back(v);
			adjListT[v].push_back(u);

		}

		// 1'st pass
		for(int i = 0; i < p; i++) 
		{
			string u = names[i];
			if(vis[u] == false) {
				kosaraju(u, 1);
			}
		}

		// reset vis 
		for(int i = 0; i < p; i++) {
			vis[names[i]] = false;
		}

		// 2'nd pass
		int num_of_truth_groups = 0;
		for(int i = top_sort.size() - 1; i >= 0; i--)
		{
			string u = top_sort[i];
			if(vis[u] == false) {
				num_of_truth_groups += 1;
				kosaraju(u, 2);
			}
		}
		printf("%d\n", num_of_truth_groups);

		// clear
		top_sort.clear();
		for(int i = 0; i < p; i++) 
		{
			adjList[names[i]].clear();
			adjListT[names[i]].clear();
		}
	}

	return 0;
}
