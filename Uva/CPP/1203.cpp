// Uva - 1203
#include <iostream>
#include <queue>
using namespace std;
struct Quary
{
    int id;
    int start_time;
    int current_time;

    bool operator < (const Quary &q) const
    {
        if(current_time == q.current_time) {
            return id > q.id;
        }
        else {
            return current_time > q.current_time;
        }
    }
};

int main()
{
   // freopen("H.txt", "r+", stdin);

    priority_queue <Quary> pq;
    Quary q;
    string s;
    int id; int time; int k;

    while(cin >> s && s != "#")
    {
        cin >> id >> time;

        q.id = id;
        q.start_time = time;
        q.current_time = time;

        pq.push(q);
    }

    Quary temp;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        temp = pq.top();
        pq.pop();

        cout << temp.id << endl;

        temp.current_time = temp.current_time + temp.start_time;
        pq.push(temp);
    }

    return 0;
}
