/**
  * Problem: 482 - Permutation Arrays
  * Status : Accepted after 3 times WA :)
  * Date   : 18.11.2015.
  */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("482.txt", "r", stdin);

	int tc;

	cin >> tc;
	cin.ignore(); // ignore 1st new line IMPORTANT
	for(int t = 0; t < tc; t++)
	{
        std::vector<int> index;
        string line1, line2;


        cin.ignore(); // ignore 2nd new line IMPORTANT
        getline(cin, line1);
        getline(cin, line2);

        stringstream ss1(line1);
        string token;

        while(getline(ss1, token, ' '))
            index.push_back(atoi(token.c_str()));

        int p = 0, len = index.size();
        stringstream ss2(line2);
        std::vector <string> floatingNumbers(len + 2);

        while(getline(ss2, token, ' ')) {
          floatingNumbers.at(index[p] - 1) = token;
           p++;
        }

        if(t > 0) {
            cout << endl;
           // cout << endl; // aitar jonnn wrong answer khaiche :(
        }
        for(int i = 0; i < len; i++)
        {
            cout << floatingNumbers[i] << endl;

           // if(i < len - 1) // ai tar jonno WA answer khaichi :( last line a akta kore new line hobe
                //cout << endl;
        }
    }
	return 0;
}
