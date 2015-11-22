/**
  * Problem : 755-487--3279.
  * Status  : Accepted. Time : 0.982s.
  * Date : 22-11-2015.
  **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc, telephoneNumbers;

	//freopen("755.txt", "r", stdin);

	cin >> tc;
	while(tc--)
	{
		cin >> telephoneNumbers;
		cin.ignore(); // skipe one new line from input :)

		string allNumbers[telephoneNumbers];

		for(int c = 0; c < telephoneNumbers; c++)
		{
			string number;
			cin >> number;
			//getline(cin, number);

			string temp = "";
			int len = number.length();

			// formate our given telephone number
			for(int i = 0; i < len; i++)
			{
				if(number[i] >= '0' && number[i] <= '9')
                    temp += number[i];
				else if(number[i] == 'A' || number[i] == 'B' || number[i] == 'C')
					temp += "2";
				else if(number[i] == 'D' || number[i] == 'E' || number[i] == 'F')
					temp += "3";
				else if(number[i] == 'G' || number[i] == 'H' || number[i] == 'I')
					temp += "4";
				else if(number[i] == 'J' || number[i] == 'K' || number[i] == 'L')
					temp += "5";
				else if(number[i] == 'M' || number[i] == 'N' || number[i] == 'O')
					temp += "6";
				else if(number[i] == 'P' || number[i] == 'R' || number[i] == 'S')
					temp += "7";
				else if(number[i] == 'T' || number[i] == 'U' || number[i] == 'V')
					temp += "8";
				else if(number[i] == 'W' || number[i] == 'X' || number[i] == 'Y')
					temp += "9";

			}
			allNumbers[c] = temp;
		}

		// sort all number lexicographical order.
        sort(allNumbers, allNumbers+telephoneNumbers);

        std::map<string, int> m;

        // count the same telephone number;
        for(int i = 0; i < telephoneNumbers; i++) {
        	m[ allNumbers[i] ]++;
        }

        bool noDuplicate = true;

        // if we get duplicate number then print it;
        for(map<string, int> :: iterator it = m.begin(); it != m.end(); ++it)
        {
        	if(it->second > 1)
        	{
                noDuplicate = false;

        		string standardForm = it->first;
        		for(int i = 0; i < 7; i++) // akhane 7 ar jaygay 8 dewar jonn 5 time WA :(
        		{
        			if(i == 3) {
        				cout << '-';
        			}
        			cout << standardForm[i];
        		}
        		cout << ' ' << it->second << endl;
        	}

        }
        if(noDuplicate)
            cout << "No duplicates." << endl;
        if(tc)
            cout << endl;
    }

	return 0;
}
