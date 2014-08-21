// 10946 - You want what filled?
#include <iostream>
#include <queue>

using namespace std;

int n, m, dem;
char s[55][55];

struct Answers {
    char ch; int num;
} ans[2600];

bool cmp(Answers a, Answers b) {
    return (a.num>b.num || (a.num==b.num && a.ch<b.ch));
}

void DFS(int u, int v, char ch) {
    if (u<0 || u>=n || v<0 || v>=m || s[u][v]!=ch) return;
    
    s[u][v] = '*'; dem++;
    DFS(u-1, v, ch); DFS(u+1, v, ch);
    DFS(u, v-1, ch); DFS(u, v+1, ch);
}

main() {
//    freopen("946.inp", "r", stdin); freopen("946.out", "w", stdout);
    int i, j, k, kase = 0;
    while (cin >> n >> m) {
        if (!n && !m) break;
        cin.get();
        for (i=0; i<n; i++)
            gets(s[i]);
        
        k = 0;
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                if (s[i][j]!='.' && s[i][j]!='*') {
                    ans[k].ch = s[i][j];
                    dem = 0; DFS(i, j, s[i][j]);
                    ans[k++].num = dem;
                }
                
        sort(ans, ans+k, cmp);
        printf("Problem %d:\n", ++kase);
        for (i=0; i<k; i++)
            printf("%c %d\n", ans[i].ch, ans[i].num);
        
    }
}
