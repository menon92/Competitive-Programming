//----------------------------------
// Problem : 762-We Ship Cheap.
// Status  : Accepted.
// Author  : Md.Mehadi Hasan Menon.
// Submission date : 27-01-2016.
//----------------------------------
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map <string, int> visited;
map <string, string> parent;

int bfs(string sourceCity, string destinationCity, map <string, vector <string> > graph)
{
	queue <string> QQ;

	QQ.push(sourceCity);
	visited[sourceCity] = 1;

	while(!QQ.empty())
	{
		string top, child;
		int vsize;

		top = QQ.front();
		vsize = graph[top].size();

		// if we get our final destinatioin city
		// then don't need to continut;
		if(top == destinationCity)
			return visited[top];

		for(int i = 0; i < vsize; i++)
		{
			child = graph[top][i];

			if(visited[child] == -1)
			{
				visited[child] = 1;

				parent[child] = top;

				QQ.push(child);
			}
		}
		QQ.pop();
	}

	return -1;
}

void printPath(string destination, string source)
{
	if(destination == source)
		return;

	// backtrack for printing in forward worder.
	printPath(parent[destination], source);

	cout << parent[destination] << " " << destination << endl;
}

int main()
{
//    map <string, vector <string> > mp;
//---------------------------------
//    mp["jv"].push_back("pt");
//    mp["jv"].push_back("px");
//    mp["jv"].push_back("pz");
//
//    cout << mp["jv"][0] << endl;
//    cout << mp["jv"][1] << endl;
//    cout << mp["jv"][2] << endl;
//----------------------------------

    int edge;
	bool flag = false;

    //freopen("762.txt", "r+", stdin);

	while(cin >> edge)
	{
        map <string, vector<string> > graph;
        string firstCity, secondCity;
        string sourceCity, destinationCity;

		for(int i = 0; i < edge; i++)
		{
			cin >> firstCity >> secondCity;

			graph[firstCity].push_back(secondCity);
			graph[secondCity].push_back(firstCity);

			visited[firstCity] = -1;
			visited[secondCity] = -1;

		}
		cin >> sourceCity >> destinationCity;

		//cout << bfs(sourceCity, destinationCity, graph) << endl;

		// skipe the last new line;
		if(flag)
            cout << endl;
        flag = true;

		if(bfs(sourceCity, destinationCity, graph) != -1) {
			printPath(destinationCity, sourceCity);
		}
		else
			cout << "No route" << endl;
	}

	return 0;
}
