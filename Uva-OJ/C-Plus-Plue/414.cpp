/**
  Status : Accepted.
  */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int n, cntX, maxX;

	//freopen("414.txt", "r+", stdin);

	while(cin >> n)
	{
		char image[14][26];
        int saveCntX[26];

        getchar();

		//cout << "N: " << n << endl;
		if(n == 0)
        {
           // cout << "Yes" << endl;
            break;
        }

		maxX = 0;
		for(int i = 0; i < n; i++)
		{
			cntX = 0;
			int j;
			char c;
			for(j = 0; j < 25; j++)
			{
				c = getchar();
				image[i][j] = c;
				//putchar(c);
				//scanf("%c", &image[i][j]);
				//cin >> image[i][j];
				//cout << image[i][j];

				if(image[i][j] == 'X')
					cntX++;
			}
			//image[i][j] = '\0';
			//putchar('\n');
			getchar(); // THIS IS VARY IMPROTANT .. WE HAVE TO ESCAPE EVRY '\N' AFTER EVERY LINE INPUT.
                        // OTHERWIES INTPUT WILL MASAKAR :( SO BE CAREFULL:)
			saveCntX[i] = cntX;

			if(cntX > maxX)
				maxX = cntX;
		}
		//cout << "maxX: " << maxX << endl;

		// print image
//		for(int i = 0; i < n; i++)
//		{
//            for(int j = 0; j < 25; j++);
//                //cout << image[i][j];
//            //cout << endl;
//        }
        //cout << endl;
        //cout << "End of image" << endl;

		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			//cout << saveCntX[i] << endl;
			ans += maxX - saveCntX[i];
		}
		cout << ans << endl;
	}


	return 0;
}
