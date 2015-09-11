/**
  * Problem  : 541-Error Correction.cpp
  * Status   : Accepted
  * Run Time : 0.00 s
  * Date     : 11.09.2015
  **/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, value, rowsum, colsum;
    int row[100 + 5], col[100 + 5];

    freopen("input.txt", "r+", stdin);

    while(scanf("%d", &n) == 1)
    {
        memset(col, 0, sizeof(col));

        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
        {
            rowsum = 0;
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &value);
                rowsum += value;
                col[j] += value;
            }
            row[i] = rowsum;
        }

        int cnt1, cnt2, rp, cp;
        bool corrupt = false;

        cnt1 = 0;
        for(int i = 0; i < n; i++) // find row position.
        {
            if(row[i] % 2 != 0)
            {
                cnt1++;
                rp = i;
            }
            if(cnt1 > 1)
            {
                printf("Corrupt\n");
                corrupt = true;
                break;
            }
        }

        if(corrupt != true)
        {
            cnt2 = 0;
            for(int i= 0; i < n; i++) // find column position.
            {
                if(col[i] % 2 != 0)
                {
                    cnt2++;
                    cp = i;
                }
                if(cnt2 > 1)
                {
                    printf("Corrupt\n");
                    break;
                }
            }
        }

        if(cnt1 == 1 && cnt2 == 1)
            printf("Change bit (%d,%d)\n", rp + 1, cp + 1);
        else if(cnt1 == 0 && cnt2 == 0)
            printf("OK\n");

    }

    return 0;
}
