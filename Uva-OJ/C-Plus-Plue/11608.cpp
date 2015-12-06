/********************************************
  * Problem : 11608-No Problem!.
  * Status : Accepted. Time : 0.00s.
  * Rank : 147. Submission Date : 06.12.15.
  *******************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int const sz = 12 + 3;

int main(int argc, char const *argv[])
{
	int ready_problem, tc;
	int ready_problems[sz], need_problem[sz];

	//freopen("11608.txt", "r+", stdin);

	tc = 1;
	while(scanf("%d", &ready_problem) && ready_problem >= 0)
	{
		for(int i = 0; i < 12; i++) {
			scanf("%d", &ready_problems[i]);
		}

		for(int i = 0; i < 12; i++) {
			scanf("%d", &need_problem[i]);
		}

		// print result ;

		printf("Case %d:\n", tc++);

		int current_ready = ready_problem;

		for(int i = 0, j = 0; i < 12; i++)
		{
			if(i > 0) {
				current_ready += ready_problems[j];
				j++;
			}

			if(current_ready >= need_problem[i]) {
				printf("No problem! :D\n");

				// ___trick. we must subtract need_problem after contest

				current_ready -= need_problem[i];
			}
			else {
				printf("No problem. :(\n");
			}
		}
	}
	return 0;
}
