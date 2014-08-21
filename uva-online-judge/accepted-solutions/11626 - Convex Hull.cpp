//----------------------------
// LAM PHAN VIET
// UVA 11626 - Convex Hull
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define maxN 100005
typedef struct Point {
    int x, y;
};
Point p[maxN];
int n;

double Theta(Point A, Point B) {
    double dx, dy, ax, ay, t;
    dx = B.x - A.x; ax = fabs(dx);
    dy = B.y - A.y; ay = fabs(dy);
    if (dx==0 && dy==0) t = 0;
    else t = dy/(ax+ay);
    
    if (dx<0) t = 2 - t;
    else if (dy<0) t += 4;
    return t;
}

double Dis(Point A, Point B) {
    double dx = A.x-B.x, dy = A.y-B.y;
    return sqrt(dx*dx + dy*dy);
}

bool cmp(Point a, Point b) {
    double Tta = Theta(p[0], a); 
    double Ttb = Theta(p[0], b);
    return (Tta<Ttb || (Tta==Ttb && Dis(p[0], a)<Dis(p[0], b)));
}

void Reverse(int u, int v) {
    for (int i=u, j=v; i<j; i++, j--)
        swap(p[i], p[j]);
}

main() {
//    freopen("626.inp", "r", stdin); freopen("626.out", "w", stdout);
    int Case, x, y, m;
    char ch;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &m);
        n = 0;
        int u = 0;
        while (m--) {
            scanf("%d %d %c", &x, &y, &ch);
            if (ch=='Y') {
                p[n].x=x; p[n].y=y;
                if (p[n].y<p[u].y || (p[n].y==p[u].y && p[n].x<p[u].x)) u = n;
                n++;
            }
        }
        swap(p[0], p[u]);
        sort(p+1, p+n, cmp);
        
        double iTheta = Theta(p[0], p[1]);
        int j = 1;
        while (iTheta==Theta(p[0], p[j+1])) j++;
        if (j>1 && Theta(p[1], p[j+1]) > Theta(p[j], p[j+1]))
            Reverse(1, j);
        
        iTheta = Theta(p[0], p[n-1]);
        j = n-1;
        while (iTheta==Theta(p[0], p[j-1])) j--;
        if (j<n-1 && Theta(p[j-1], p[j]) > Theta(p[j-1], p[n-1]))
            Reverse(j, n-1);
        
        u = 0;
        for (int i=1; i<n; i++)
            if (p[i].x<p[u].x || (p[i].x==p[u].x && p[i].y<p[u].y)) u = i;
            
        printf("%d\n", n);
        for (int i=u; i<n; i++)
            printf("%d %d\n", p[i].x, p[i].y);
        for (int i=0; i<u; i++)
            printf("%d %d\n", p[i].x, p[i].y);
    }
}
