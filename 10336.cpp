/**
  * Problem : 10336 - Rank the language_ranks
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 25.12.16.
  **/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int h, w;
const int mx = 200;
char grid[mx][mx];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct data
{
    int points;
    char name;

}all_language_ranks[26];

// compare function for sort our structure
bool compare (const data &a, const data &b)
{
    if(a.points == b.points) {
        return a.name < b.name;
    }
    else {
        return a.points > b.points;
    }
}

void dfs(int r, int c, char new_language_rank)
{
	if(r < 0 || r >= h || c < 0 || c >= w) {
		return ;
	}
	if(grid[r][c] == '*' || grid[r][c] != new_language_rank) {
		return ;
	}
	// marked as visited :)
	grid[r][c] = '*';

	for(int i = 0; i < 4; i++)
	{
		int new_row = r + dr[i];
		int new_col = c + dc[i];

		dfs(new_row, new_col, new_language_rank);
	}
}

int main()
{
	freopen("input.txt", "r+", stdin);
	freopen("output.txt", "r+", stdout);

	int tc;

	scanf("%d\n", &tc);
	for(int i = 1; i <= tc; i++)
	{
		scanf("%d %d", &h, &w);
		getchar(); // skip new line char

		// take input
		for(int j = 0; j < h; j++)
		{
			for(int k = 0; k < w; k++)
			{
				scanf("%c", &grid[j][k]);
			}
			getchar(); // skip newline char
		}

		// initially all language_ranks rank is 0;
		int language_rank[26] = {0};

		for(int j = 0; j < h; j++)
		{
			for(int k = 0; k < w; k++)
			{
				if(grid[j][k] != '*')
				{
					// count the rannk;
					language_rank[ grid[j][k] - 'a'] += 1;

					dfs(j, k, grid[j][k]);
			    }
			}
		}

        for(int j = 0; j < 26; j++)
        {
            all_language_ranks[j].points = language_rank[j];
            all_language_ranks[j].name = j + 'a';
        }

        // sort data as they describe :)
        sort(all_language_ranks, all_language_ranks + 26, compare);

		// now just print result :)
		printf("World #%d\n", i);
        for(int j = 0; j < 26; j++)
        {
            if(all_language_ranks[j].points == 0) {
                // we got everything . no need to continue;
                break;
            }

            printf("%c: %d\n", all_language_ranks[j].name, all_language_ranks[j].points);
        }
	}

	return 0;
}
