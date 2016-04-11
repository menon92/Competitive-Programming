//------------------------------------
// Problem : 10452 - Marcus.
// Verdict : Accepted, Time : 0.00 ms,
// Writer  : Mehadi Hasan Menon.
// Algorithm : DFS, Date : 11.04.16.
//------------------------------------
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int  max_size = 10;
const char lock = 'X';

int map_of_path[10][10];
int starting_row, starting_col;
int max_row_m, max_col_n;

vector <string> path;

void create_a_map(int max_row, int max_col)
{
	char stone;

	for(int i = 0; i  < max_row; i++)
	{
		for(int j = 0; j < max_col; j++)
		{
			cin >> stone;

			if(stone == '@')
			{
				starting_row = i;
				starting_col = j;
			}
			map_of_path[i][j] = stone;
		}
	}
}

void print(int r, int c)
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			printf("%c", map_of_path[i][j]);
		}
		printf("\n");
	}
}

void find_path_using_DFS(int row, int col, string direction)
{
	if(row < 0 || col < 0 || row >= max_row_m || col >= max_col_n) {
		//cout << "out of range" << endl;
		return; // out of our map;
	}

	if(map_of_path[row][col] != 'I' && map_of_path[row][col] != 'E' && map_of_path[row][col] != 'H' &&
	   map_of_path[row][col] != 'O' && map_of_path[row][col] != 'V' && map_of_path[row][col] != 'A' &&
	   map_of_path[row][col] != '@' && map_of_path[row][col] != '#') {
	      // cout << "not cobblestone" << endl;
		return; // this is not a cobblestone . so back :)
	}
	else {
		map_of_path[row][col] = lock; // coz we don't want to visite same path twice;

		path.push_back(direction); // save the path direction

		//cout << direction << endl;


		find_path_using_DFS(row, col - 1, "left");  // go left;
		find_path_using_DFS(row, col + 1, "right"); // go right;
		find_path_using_DFS(row - 1, col, "forth"); // go top/forth;
	}
}

int main()
{
	freopen("10452.txt", "r+", stdin);

	int tcase, m, n, path_size;

	cin >> tcase;
	while(tcase--)
	{
		cin >> m >> n;

		max_row_m = m;
		max_col_n = n;

		create_a_map(m, n);
		//print(m, n);


		find_path_using_DFS(starting_row, starting_col, "");

		path_size = path.size();

		for(int i = 1; i < path_size; i++)
        {
			if(i > 1) {
                printf(" "); // skip last space char ;
			}
			cout << path[i];
		}
		printf("\n");

		path.clear();
	}

	return 0;
}
