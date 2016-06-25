/**
  * Problem : 11831 - Sticker Collector Robot.
  * Status : Accepted.
  * Author : Mehadi Hasan Menon.
  * Date : 26.06.16.
  **/
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

const char d[5] = {'N', 'L', 'S', 'O'};
const int mx = 101;

int main()
{
//	freopen("11831.txt", "r+", stdin);
//	freopen("11831_out.txt", "r+", stdout);

    int n, m, instruction;
    char graph[mx][mx];

    while(cin >> n >> m >> instruction)
    {
        if(n == 0 && m == 0 && instruction == 0)
        {
            break;
        }

        int current_row, current_col;
        int stickers, index;
        char direction, c;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                cin >> c;

                graph[row][col] = c;

                if(c == 'N' || c == 'L' || c == 'S' || c == 'O')
                {
                    direction = c;
                    current_row = row;
                    current_col = col;

                    graph[row][col] = '.'; // very important!

                }
            }
        }

        if(direction == 'N')
        {
            index = 0;
        }
        else if(direction == 'L')
        {
            index = 1;
        }
        else if(direction == 'S')
        {
            index = 2;
        }
        else if(direction == 'O')
        {
            index = 3;
        }

        stickers = 0;
        for(int ins = 0; ins < instruction; ins++)
        {
            cin >> c;

            if(c == 'D')
            {
                index = index + 1;

                if(index > 3)
                {
                    index = 0;
                }
            }
            else if(c == 'E')
            {
                index = index - 1;

                if(index < 0)
                {
                    index = 3;
                }
            }
            else if (c == 'F')
            {
                if(index == 0) // 'N' go up
                {
                    current_row = current_row - 1;
                    //current_col = current_col;

                    if(current_row < 0 || graph[current_row][current_col] == '#') // we can't go this position.
                    {
                        current_row = current_row + 1;
                    }
                    else if(graph[current_row][current_col] == '*')
                    {
                        stickers = stickers + 1;
                        graph[current_row][current_col] = '.'; // we collect this stickers.
                    }

                }
                else if(index == 1) // 'L' go right
                {
                    current_col = current_col + 1;
                    //current_col = current_col;

                    if(current_col >= m  || graph[current_row][current_col] == '#')   // we can't go this position.
                    {
                        current_col = current_col - 1;
                    }
                    else if(graph[current_row][current_col] == '*')
                    {
                        stickers = stickers + 1;
                        graph[current_row][current_col] = '.'; // we collect this stickers.
                    }
                }
                else if(index == 2) // 'S' go down.
                {
                    current_row = current_row + 1;

                    if(current_row >= n || graph[current_row][current_col] == '#')   // we can't go this position.
                    {
                        current_row = current_row - 1;
                    }
                    else if(graph[current_row][current_col] == '*')
                    {
                        stickers = stickers + 1;
                        graph[current_row][current_col] = '.'; // we collect this stickers.
                    }
                }
                else if(index == 3) // 'O' go left
                {
                    current_col = current_col - 1;

                    if(current_col < 0 || graph[current_row][current_col] == '#')   // we can't go this position.
                    {
                        current_col = current_col + 1;
                    }
                    else if(graph[current_row][current_col] == '*')
                    {
                        stickers = stickers + 1;
                        graph[current_row][current_col] = '.'; // we collect this stickers.
                    }
                }
            }
        }
        cout << stickers << endl;
    }

    return 0;
}
