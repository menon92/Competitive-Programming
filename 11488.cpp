/**
  * Problem : 11488 - Hyper Prefix Sets.
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Time    : 0.090
  **/
#include <iostream>
using namespace std;

struct Node {
    long long int _end;
    Node *next[3];
    Node() {
        for(int i = 0; i < 3; i++) {
            next[i] = nullptr;
            _end = 0;
        }
    }
};
Node *root;
long long int ans;

void Insert(char *s)
{
    Node *curr = root;
    int id;
    for(int i = 0; s[i]; i++)
    {
        id = s[i] - '0';
        if(curr->next[id] == nullptr) {
            curr->next[id] = new Node();
        }
        curr = curr->next[id];

        curr->_end = curr->_end + 1;
        ans = max(ans, curr->_end * (i + 1));
    }
}
int main()
{
    freopen("input.txt", "r+", stdin);

    int n, tc;
    char str[201];

    scanf("%d", &tc);
    while(tc--)
    {
        root = new Node();

        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str);

            Insert(str);
        }
        printf("%lld\n", ans);
        ans = 0;
    }
    return 0;
}
