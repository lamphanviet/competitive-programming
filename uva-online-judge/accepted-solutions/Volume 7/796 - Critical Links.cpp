//*****************
// LAM PHAN VIET **
// UVA 796 - Critical Links
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 10000
class Pair {
public:
    int u, v;
    Pair() { u=v=0; }
    Pair(int x, int y) {
        if (x<y) {
            u = x; v = y;
        }
        else {
            u = y; v = x;
        }
    }
};
int n, Parent[maxN];
int Number[maxN], Low[maxN], Count;
bool a[maxN][maxN];

bool cmp(Pair a, Pair b) {
    return (a.u<b.u || (a.u==b.u && a.v<b.v));
}

void Visit(int u) {
    Number[u] = ++Count;
    Low[u] = n+1;
    for (int v=0; v<n; v++)
        if (a[u][v]) {
            a[v][u] = false;
            if (Parent[v]!=-1) Low[u] = min(Low[u], Number[v]);
            else {
                Parent[v] = u;
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
        }
}

main() {
//    freopen("796.inp", "r", stdin); freopen("796.out", "w", stdout);
    while (scanf("%d", &n)!=EOF) {
        // Init
        for (int i=0; i<n; i++) {
            memset(a[i], false, n+1);
            Parent[i] = -1;
        }
        // Read Input
        for (int i=0; i<n; i++) {
            int u, v, m;
            scanf("%d (%d)", &u, &m);
//            printf("%d %d: ", u, m);
            while (m--) {
                scanf("%d", &v);
//                printf("%d ", v);
                a[u][v] = a[v][u] = true;
            }
//            printf("\n");
        }
        // Solve
        Count = 0;
        for (int i=0; i<n; i++)
            if (Parent[i]==-1) {
                Parent[i] = -2;
                Visit(i);
            }
        // Result
        vector<Pair> result;
        for (int v=0; v<n; v++) {
            int u = Parent[v];
            if (u!=-2 && Low[v]>=Number[v])
                result.push_back(Pair(u, v));
        }
        sort(result.begin(), result.end(), cmp);
        printf("%d critical links\n", result.size());
        for (int i=0; i<result.size(); i++)
            printf("%d - %d\n", result[i].u, result[i].v);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
