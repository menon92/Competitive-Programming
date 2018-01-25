/**
  * Problem : 247 - Calling Circles 
  * Writer  : Mehadi Hasan Menon.
  * Verdict : Accepted.
  * Date    : 25.01.2018
  */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <set>
using namespace std;

map <string, vector<string> >adjList;
map <string, vector<string> >adjListT; // transpose of graph.
map <string, bool> vis;
vector <string> node_list;
vector <string> same_circle_list;

void kosaraju(string u, int pass)
{
    vis[u] = true;
    vector <string> neighbor;

    if(pass == 1) {
        neighbor = adjList[u];
    }
    else {
        neighbor = adjListT[u];
        same_circle_list.push_back(u);
    }

    for(int i = 0; i < neighbor.size(); i++) {
        string v = neighbor[i];
        if(vis[v] == false) {
            kosaraju(v, pass);
        }
    }
    node_list.push_back(u);
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int n, m;
    string u, v;
    int n_dataset = 1;

    while(cin >> n >> m) 
    {
        if(n == 0 && m == 0) {
            break;
        }
        
        set <string> node_set;
        set <string> :: iterator it;

        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            adjList[u].push_back(v);
            adjListT[v].push_back(u); // transpose input.
            node_set.insert(u);
            node_set.insert(v);
            vis[u] = vis[v] = false;
        }

        // 1st pass 
        for(it = node_set.begin(); it != node_set.end(); ++it) {
            if(vis[*it] == false) {
                kosaraju(*it, 1);
            }
        }

        // reinit vis for 2nd pass.
        for(it = node_set.begin(); it != node_set.end(); ++it) {
            vis[*it] = false;
        }

        // 2nd pass
        bool is_circle_found = false;
        int numSCC = 0;
        cout << "Calling circles for data set " << n_dataset << ":" << endl;
        n_dataset += 1;

        for(int i = node_list.size() - 1; i >= 0; i--)
        {
            string u = node_list[i];
            
            if(vis[u] == false) {
                kosaraju(u, 2);
                is_circle_found = true;
                numSCC += 1;
            }
            if(is_circle_found) {
                for(int i = 0; i < same_circle_list.size(); i++) {
                    if(i > 0) {
                        cout << ", ";
                    }
                    cout << same_circle_list[i];
                }
                cout << "\n";
                is_circle_found = false;
                // clear circle list
                same_circle_list.clear();
            }
        }
        //cout << "numSCC : " << numSCC << endl;

        // reset graph for each input set.
        for(it = node_set.begin(); it != node_set.end(); ++it) {
            adjList.clear();
            adjListT.clear();
        }
        node_list.clear();
        node_set.clear();
    }
   
    return 0;
}
