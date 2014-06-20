//----------------------------
// LAM PHAN VIET
// UVA 11709 - Trust groups
// Time limit: 5s
//----------------------------
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define maxN 1005
int n, m, Count, nodeindex;
int Number[maxN], Low[maxN];
bool Free[maxN];
vector<int> ke[maxN];
map<string, int> Index;
int Stack[maxN], Top;

void ReadInput() {
    string name1, name2;
    Index.clear();
    scanf(" ");
    for (int i=1; i<=n; i++) {
        getline(cin, name1);
        Index[name1] = i;
        Free[i] = true;
        Number[i] = 0;
        ke[i].clear();
    }
    while (m--) {
        getline(cin, name1);
        getline(cin, name2);
        ke[Index[name1]].push_back(Index[name2]);
    }
}

void Visit(int u) {
    Number[u] = Low[u] = ++nodeindex;
    Stack[++Top] = u;
    
    for (int i=0, sizeu = ke[u].size(); i<sizeu; i++) {
        int v = ke[u][i];
        if (!Free[v]) continue;
        if (Number[v])
            Low[u] = min(Low[u], Number[v]);
        else {
            Visit(v);
            Low[u] = min(Low[u], Low[v]);
        }
    }
    
    if (Number[u] == Low[u]) {
        Count++;
        int v;
        do {
            v = Stack[Top--];
            Free[v] = false;
        } while (v!=u);
    }
}

main() {
//    freopen("709.inp", "r", stdin); freopen("709.out", "w", stdout);
    while (scanf("%d %d", &n, &m)) {
        if (!n && !m) break;
        ReadInput();
        Count = nodeindex = Top = 0;
        for (int i=1; i<=n; i++)
            if (!Number[i]) Visit(i);
        printf("%d\n", Count);
    }
}
