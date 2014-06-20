/*****************/
/* LAM PHAN VIET */
/* UVa: 681 - Convex Hull Finding
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define maxN 520
using namespace std;

struct Point {
    int x, y;
} p[maxN];

double Theta(Point a, Point b) {
    int dx, dy, ax, ay;
    dx = b.x-a.x; ax=abs(dx);
    dy = b.y-a.y; ay=abs(dy);
    double t;
    if (!dx && !dy) t = 0;
    else t = double(dy)/(ax+ay);
    if (dx<0) t = 2-t;
    else if (dy<0) t += 4;
    return t*90.0;
}

int dis(int i, int j) {
    return (p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y);
}

main() {
//    freopen("681.inp", "r", stdin); freopen("681.out", "w", stdout);
    int Case, i, j, u, n, m;
    double mina, v;
    for (scanf("%d", &Case), printf("%d\n", Case); Case--; ) {
        scanf("%d", &n);
        for (i=1; i<=n; i++)
            cin >> p[i].x >> p[i].y;
        
        for (i=u=1; i<=n; i++)
            if (p[i].y<p[u].y || (p[i].y==p[u].y && p[i].x>p[u].x)) u=i;

        p[n+1] = p[u]; mina = 0; m=0;
        
        do {
            Point t = p[++m]; p[m] = p[u]; p[u] = t;
            v = mina; mina = 360.0; u=n+1;
            for (i=m+1; i<=n+1; i++) {
                double tempa = Theta(p[m], p[i]);
                if ((tempa<mina || (tempa==mina && dis(m, i)>dis(m, u))) && tempa>v) {
  //              if (tempa<mina && tempa>v) {
                    u = i; mina = tempa;
                }
            }
            
        } while (!(p[u].x==p[n+1].x && p[u].y==p[n+1].y));
        printf("%d\n", m + 1);
        int s=1, f=m;
        if (p[m].y==p[1].y) f--;
        else {
            m=1; s++;
        }
        printf("%d %d\n", p[m].x, p[m].y);
        for (i = s; i <= f; i++)
            printf("%d %d\n", p[i].x, p[i].y);
        printf("%d %d\n", p[m].x, p[m].y);
        if (Case) {
            scanf("%d", &i);
            puts("-1");
        }
    }
}
