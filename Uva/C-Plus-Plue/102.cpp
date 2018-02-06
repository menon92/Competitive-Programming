/**
  * Problem : 10260-Soundex;
  * Status  : Accepted. Time : 0.00s;
  * Date : 25.11.2015.
  ***********************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string line;

	string one = "BFPV";
	string two = "CGJKQSXZ";
	string three = "DT";
	string four = "L";
	string five = "MN";
	string six = "R";
	string extra = "AEIOUHWY";

	//freopen("10260.txt", "r+", stdin);

	while(getline(cin, line))
	{
		int len = line.length();
		string currnt = ""; // ai currnt variable while ar age delear korar jonn akbar WA khaichi ::

		for(int i = 0; i < len; i++)
		{
			if(currnt.find(line[i]) != -1) { // We fount the same code.
				continue;
			}
			else {
				char c = line[i];
				if(c == 'B' || c == 'F' || c == 'P' || c == 'V') {
					cout << 1;
					currnt = one;
				}
				else if(c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') {
					cout << 2;
					currnt = two;
				}
				else if(c == 'D' || c == 'T') {
					cout << 3;
					currnt = three;
				}
				else if(c == 'L') {
					cout << 4;
					currnt = four;
				}
				else if(c == 'M' || c == 'N') {
					cout << 5;
					currnt = five;
				}
				else if(c == 'R') {
					cout << 6;
					currnt = six;
				}
				else {
                    currnt = extra;
				}
			}
		}
		cout << endl;
	}
    return 0;
}
