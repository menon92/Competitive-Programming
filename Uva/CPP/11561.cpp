// Uva 11561.
#include <iostream>
#include <cstdio>

using std :: cout;
using std :: cin;
using std :: endl;

int golds, H_row, W_col;
int x, y;
char grid[52][52];
bool danger_zone[52][52];
const int px[] = {-1, 0, 1, 0}; // up, right, down, left
const int py[] = {0, 1, 0, -1}; // up, right, down, left

void DFS(int row, int col)
{
    if(row < 1 || row >= H_row - 1  || col < 1 || col >= W_col - 1) { // out of range.
        return ;
    }
    if(grid[row][col] == '#' || grid[row][col] == 'T') {
        return ; // this is wall.
    }

    if(grid[row][col] == 'G') {
        golds++;
    }

    grid[row][col] = '#';

    if(danger_zone[row][col] == false)
    {
        // if this is not danger zone then we can go
        // .. up, right, down, left other wise not.
        for(int i = 0; i < 4; i++)
        {
            x = row + px[i];
            y = col + py[i];

            DFS(x, y);
        }
    }
}

int main()
{
//    freopen("D.txt", "r+", stdin);

    int row, col;
    char ch;

    while(cin >> W_col >> H_row)
    {
        for(int r = 0; r < H_row; r++)
        {
            for(int c = 0; c < W_col; c++)
            {
                cin >> ch;

                if(ch == 'P')
                {
                    row = r;
                    col = c;

                    ch = '.';
                }
                grid[r][c] = ch;
                danger_zone[r][c] = false;
            }
        }

        for(int r = 1; r < H_row - 1; r++)
        {
            for(int c = 1; c < W_col - 1; c++)
            {
                if(grid[r][c] == 'T')
                {
                    for(int k = 0; k < 4; k++)
                    {
                        x = r + px[k];
                        y = c + py[k];

                        danger_zone[x][y] = true;
                    }
                }
            }
        }
        golds = 0;

        DFS(row, col);

        cout << golds << endl;

    }

    return 0;
}
