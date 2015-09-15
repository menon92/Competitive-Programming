/**
  * Problme : 10302-Summation of Polynomials.cpp
  * Status  : Accepted
  * Time taken : 0.00 s
  * Date    : 15.09.2015
  **/
#include <iostream>

using namespace std;

int const maxsize = 50000 + 5;
long long a[maxsize];

void preCalculate()
{
    long long sum;

    for(int i = 1; i < maxsize; i++)
    {
        sum = 0.5 * i * (i + 1);
        a[i] = sum * sum;
    }
}

int main()
{
    preCalculate();

    int n;
    while(cin >> n)
    {
        cout << a[n] << endl;
    }
}
