/**
  * Problem : 10050-Hartals.
  * Status  : Accepted. Time : 0.0s
  * Date    : 23-11-15.
  **/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc, nDays, pParty;

	freopen("10050.txt", "r+", stdin);

	cin >> tc;
	while(tc--)
	{
		cin >> nDays;
		bool wdays[nDays];
		for(int i = 1; i <= nDays; i++) { // initially all day is working day.
			wdays[i] = true;
		}

		int hDay;

		cin >> pParty;
		for(int i = 1; i <= pParty; i++)
		{
			cin >> hDay;
			for(int j = hDay; j <= nDays; j += hDay) {

				if(((j + 1) % 7 == 0)|| (j % 7 == 0) ) { // skipe friday and saturday
					wdays[j] = true;
				}
				else
        			wdays[j] = false; // indicate hartal days from working dasy.
			}
		}

		int totlaHartalDay = 0;
		// count hartal days. skip friday && saturday
		for(int i = 1; i <= nDays; i++) {
			if(wdays[i] == false) {
           		totlaHartalDay++;
			}
		}
		cout << totlaHartalDay << endl;
	}

	return 0;
}
