/****************************************
  * Problem : 11222-Only i did it!.
  * Status  : Accepted. Time : 0.006s.
  * Date : 06-12-2015. Rank : 69.
  **************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int tc, s;
	int ff[1000 + 5], sf[1000 + 5], tf[1000 + 5];

	//freopen("11222.txt", "r+", stdin);

	scanf("%d", &tc);
	for(int i = 0; i < tc; i++)
	{
		int s1, s2, s3;

		// input for 1st friend

		scanf("%d", &s1);
		for(int j = 0; j < s1; j++) {
			scanf("%d", &ff[j]);
		}

		// input for 2nd friend.

		scanf("%d", &s2);
		for(int j = 0; j < s2; j++) {
			scanf("%d", &sf[j]);
		}

		// input for 3rd friend.

		scanf("%d", &s3);
		for(int j = 0; j < s3; j++) {
			scanf("%d", &tf[j]);
		}

		// find uncommon problme solved by 1st friend;

		int fsolve[s1];
		int cnt1 = 0;
		for(int j = 0; j < s1; j++)
		{
			int *p1 = find(sf, sf + s2, ff[j]);
			int *p2 = find(tf, tf + s3, ff[j]);

			if(p1 == sf + s2 && p2 == tf + s3) { // not found in sf ts;
				fsolve[cnt1] = ff[j];
				cnt1++;
			}
		}

		// find uncommon problem solved by 2nd friend;

		int ssolve[s2];
		int cnt2 = 0;
		for(int j = 0; j < s2; j++)
		{
			int *p1 = find(ff, ff + s1, sf[j]);
			int *p2 = find(tf, tf + s3, sf[j]);

			if(p1 == ff + s1 && p2 == tf + s3) { // not found in ff, ts;
				ssolve[cnt2] = sf[j];
				cnt2++;
			}
		}

		// find uncommon problem solved by 3rd friend;

		int tsolve[s3];
		int cnt3 = 0;
		for(int j = 0; j < s3; j++)
		{
			int *p1 = find(ff, ff + s1, tf[j]);
			int *p2 = find(sf, sf + s2, tf[j]);

			if(p1 == ff + s1 && p2 == sf + s2) { // not found in ff, sf;
                tsolve[cnt3] = tf[j];
                cnt3++;
            }
		}

		// now print the resul;

		cout << "Case #" << i + 1 << ":" << endl;

		if(cnt1 == cnt2 && cnt2 == cnt3) // all are solved equel number of different problem;
        {
            // print 1st;

            sort(fsolve, fsolve + cnt1); //sort(ff, ff + s1);
            cout << "1" << " " << cnt1;
            if(cnt1) {
                for(int j = 0; j < cnt1; j++) {
                    cout << " " << ff[j];
                }
            }
            cout << endl;

            // print 2nd;

            sort(ssolve, ssolve + cnt2); //sort(sf, sf + s2);
            cout << "2" << " " << cnt2;
            if(cnt2) {
                for(int j = 0; j < cnt2; j++) {
                    cout << " " << sf[j];
                }
            }
            cout << endl;

            // print 3rd;

            sort(tsolve, tsolve + s3); //sort(tf, tf + s3);
            cout << "3" << " " << cnt3;
            if(cnt3) {
                for(int j = 0; j < cnt3; j++) {
                    cout << " " << tf[j];
                }
            }
            cout << endl;

        } else {
            int maxSolve;

            maxSolve = max(max(cnt1,cnt2), cnt3);

            if(maxSolve == cnt1)
            {
                sort(fsolve, fsolve + cnt1);
                cout << "1" << " " << cnt1;
                if(cnt1) {
                    for(int j = 0; j < cnt1; j++) {
                        cout << " " << fsolve[j];
                    }
                }
                cout << endl;
            }
            if(maxSolve == cnt2)
            {
                sort(ssolve, ssolve + cnt2);
                cout << "2" << " " << cnt2;
                if(cnt2) {
                    for(int j = 0; j < cnt2; j++) {
                        cout << " " << ssolve[j];
                    }
                }
                cout << endl;
            }
            if(maxSolve == cnt3) {
            	sort(tsolve, tsolve + cnt3);
            	cout << "3" << " " << cnt3;
            	if(cnt3) {
                    for(int j = 0; j < cnt3; j++) {
                        cout << " " << tsolve[j];
                    }
                }
            	cout << endl;
            }
        }

	}


    return 0;
}
