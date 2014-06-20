//*****************
// LAM PHAN VIET **
// UVA 124 - Following Orders
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 30
int n;
bool cnt[maxN][maxN], Free[maxN];
int Index[130];
char Name[maxN];

void BackTracking(string rs) {
    bool f = true;
    For (i, 1, n)
        if (Free[i]) {
            bool ok = true;
            for (int j=1; j<=n && ok; j++)
                if (cnt[j][i] && Free[j]) ok = false;
            if (ok) {
                Free[i] = false;
                BackTracking(rs + Name[i]);
                Free[i] = true;
            }
            f = false;
        }
    if (f) cout << rs << endl;
}

main() {
//    freopen("124.inp", "r", stdin); freopen("124.out", "w", stdout);
    int len;
    char s[500];
    bool Line = false;
    while (gets(s)) {
        len = strlen(s);
        vector<char> tmp;
        For (i, 0, len-1)
            if (s[i]!=' ') tmp.push_back(s[i]);
        sort(tmp.begin(), tmp.end());
        n = 0;
        For (i, 0, tmp.size()-1) {
            Index[tmp[i]] = ++n;
            Name[n] = tmp[i];
        }
        memset(Free, true, n+1);
        memset(cnt, false, sizeof(cnt));
        gets(s); len = strlen(s);
        int k = 0, u, v;
        while (k<len) {
            while (s[k]==' ') k++;
            u = Index[s[k++]];
            while (s[k]==' ') k++;
            v = Index[s[k++]];
            cnt[u][v] = true;
        }
        if (Line) printf("\n"); Line = true;
        BackTracking("");
    }
}

/* lamphanviet@gmail.com - 2011 */
