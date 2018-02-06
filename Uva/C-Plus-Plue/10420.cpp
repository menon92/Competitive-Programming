/**
  * Problme : 10420 - List fo Conquests.cpp
  * Status  : Accepted .
  * Tiem taken : 0.00 s.
  * Date of submission : 10.09.2015.
  **/

#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

struct cmp_str {
    bool operator()(char const *a, char const *b)
    {
        return std::strcmp(a, b) < 0;
    }
};

int main()
{
    map <string, int> m;
    int n;

   // freopen("input.txt", "r+", stdin);
   // freopen("output.txt", "r+", stdout);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char country[80];
        scanf("%s", country);

        char name[80];
        scanf("%[^\n]", name);

        stringstream ss;
        ss << country;
        string key;
        ss >> key;

        m[key]++;
    }

    map <string, int> :: iterator it;

    for(it = m.begin(); it != m.end(); ++it)
        cout << it->first << " " << it->second << endl;

    return 0;
}
