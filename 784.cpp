/**
  * Problem : 784 - Maze Exploration.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 24.12.16.
  **/
#include <iostream>
#include <cstring>
#include <cstring>
#include <cctype>

using namespace std;
char maze[50][100];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, char wall)
{
    if(maze[r][c] == wall || maze[r][c] == '#')
    {
        return;
    }
    if(maze[r][c] == ' ' || maze[r][c] == '*')
    {
        maze[r][c] = '#';

        for(int i = 0; i < 4; i++)
        {
            int new_row = r + dr[i];
            int new_col = c + dc[i];

            dfs(new_row, new_col, wall);
        }
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    char line[100];
    char wall_char;
    int star_row, star_col;
    bool found_star = false, found_wall_char = false;
    int r = 0;
    int tc;

    scanf("%d", &tc);
    getchar();

    for(int t = 0; t < tc; t++)
    {
        while(gets(line))
        {
            // find start position
            if(found_star == false)
            {
                for(int c = 0; line[c]; c++)
                {
                    if(line[c] == '*')
                    {
                        star_row = r;
                        star_col = c;

                        found_star = true;
                        break;
                    }
                }
            }

            // find wall char
            if(found_wall_char == false)
            {
                for(int c  = 0; line[c]; c++)
                {
                    if(isprint(line[c]))
                    {
                        wall_char = line[c];
                        found_wall_char = true;

                        break;
                    }
                }
            }

            strcpy(maze[r], line);
            r += 1;

            if(line[0] == '_')
            {
                break;
            }
        }
        dfs(star_row, star_col, wall_char);

        // print result
        for(int i = 0; i < r; i++)
        {
            puts(maze[i]);
        }

        r = 0;
        found_wall_char = false;
        found_star = false;
    }

    return 0;
}
