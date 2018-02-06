/*
  Status : Accepted.
*/
#include <iostream>
#include <cstdio>
#include <vector>

#define debug(a) cout << "debug : " << a << endl;

using namespace std;

struct pairs {
    int lower, upper;
} p[100000];

struct result {
    string name;
    int c_d[10000];
    int c_not;
    int CD;
    int dd;
} results[10000];

//struct test
//{
//   char s[30] = "string input to read";
//} t[1000];

int main()
{
    int n, r, cd, b, d;
    vector <int> c_array;

//    cout << t.s << endl;
//    cout << t.s[0] << endl;
//    cout << t.s[1] << endl;
//    cout << t.s[2] << endl;
//    cout << t.s[3] << endl;
//    cout << t.s[4] << endl;
//    t.s[0] = 'X';
//    cout << t.s << endl;
//    cout << t[0].s << endl;
//    cout << t[0].s[0] << endl;
    // output is as expected ;

//    cout << "THREE" << "[";
//    cout << 1 << ", ";
//    cout << 4 << ", ";
//    cout << 0 << ", ";
//    cout << 9 << ",";
//    cout << "] = ";
//    cout << 14256;
//    cout << endl;


    freopen("input.txt", "r", stdin);

    cin >> n >> r;
    for(int i = 0, index = 0; i < n; i++, index++)
    {
        string tname;

        cin >> tname >> b >> cd >> d;
        for(int j = 0; j < d; j++)
        {
            cin >> p[j].lower >> p[j].upper;
        }


        int temp, k;
        // calculate C0
        bool flag = true;
        k = d - 1;
        //cout << cd << " " << p[k].lower << endl;
        results[index].name = tname;
        results[index].CD = cd;
        results[index].dd = d;
        b = b - cd * p[k].lower;
        //cout << b << endl;
        for(int k = d - 1, c_i = 0; k > 0; k--, c_i++)
        {
            //cout << p[k].upper << " : " << p[k].lower << " : " << cd  << endl;
//            if(flag)
//            {
//                flag = false;
//                temp = cd * p[k].lower;
//            }
//            else
            //we need c2, l2, u2 to calculate c1 = temp;
            temp = cd * ((p[k].upper - p[k].lower) + 1);
            //cout << temp << endl;
            results[index].c_d[c_i] = temp;
            int pos = k - 1; // hare we need to use c1 lower value this why --;
            b = b - (temp * p[pos].lower);
            cd = temp;
        }
        results[index].c_not = b;
        results[index].name = tname;
       // cout << name << " : " << b << endl;
       // store our result;
//       result rr;
//       rr.name = tname;
//       rr.referance = b;
    }

//    for(int i = 0; i < n; i++)
//    {
//        cout << results[i].name << " :";
//        cout << "dd: " << results[i].dd << endl;;
//        for(int j = 0; j < results[i].dd - 1; j++)
//        {
//           // cout << "IN" << endl;
//            cout << results[i].c_d[j] << ", ";
//        }
//        cout << endl;
//        cout << results[i].CD << " : " << results[i].c_not << endl;
//        cout << endl;
//
//    }
//    cout << endl;
//    cout << endl;


    // 2nd test
    string name;
    int ndymension, ans, sum;
    ans = 0;
    for(int i = 0; i < r; i++)
    {
        cin >> name;
        // find the location of the tergated name;
        int tar;
        for(tar = 0; tar < n; tar++)
        {
            if(name == results[tar].name)
                break;
        }
        ans = results[tar].c_not;
        //cout << ans << endl;
        cout << name << "[";
        int j, k;
        for(j = 0, k = results[tar].dd - 2; j < results[tar].dd - 1; j++, k--)
        {
            cin >> ndymension;
            cout << ndymension << ", ";
            //if(j > 0)
             //   cout << ", ";
            //cout << "nd: " << ndymension << " " << "r: " << results[i].c_d[j] << endl;
           // ans = ans + (results[i].c_d[j] * ndymension);
            // we have to go reverse but before statement go forward.
            ans = ans + (results[tar].c_d[k] * ndymension);
        }

//        for(int k = j - 2, l = 0; k >= 0; k--, l++)
//        {
//            ans += results[k].c_d[k] * ndymension[l];
//        }

        int last;
        cin >> last;
        cout << last << "] = ";
        //cout << "after loop: " << "nd: " << last << " rd: " << results[tar].CD << endl;
        ans = ans + (last * results[tar].CD);
        cout << ans << endl;

        //cout << name << " : " << ans << endl;
    }

    return 0;
}
