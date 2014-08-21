//*****************
// LAM PHAN VIET **
// UVA 10336 - Rank the Languages
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define N 105

using namespace std;

int n, m;
char s[N][N], ch;

struct ANS {
    int num;
    char ch;
} ans[30];

bool cmp(ANS a, ANS b) {
    return (a.num>b.num || (a.num==b.num && a.ch<b.ch));
}

void DFS(int u, int v) {
    if (u<0 || u>=n || v<0 || v>=m || s[u][v]!=ch) return;
    
    s[u][v] = '*';
    DFS(u-1, v); DFS(u, v-1);
    DFS(u+1, v); DFS(u, v+1);
}

main() {
//    freopen("336.inp", "r", stdin); freopen("336.out", "w", stdout);
    int i, j, k, kase;
    cin >> kase;
    for (int t=1; t<=kase; t++) {
        cin >> n >> m; cin.get();
        for (i=0; i<n; i++)
            gets(s[i]);
        
        for (i=0; i<26; i++) {
            ans[i].num = 0; ans[i].ch = i+97;
        }
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                if (s[i][j]!='*') {
                    ch = s[i][j];
                    DFS(i, j);
                    ans[ch-97].num++;
                }
        sort(ans, ans+26, cmp);
        printf("World #%d\n", t);
        i=0;
        while (i<26 && ans[i].num!=0) {
            printf("%c: %d\n", ans[i].ch, ans[i].num);
            i++;
        }
    }
}
