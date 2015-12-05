/**********************************************
  * Problem : 11192-Grope Reverse.
  * Status  : Accepted. time : 0.00ms;
  * Rank : 544. Submission Date : 05.12.15
  *********************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int g;
	char input[100 + 5];

	//freopen("11192.txt", "r+", stdin);

	while(scanf("%d", &g) && g != 0)
	{
		getchar(); // skipe new line ___Important!
		scanf("%[^\n]", &input);

		int len, start, end, m;
		char newString[100 + 5];

		len = strlen(input);
		g = len / g;
		end = 0; m = 0;

		for(int i = 0; i < len; )
		{
			end += g;
			start = i;

			for(int j = end - 1; j >= start; j--)
			{
				newString[m] = input[j];
				m++;
			}
			i = end;
		}
		newString[m] = '\0';

		// print reversed string

		printf("%s\n", newString);
	}

	return 0;
}
