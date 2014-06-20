//*****************
// LAM PHAN VIET **
// UVA 10171 - Meeting Prof. Miguel...
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 30
int n, c[2][maxN][maxN];   // young: 0 - old: 1
int Index[100], s, f;
char Name[maxN], U, V;

void Init() {
    For (i, 1, maxN-1) {
        For (j, i+1, maxN-1) {
            c[0][i][j] = c[0][j][i] = INF;
            c[1][i][j] = c[1][j][i] = INF;
        }
        c[0][i][i] = c[1][i][i] = 0;
    }
    For (i, 'A', 'Z') Index[i] = 0;
    n = 0;
}

void ReadInput(int m) {
    char age, direct;
    int u, v, cost;
    while (m--) {
        getchar();
        scanf("%c %c %c %c %d", &age, &direct, &U, &V, &cost);
//        printf("%c %c %c %c %d\n", age, direct, U, V, cost);
        age = (age=='Y')?0:1;
        u = Index[U];
        if (u==0) {
            Name[++n] = U;
            u = Index[U] = n;
        }
        v = Index[V];
        if (v==0) {
            Name[++n] = V;
            v = Index[V] = n;
        }
        c[age][u][v] = min(c[age][u][v], cost);
        if (direct=='B') c[age][v][u] = min(c[age][v][u], cost);
    }
    getchar();
    scanf("%c %c", &U, &V);
//    printf("%c %c\n", u, v);
    s = Index[U]; f = Index[V];
//    printf("sf %d %d\n", s, f);
}

void Dijkstra(int x, int age) {
    bool Free[n+1];
    memset(Free, true, n+1);
    while (1) {
        int u = 0, tmpmin = INF;
        For (i, 1, n)
            if (Free[i] && c[age][x][i]<tmpmin) {
                tmpmin = c[age][x][i];
                u = i;
            }
        if (u==0) return;
        Free[u] = false;
        For (v, 1, n) {
            int cost = c[age][x][u] + c[age][u][v];
            if (Free[v] && cost < c[age][x][v])
                c[age][x][v] = cost;
        }
    }
}

void Solve() {
    if (!s || !f) {
        if (U==V) {
            printf("0 %c\n", U);
            return;
        }
        puts("You will never meet."); return;
    }
    Dijkstra(s, 0); Dijkstra(f, 1);
    int mincost = INF;
    For (i, 1, n)
        mincost = min(mincost, c[0][s][i] + c[1][f][i]);
    if (mincost==INF) {
        puts("You will never meet."); return;
    }
    vector<char> ans;
    For (i, 1, n)
        if (c[0][s][i] + c[1][f][i] == mincost) ans.push_back(Name[i]);
    sort(ans.begin(), ans.end());
    printf("%d", mincost);
    For (i, 0, ans.size()-1) printf(" %c", ans[i]);
    printf("\n");
}

main() {
//    freopen("171.inp", "r", stdin); freopen("171.out", "w", stdout);
    int m;
    while (scanf("%d", &m) && m) {
        Init();
        ReadInput(m);
        Solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
