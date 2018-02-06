/**
  * Problem : 264-Count on Cantor.cpp
  * Status  : Accepted.
  * Time taken : 0.016s.
  * Date : 14.09.2015.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

int const maxsize = 10000002;
int p[maxsize], q[maxsize];

void generateNumbers()
{
    bool isup = true;

    p[0] = q[0] = 1;

    for(int i = 1, k = 1, cnt = 2; i <= maxsize - 1; )
    {
        if(isup) // for up counter
        {
            for(int j = 1; j <= cnt; j++)
            {
                p[k] = j;
                q[k] = cnt - j + 1;

                k++;
                i++;

                if(i == maxsize) // take a close look on this line
                    break;       // this will save from overflow our array
            }

            isup = false;
        }
        else // for dowon counter
        {
            for(int j = 1; j <= cnt; j++)
            {
                q[k] = j;
                p[k] = cnt - j + 1; // reversed condition for p[]

                k++;
                i++;

                if(i == maxsize) // also take a close look on this line
                    break;       // this will save from overflow our array
            }
            isup = true;
        }
        cnt++;
    }
}

int main()
{
    generateNumbers();

    int n;

    while(scanf("%d", &n) != EOF)
    {
        printf("TERM %d IS %d/%d\n", n, p[n - 1], q[n - 1]);
    }

    return 0;
}

