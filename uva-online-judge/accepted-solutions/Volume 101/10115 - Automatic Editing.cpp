//*****************
// LAM PHAN VIET **
// UVA 10115 - Automatic Editing
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 12
int n;
string s, fnd[maxN], rep[maxN];

bool Compare(string f, int k) {
    string subs = s.substr(k, f.length());
    return subs == f;
}

void FindAndReplace(string f, string r) {
    int lens = s.length();
    for (int i=0; i<lens; i++)
        if (s[i]==f[0] && Compare(f, i)) {
            s.replace(i, f.length(), r);
            i -=  f.length();
            if (i<0) i = -1;
            lens = s.length();
//            cout << s << endl;
        }
}

main() {
//    freopen("115.inp", "r", stdin); freopen("115.out", "w", stdout);
    while (scanf("%d", &n) && n) {
        getline(cin, s);
        For (i, 1, n) {
            getline(cin, fnd[i]);
            getline(cin, rep[i]);
        }
        getline(cin, s);
        
        For (i, 1, n) {
            FindAndReplace(fnd[i], rep[i]);
        }
        cout << s << endl;
    }
}

/* lamphanviet@gmail.com - 2011 */
