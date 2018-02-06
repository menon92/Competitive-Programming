/**
  * Problem : 929-Number Maze.
  * Status  : Accepted.
  * Author  : Mehadi Hasan Menon.
  * Date : 24.03.16.
  */
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_CELL_SIZE = 999 + 4;
const int infinity = 10000000; // value range is 0 to 9

int fx[] = {-1, 0, 1, 0};
int fy[] = {0, 1, 0, -1};
int cell[MAX_CELL_SIZE][MAX_CELL_SIZE];

struct data
{
    int row, col;
    int cost;

    bool operator < (const data &p) const {
        return cost > p.cost;
    }
};

int dijkstra_find_min_cost(int srow, int scol, int erow, int ecol)
{
    int dis[erow][ecol];
    int current_cost;

   // memset(dis, 10, sizeof(dis[0][0]*erow*ecol));

    for(int i = 0; i < erow; i++)
    {
        for(int j = 0; j < ecol; j++)
            dis[i][j] = infinity;
    }


//     for(int i = 0; i < erow; i++)
//     {
//          for(int j = 0; j < ecol; j++)
//              printf("%d ", dis[i][j]);
//          printf("\n");
//     }

    priority_queue <data> pq;
    data u, v;

    u.row = srow;
    u.col = scol;
    u.cost = cell[srow][scol];

    pq.push(u);
    dis[srow][scol] = cell[srow][scol];

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        int x, y;

/*         x = top.row;
 *         y = top.col;
 */

        for(int i = 0; i < 4; i++)// we can go only 4 directions;
        {
            x = u.row + fx[i];
            y = u.col + fy[i];

            if(x >= srow && y >= scol && x < erow && y < ecol) // is in range then
            {
                current_cost = dis[u.row][u.col] + cell[x][y];

                if(current_cost < dis[x][y])
                {
                    dis[x][y] = current_cost;

                    v.row = x;
                    v.col = y;
                    v. cost = current_cost;

                    pq.push(v);
                }
            }
        }
    }
   // cout << "Debug: " << dis[erow - 1][ecol - 1] << endl;
    return dis[erow - 1][ecol - 1];

}


int main()
{
    freopen("929.txt", "r+", stdin);

    int t_case, row, col, cost;

    cin >> t_case;
    while(t_case--)
    {
        cin >> row >> col;

        for(int r = 0; r < row; r++)
        {
            for(int c = 0; c < col; c++)
            {
                cin >> cost;

                cell[r][c] = cost;
            }
        }

        int min_cost;

        min_cost = dijkstra_find_min_cost(0, 0, row, col);

        cout << min_cost << endl;
    }

    return 0;
}
