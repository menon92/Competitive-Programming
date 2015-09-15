/**
  * Problem : 10340-All in All.cpp
  * Status  : Accepted
  * Time taken : 0.003s
  * Date : 15.09.2015
  **/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	string s, t;
	int i, j, start, sslength, tslength, count;
	bool isnotinside;

	//freopen("input.txt", "r+", stdin);

	while(cin >> s && cin >> t)
	{
		sslength = s.length();
		tslength = t.length();

		count = 0;
		for(i = 0, start = 0; i < sslength; i++)
		{
			isnotinside = true;
			for(j = start; j < tslength && isnotinside; j++)
			{
				if(s[i] == t[j])
				{
					start = j + 1;
					isnotinside = false;
					count++;
				}
			}
		}

		if(count == sslength)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

        s.clear();
        t.clear();
	}

	return 0;
}
