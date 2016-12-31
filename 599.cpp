/**
  * Problem :
  * Verdict : Accepted.
  * Time    : 0.400 ms.
  * Write   : Mehadi Hasan Menon.
  * Date    : 31.12.16.
  **/
#include <iostream>
#include <vector>
using namespace std;

vector <int> AdjList[27];

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc, edges;

    cin >> tc;
    cin.ignore();
    for(int t = 1; t <= tc; t++)
    {
        string s;
        edges = 0;
        while(true) {
            getline(cin, s);
            if(s[0] == '*') {
                break;
            }
            char x, y; bool flag = true;
            // Extract value of x & y from string;
            for(int i = 0; s[i]; i++) {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    if(flag == true) {
                        x = s[i];
                        flag = false;
                    }
                    else {
                        y = s[i];
                        break;
                    }
                }
            }
            // it's time to make adjacent list :)
            AdjList[x - 'A'].push_back(y - 'Z');
            AdjList[y - 'A'].push_back(x - 'Z');
            edges += 1;
        }
        int trees, acorns, nodes;

        getline(cin, s);
        nodes = acorns = 0;
        for(int i = 0; s[i]; i++) {
            // check if a node has some adjacent node of not :)
            if(s[i] >= 'A' && s[i] <= 'Z') {
                if(AdjList[ s[i] - 'A' ].size() == 0) {
                    acorns += 1;
                    nodes += 1;
                }
                else {
                    nodes += 1;
                    AdjList[ s[i] - 'A' ].clear();
                }
            }
        }
        // number of connected component in our graph is
        trees = nodes - edges;
        if(acorns > 0) {
            trees = trees - acorns;
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
    }
    return 0;
}
