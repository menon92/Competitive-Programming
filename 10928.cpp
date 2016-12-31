/**
  * Problem : 10928 - My Dear Neighbours
  * Verdict : Accepted.
  * Time    : 0.120 ms.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 31.12.16.
  **/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int mx = 1005;
vector <int> AdjList[mx];

int main()
{
    freopen("input.txt", "r+", stdin);

    int n, p, min_neighbours;

    while(scanf("%d", &n) != EOF)
    {
        for(int t = 0; t < n; t++)
        {
            scanf("%d", &p);
            cin.ignore();
            min_neighbours = 1000;
            for(int i = 1; i <= p; i++)
            {
                string line;
                stringstream ss;
                int number;
                getline(cin, line);
                ss << line;
                while(true) {
                    ss >> number;
                    if(!ss) {
                        break;
                    }
                    AdjList[i].push_back(number);
                }
                min_neighbours = min(min_neighbours, (int)AdjList[i].size());
            }
            int cnt = 0;
            for(int i = 1; i <= p; i++)
            {
                if(AdjList[i].size() == min_neighbours) {
                    if(cnt > 0) {
                        printf(" ");
                    }
                    printf("%d", i);
                    cnt += 1;
                }
                AdjList[i].clear();
            }
            puts("");
        }
    }
    return 0;
}
