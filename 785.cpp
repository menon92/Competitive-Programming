/**
  * Problem : 785 - Grid Colouring.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 24.12.16.
  **/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>

using namespace std;

char maze[50][100];
char contours_char;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, char marking_char)
{
    if(maze[r][c] == contours_char || maze[r][c] == marking_char) {
        return;
    }
    if(maze[r][c] == ' ')
    {
        maze[r][c] = marking_char;

        for(int i = 0; i < 4; i++)
        {
            int new_row = r + dr[i];
            int new_col = c + dc[i];

            // traverse all adjacent
            dfs(new_row, new_col, marking_char);
        }
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);

    char line[100];
    bool found_contours_char = false;
    int r = 0;

    vector < pair<int, int> > vip_index;
    vector <char> vc_marking_char;

    while(gets(line))
    {
        // find contours char
        if(found_contours_char == false)
        {
            for(int c  = 0; line[c]; c++)
            {
                if(isprint(line[c]) && line[c] != ' ')
                {
                    contours_char = line[c];
                    found_contours_char = true;

                    break;
                }
            }
        }

        // find all marking_char's  position
        for(int c = 0; line[c]; c++)
        {
            if(line[c] != contours_char && line[c] != ' ' && line[c] != '_')
            {
                int marking_char_row = r;
                int marking_char_col = c;

                // track the location of marking char in maze & and the char itself
                vip_index.push_back(make_pair(marking_char_row, marking_char_col));
                vc_marking_char.push_back(line[c]);
            }
        }

        strcpy(maze[r], line);
        r += 1;

        if(line[0] == '_')
        {
            int sz = vip_index.size();
            int row, col;
            char marking_char;

            for(int contours = 0; contours < sz; contours++)
            {
                row = vip_index[contours].first;
                col = vip_index[contours].second;
                marking_char = vc_marking_char[contours];

                // for 1st time dfs call
                maze[row][col] = ' ';

                // fill all
                dfs(row, col, marking_char);

                vip_index.clear();
                vc_marking_char.clear();
            }

	        // print result
	        for(int i = 0; i < r; i++)
	        {
	            puts(maze[i]);
	        }

	        r = 0;
	        found_contours_char = false;
	    }
    }

    return 0;
}
