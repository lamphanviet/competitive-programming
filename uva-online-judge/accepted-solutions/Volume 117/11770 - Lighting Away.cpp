//----------------------------
// LAM PHAN VIET
// UVA 11770 - Lighting Away
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

#define maxN 10001
int n, Number[maxN], Low[maxN], Index;
int Part[maxN], nPart;
vector<int> ke[maxN];
stack<int> Stack;

void Init() {
    Index = nPart = 0;
    for (int i=0; i<maxN; i++) {
        Number[i] = Part[i] = 0;
        ke[i].clear();
    }
    while (!Stack.empty()) Stack.pop();
}

void Visit(int u) {
    Number[u] = Low[u] = ++Index;
    Stack.push(u);
    int v;
    for (int i=0, sizeu=ke[u].size(); i<sizeu; i++) {
        v = ke[u][i];
        if (Part[v]) continue;
        if (Number[v])
            Low[u] = min(Low[u], Number[v]);
        else {
            Visit(v);
            Low[u] = min(Low[u], Low[v]);
        }
    }
    
    if (Low[u]==Number[u]) {
        nPart++;
        do {
            v = Stack.top(); Stack.pop();
            Part[v] = nPart;
        } while (v!=u);
    }
}

int Solve() {
    for (int i=1; i<=n; i++)
        if (!Number[i]) Visit(i);
    
    bool Free[nPart+1];
    memset(Free, true, nPart+1);
    for (int u=1; u<=n; u++)
        for (int i=0, sizeu=ke[u].size(); i<sizeu; i++) {
            int v = ke[u][i];
            if (Part[v]!=Part[u]) Free[Part[v]] = false;
        }
    int ans = 0;
    for (int i=1; i<=nPart; i++)
        if (Free[i]) ans++;
    return ans;
}

main() {
//    freopen("770.inp", "r", stdin); freopen("770.out", "w", stdout);
    int Case, u, v, m;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d %d", &n, &m);
        Init();
        while (m--) {
            scanf("%d %d", &u, &v);
            ke[u].push_back(v);
        }
        printf("Case %d: %d\n", kk, Solve());
    }
}
