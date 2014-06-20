//*****************
// LAM PHAN VIET **
// UVA 11518 - Dominos 2
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dsk[10005][10005], n, m, l, dem;
bool Free[10005];

void BFS(int u) {
    int i;
    queue <int> Queue;
    
    Queue.push(u); Free[u] = false;
    while (!Queue.empty()) {
        u = Queue.front(); Queue.pop();
        dem++;
        for (i=1;i<=dsk[u][0];i++)
            if (Free[dsk[u][i]]) {
                Queue.push(dsk[u][i]);
                Free[dsk[u][i]] = false;
            }
    }
}

main() {
    int kase, u, v, i;
    cin >> kase;
    while (kase--) {
        cin >> n >> m >> l;
        for (i=1;i<=n;i++) {
            Free[i] = true;
            dsk[i][0] = 0;
        }
        
        for (i=1;i<=m;i++) {
            cin >> u >> v;
            dsk[u][++dsk[u][0]] = v;
        }
        
        dem = 0;
        for (i=1;i<=l;i++) {
            cin >> u;
            if (Free[u]) BFS(u);
        }
        
        printf("%d\n", dem);
    }
}
