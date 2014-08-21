//*****************
// LAM PHAN VIET **
// UVA 10731 - Test
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <stack>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 30
int n, Count;
int Low[maxN], Number[maxN];
bool cnt[maxN][maxN], Free[maxN];
int Index[100];
char Name[maxN];
vector<string> ans;
stack<int> S;

void Init() {
    For (i, 1, maxN-1) {
        memset(cnt[i], false, maxN);
        Number[i] = 0;
        Free[i] = true;
    }
    For (i, 'A', 'Z') Index[i] = 0;
    Count = n = 0;
    S = stack<int>();
    ans.clear();
}

void Visit(int u) {
    S.push(u);
    Number[u] = Low[u] = ++Count;
    For (v, 1, n)
        if (Free[v] && cnt[u][v]) {
            if (Number[v]) Low[u] = min(Low[u], Number[v]);
            else {
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
        }
    if (Low[u]==Number[u]) {
        int v;
        string tmp = "";
        do {
            v = S.top(); S.pop();
            Free[v] = false;
            tmp += Name[v];
        } while (v!=u);
        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }
}

main() {
//    freopen("731.inp", "r", stdin); freopen("731.out", "w", stdout);
    char c[7], ch;
    int x[7], u, m;
    bool Line = false;
    while (scanf("%d", &m) && m) {
        Init();
        while (m--) {
            For (i, 1, 5) {
                scanf(" %c ", &c[i]);
                x[i] = Index[c[i]];
                if (x[i]==0) {
                    x[i] = Index[c[i]] = ++n;
                    Name[x[i]] = c[i];
                }
            }
            scanf(" %c ", &ch);
            u = Index[ch];
            if (u==0) {
                u = Index[ch] = ++n;
                Name[u] = ch;
            }
            For (i, 1, 5)
                cnt[u][x[i]] = true;
        }
        
        For (i, 1, n)
            if (Number[i]==0) Visit(i);
        sort(ans.begin(), ans.end());
        
        if (Line) printf("\n"); Line = true;
        for (int i=0; i<ans.size(); i++) {
            int len = ans[i].length();
            printf("%c", ans[i][0]);
            for (int j=1; j<len; j++)
                printf(" %c", ans[i][j]);
            printf("\n");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
