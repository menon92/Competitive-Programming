/**
  * Problelm : 10019 - Funny Encryption Method.cpp
  * Status   : Accepted.
  * Date     : 10.09.2015.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

int countBitOfDecimalNumber(int n);
int countBitOfHexDicimalNumber(int dec);

int main()
{
    int n, number;

    //freopen("input.txt", "r+", stdin);
    
    cin >> n;
    while(n--)
    {
        cin >> number;
        cout << countBitOfDecimalNumber(number) << " " << countBitOfHexDicimalNumber(number) << endl;
    }
    return 0;
}

int countBitOfDecimalNumber(int n)
{
    int cnt = 0;
    while(n)
    {
        if(n & 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}

int countBitOfHexDicimalNumber(int dec)
{
    int cnt = 0;
    while(dec != 0)
    {
        int key = dec % 10;

        switch(key)
        {
            case 0:
                break;
            case 1:
            case 2:
            case 4:
            case 8:
                cnt++;
                break;
            case 3:
            case 6:
            case 9:
            case 10:
            case 12:
                cnt += 2;
                break;
            case 5:
                cnt += 2;
                break;
            case 7:
            case 11:
            case 13:
            case 14:
                cnt += 3;
                break;
            case 15:
                cnt += 4;
                break;
        }
        dec = dec / 10;
    }
    return cnt;
}
