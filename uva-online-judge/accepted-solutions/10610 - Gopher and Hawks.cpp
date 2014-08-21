//*****************
// LAM PHAN VIET **
// UVA 10610 - Gopher and Hawks
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1005
#define INF 200000000
int n, d[maxN], V, M;
bool a[maxN][maxN];
double x[maxN], y[maxN], D;

bool isOK(int i, int j) {
    double a = x[i]-x[j];
    double b = y[i]-y[j];
    double dis = sqrt(a*a+b*b);
    return (dis <= D);
}

int BFS() {
    queue<int> Queue;
    d[0] = 0;
    Queue.push(0);
    while (!Queue.empty()) {
        int u = Queue.front(); Queue.pop();
        For(v, 0, n-1)
            if (d[v]==INF && a[u][v]) {
                if (v==1) return d[u];
                d[v] = d[u]+1;
                Queue.push(v);
            }
    }
    return -1;
}

main() {
//    freopen("610.inp", "r", stdin); freopen("610.out", "w", stdout);
    char s[30];
    while (scanf("%d %d", &V, &M) && (V || M)) {
        D = V*M*60.0;
        n = 0; gets(s);
        while (gets(s)) {
            if (strlen(s)==0) break;
            sscanf(s, "%lf %lf", &x[n], &y[n]);
            n++;
        }
        For(i, 0, n-1) {
            a[i][i] = true;
            d[i] = INF;
            For(j, i+1, n-1)
                a[i][j] = a[j][i] = isOK(i, j);
        }
        int ans = BFS();
        if (ans<0) puts("No.");
        else printf("Yes, visiting %d other holes.\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
