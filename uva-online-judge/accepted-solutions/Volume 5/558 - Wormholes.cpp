// 558 - Wormholes
#include <iostream>
#include <vector>
#define N 1005
#define INF 10000000

using namespace std;

int a[N][N], n;
vector <int> ad[N];

bool Bellman_Ford() {
    int i, j, d[n+5], k, v;
    for (i=0; i<n; i++)
        d[i] = INF;
    d[0] = 0;
    for (k=0; k<n; k++) {
        for (i=0; i<n; i++)
            for (j=0; j<ad[i].size(); j++) {
                v = ad[i][j];
                if (d[i]+a[i][v] < d[v])
                    d[v] = d[i]+a[i][v];
            }
    }
    for (i=0; i<n; i++)
        for (j=0; j<ad[i].size(); j++) {
            v = ad[i][j];
            if (d[i]+a[i][v] < d[v]) return true;
        }
    
    return false;
}

main() {
//    freopen("558.inp", "r", stdin); freopen("558.out", "w", stdout);
    int kase, i, j, m, t;
    cin >> kase;
    while (kase--) {
        cin >> n >> m;
        for (i=0; i<n; i++) ad[i].clear();
        for (i=0; i<n; i++) {
            a[i][i] = 0;
            for (j=i+1; j<n; j++)
                a[i][j] = a[j][i] = INF;
        }
        while (m--) {
            scanf("%d %d %d", &i, &j, &t);
            a[i][j] = t;
            ad[i].push_back(j);
        }
        
        bool ans = Bellman_Ford();
        if (ans) printf("possible\n");
        else printf("not possible\n");
    }
}
