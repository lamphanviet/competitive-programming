//----------------------------
// LAM PHAN VIET
// UVA 11504 - Dominos
// Time limit: 3.000s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100001
int n, Part[maxN], Count;
bool Free[maxN];
vector< vector<int> > adj, radj;
vector<int> Node;

void Init() {
    memset(Free, true, n+1);
    adj = vector< vector<int> >(n+1);
    radj = vector< vector<int> >(n+1);
    Count = 0;
    Node.clear();
}

void DFS1(int u) {
    Free[u] = false;
    for (int i=0, size=adj[u].size(); i<size; i++)
        if (Free[adj[u][i]]) DFS1(adj[u][i]);
    Node.push_back(u);
}

void DFS2(int u, int p) {
    Free[u] = true;
    Part[u] = p;
    for (int i=0, size=radj[u].size(); i<size; i++)
        if (!Free[radj[u][i]]) DFS2(radj[u][i], p);
}

main() {
//    freopen("504.inp", "r", stdin); freopen("504.out", "w", stdout);
    int Case, m, u, v;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        Init();
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        For (i, 1, n)
            if (Free[i]) DFS1(i);
        int nPart = 0;
        for (int i=Node.size()-1; i>=0; i--)
            if (!Free[Node[i]]) DFS2(Node[i], ++nPart);
        bool Com[nPart+1];
        memset(Com, true, nPart+1);
        For (u, 1, n)
            for (int i=0, size=adj[u].size(); i<size; i++) {
                int v = adj[u][i];
                if (Part[u]!=Part[v]) Com[Part[v]] = false;
            }
        int ans = 0;
        For (i, 1, nPart)
            if (Com[i]) ans++;
        printf("%d\n", ans);
    }
}




/*  RUNTIME ERROR   

#define maxN 500002
int n, Number[maxN], Low[maxN], Index;
int Part[maxN], nPart;
vector< vector<int> > adj;
stack<int> Stack;

void Init() {
    nPart = Index = 0;
    for (int i=0; i<=n; i++) {
        Part[i] = Number[i] = 0;
        vector<int> tmp;
    }
    Stack = stack<int>();
    adj = vector< vector<int> >(n+1);
}

void Visit(int u) {
    Number[u] = Low[u] = ++Index;
    Stack.push(u);
    int v;
    for (int i=0, sizeu=adj[u].size(); i<sizeu; i++) {
        v = adj[u][i];
        if (Part[v]) continue;
        if (Number[v]) Low[u] = min(Low[u], Number[v]);
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

void Solve() {
    for (int i=1; i<=n; i++)
        if (!Number[i]) Visit(i);
    
    bool Free[nPart+1];
    memset(Free, true, nPart+1);
    for (int u=1; u<=n; u++)
        for (int i=0, sizeu=adj[u].size(); i<sizeu; i++) {
            int v = adj[u][i];
            if (Part[v]!=Part[u]) Free[Part[v]] = false;
        }
    int result = 0; 
    for (int i=1; i<=nPart; i++)
        if (Free[i]) result++;
    printf("%d\n", result);
}

main() {
//    freopen("504.inp", "r", stdin); freopen("504.out", "w", stdout);
    int m, u, v, Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        Init();
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        Solve();
    }
}
    RUNTIME ERROR   */
