/**
  * Problem : 440 - Eeny Meeny Moo.
  * Verdict : Accepted.
  * Writer : Mehadi Hasan Menon.
  **/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n;

bool check_2_is_last_alive(int m)
{
    vector <int> circle_list;

    for(int i = 1; i <= n; i++) {
        circle_list.push_back(i);
    }

    int c = 0;
    while(circle_list[c] != 2)
    {
        // first time in loop power off two 1'st city. than power off to m'th city.

        circle_list.erase(circle_list.begin() + c);
        c =  c + m - 1;

        if(c >= circle_list.size()) {
            c = c % (circle_list.size());
        }
    }

    // if circle_list[c] == 13 then check it's the last element remain in our list.
    return circle_list.size() == 1;
}

// the answer m can be greater then the value of n

int main()
{
    //freopen("input.txt", "r+", stdin);

    while(scanf("%d", &n))
    {
        if(n == 0) {
            break;
        }

        int m = 2;
        while(check_2_is_last_alive(m) != true) {
            m = m + 1;
        }
        printf("%d\n", m);
    }

    return 0;
}
