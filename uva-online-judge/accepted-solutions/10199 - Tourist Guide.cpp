//*****************
// LAM PHAN VIET **
// UVA 10199 - Tourist Guide
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define maxN 102
int n, Parent[maxN], nChildren[maxN];
int Number[maxN], Low[maxN], Count;
bool a[maxN][maxN], IsCut[maxN];
char s[maxN][35];
map<string, int> Index;

void Enter() {
    for (int i=1; i<=n; i++) {
        memset(a[i], false, n+2);
        Parent[i] = 0;
        nChildren[i] = 0;
        IsCut[i] = false;
    }
    Index.clear();
    gets(s[0]);
    for (int i=1; i<=n; i++) {
        gets(s[i]);
        Index[s[i]] = i;
    }
    int m, u, v;
    char s1[35], s2[35];
    scanf("%d", &m); gets(s[0]);
    while (m--) {
        scanf("%s %s", &s1, &s2);
        u = Index[s1]; v = Index[s2];
        a[u][v] = a[v][u] = true;
    }
}

void Visit(int u) {
    Number[u] = ++Count;
    Low[u] = n+1;
    for (int v=1; v<=n; v++)
        if (a[u][v]) {
            a[v][u] = false;
            if (Parent[v]) Low[u] = min(Low[u], Number[v]);
            else {
                Parent[v] = u;
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
        }
}

void Result(int Case) {
    for (int i=1; i<=n; i++)
        if (Parent[i]!=-1) nChildren[Parent[i]]++;
    for (int v=1; v<=n; v++)
        if (Parent[v]!=-1) {
            int u = Parent[v];
            if (Low[v]>=Number[u])
                IsCut[u] = IsCut[u] || (Parent[u]!=-1) || (nChildren[u]>=2);
        }
    vector<string>result;
    for (int v=1; v<=n; v++)
        if (IsCut[v]) result.push_back(s[v]);
    sort(result.begin(), result.end());
    if (Case!=1) printf("\n");
    printf("City map #%d: %d camera(s) found\n", Case, result.size());
    for (int i=0; i<result.size(); i++)
        cout << result[i] << endl;
}

main() {
//    freopen("199.inp", "r", stdin); freopen("199.out", "w", stdout);
    int Case = 0;
    while (scanf("%d", &n) && n) {
        Enter();
        Count = 0;
        for (int i=1; i<=n; i++)
            if (Parent[i]==0) {
                Parent[i] = -1;
                Visit(i);
            }
        Result(++Case);
    }
}

/* lamphanviet@gmail.com - 2011 */
