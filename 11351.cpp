/**
  * Problem : 11351 - Last Man Standing
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  **/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int joshepus(int n, int k)
{
    vector <int> rem_list;
    for(int i = 1; i <= n; i++) {
        rem_list.push_back(i);
    }

    int c = k - 1;

    if(c >= n) { // n = 23, k = 99
        c %= n;
    }
    while(rem_list.size() != 1)
    {
        //cout << *(rem_list.begin() + c) << endl;

        rem_list.erase(rem_list.begin() + c);

        c = c + k - 1;

        if(c >= rem_list.size()) {
            c %= rem_list.size();
        }
    }
    return rem_list[0];

//    if(n == 1) {
//        return 1;
//    }
//    else return (joshepus(n - 1, k) + k - 1) % n + 1;
//}

int main()
{
    //freopen("input.txt", "r+", stdin);

    int n, k, tc;

    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++)
    {
        scanf("%d %d", &n, &k);

        printf("Case %d: %d\n", i, joshepus(n, k));
    }

    return 0;
}
