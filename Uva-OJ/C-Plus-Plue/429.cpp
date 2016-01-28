//-------------------------------------
// Problem : 429-Word Transformation.
// Status  : Accepted.
// Author  : Mehadi Hasan Menon.
// Submission Date : 29-01-2016.
//-------------------------------------

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>

using namespace std;

bool isOneCharDiff(string a, string b);
int bfs(string startingWord, string endingWord, map <string, vector <string> > graph, map <string, int> visited);

int main()
{
    int tcase;
    string word;

   // freopen("429.txt", "r+", stdin);

    cin >> tcase;
    while(tcase--)
    {
        map <string, vector<string> > graph;
        map <string, int> visited;
        string dictionary[205];
        int i;

        // take input into our dictionary.
        i = 0;
        while(cin >> word && word != "*") {
            dictionary[i++] = word;
        }

        // make a graph from a given dictionary;
        for(int j = 0; j < i - 1; j++)
        {
            for(int k = j + 1; k < i; k++)
            {
                // if two word is different in one char then there is
                // a edge between this two word;
                if(isOneCharDiff(dictionary[j], dictionary[k]))
                {
                    graph[dictionary[j]].push_back(dictionary[k]);
                    graph[dictionary[k]].push_back(dictionary[j]);

                    visited[dictionary[j]] = 0;
                    visited[dictionary[k]] = 0;
                }
            }
        }

        string startingWord, endingWord;
        string line;
        int moves;

        getchar(); // this is for skipe a space from input.
        while(getline(cin, line) && line != "")
        {
            int pos;

            pos = line.find(" "); // get the position.

            startingWord = line.substr(0, pos); // coppy before space.
            endingWord = line.substr(pos + 1, line.length()); // coppy after space.

            moves = bfs(startingWord, endingWord, graph, visited);

            cout << startingWord << " " << endingWord << " " << moves << endl;
        }
        if(tcase > 0)
            cout << endl;
    }
    return 0;
}

bool isOneCharDiff(string a, string b)
{
    int len_a, len_b, cnt;

    len_a = a.length();
    len_b = b.length();
    cnt = 0;

    if(len_a == len_b)
    {
        for(int i = 0; i < len_a && cnt < 2; i++)
        {
            if(a[i] != b[i])
                cnt++;
        }
        if(cnt == 1)
            return true;
        else
            return false;
    }
    return false;
}

int bfs(string startingWord, string endingWord, map <string, vector <string> > graph, map <string, int> visited)
{
    queue <string> QQ;
    map <string, int> d;

    d[startingWord] = 0;
    visited[startingWord] = 1;

    QQ.push(startingWord);

    while(!QQ.empty())
    {
        string top, child;
        int vsize;

        top = QQ.front();
        vsize = graph[top].size();

        if(top == endingWord) {
            return d[top];
        }

        for(int i = 0; i < vsize; i++)
        {
            child = graph[top][i];

            if(visited[child] == 0)
            {
                visited[child] = 1;
                d[child] = d[top] + 1;
                QQ.push(child);
            }
        }
        QQ.pop();
    }
    return -1;
}
