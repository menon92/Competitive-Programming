/**
  * Problem : 352 - The Seasonal War
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 23.12.16.
  **/
#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 27;
int image_size;
char image[mx][mx];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c)
{
	if(r < 0 || r >= image_size || c < 0 || c >= image_size) {
		return ;
	}
	if(image[r][c] == '0') {
		return;
	}
	image[r][c] = '0';

	for(int i = 0; i < 8; i++)
	{
		int new_row = r + dr[i];
		int new_col = c + dc[i];

		dfs(new_row, new_col);
	}
}

int main()
{
	freopen("input.txt", "r+", stdin);

	int image_number = 1;

	while(scanf("%d", &image_size) != EOF)
	{
		for(int i = 0; i < image_size; i++) {
			scanf("%s", image[i]);
		}
        int number_of_war_eagles = 0;
		for(int i = 0; i <= image_size; i++)
		{
			for(int j = 0; j < image_size; j++)
			{
				if(image[i][j] == '1')
				{
					dfs(i, j);
					number_of_war_eagles += 1;
				}
			}
		}
		cout << "Image number " << image_number << " contains ";
		cout << number_of_war_eagles << " war eagles." << endl;

        image_number += 1;
	}

	return 0;
}
