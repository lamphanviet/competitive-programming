//*****************
// LAM PHAN VIET **
// UVA 872 - Ordering
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
bool Free[maxN], cnt[maxN][maxN], No;
int Index[100];
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
    if (f) {
        printf("%c", rs[0]);
        For (i, 1, rs.length()-1) printf(" %c", rs[i]);
        printf("\n");
        No = false;
    }
}

main() {
//    freopen("872.inp", "r", stdin); freopen("872.out", "w", stdout);
    int Case, len;
    char s[500];
    scanf("%d", &Case); getchar();
    while (Case--) {
        getchar();
        gets(s); len = strlen(s);
        vector<char> tmp;
        For (i, 0, len-1)
            if (s[i]!=' ') tmp.push_back(s[i]);
        sort(tmp.begin(), tmp.end());
        n = 0;
        For (i, 0, tmp.size()-1) {
            Index[tmp[i]] = ++n;
            Name[n] = tmp[i];
        }
        memset(cnt, false, sizeof(cnt));
        memset(Free, true, sizeof(Free));
        gets(s); len = strlen(s);
        For (i, 1, len-2)
            if (s[i]=='<') {
                int u = Index[s[i-1]], v = Index[s[i+1]];
                cnt[u][v] = true;
            }
        No = true;
        BackTracking("");
        if (No) puts("NO");
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
