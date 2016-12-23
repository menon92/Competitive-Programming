/**
  * Problem : 260 - Il Gioco dell'X
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 24.12.16
  **/
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

const int mx = 205;
char board[mx][mx];
bool vis[mx][mx];
int N;
int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 0, -1, 1, 0, 1};

bool dfs()
{
    stack < pair <int, int> > sii;
    pair <int, int> pii;

    for(int i = 0; i < N; i++)
    {
        if(board[0][i] == 'b')
        {
            sii.push(make_pair(0, i));
            vis[0][i] = true;
        }
    }

    while(!sii.empty())
    {
        pii = sii.top(); sii.pop();

        if(pii.first == N - 1) {
            return true;
        }

        for(int i = 0; i < 6; i++)
        {
            int r = pii.first + dr[i];
            int c = pii.second + dc[i];

            if(r >= 0 && r < N && c >= 0 && c < N && board[r][c] == 'b' && vis[r][c] != true) {
                sii.push(make_pair(r, c));
                vis[r][c] = true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r+", stdin);

    int tc = 1;

    while(cin >> N && N != 0)
    {
        for(int i = 0; i < N; i++) {
            scanf("%s", board[i]);
        }

        bool is_black_win = dfs();

        if(is_black_win) {
            cout << tc << " " << "B" << endl;
        }
        else {
            cout << tc << " " << "W" << endl;
        }

        tc = tc + 1;
        // reset our vis array :)
        for(int i = 0; i < N; i++) {
            fill(vis[i], vis[i] + N, false);
        }
    }

    return 0;
}
