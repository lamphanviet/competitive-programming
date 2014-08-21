//----------------------------
// LAM PHAN VIET
// UVA 784 - Maze Exploration
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Point {
    int x, y;
};

char s[35][85];
Point start;

void BFS() {
    Point Queue[10000];
    int front, rear, u, v;
    front = rear = 1;
    Queue[1] = start;
    s[start.x][start.y] = '#';
    while (front<=rear) {
        u = Queue[front].x; v = Queue[front++].y;
        
        if (s[u-1][v]==' ') {
            Queue[++rear].x = u-1; Queue[rear].y = v;
            s[u-1][v] = '#';
        }
        
        if (s[u+1][v]==' ') {
            Queue[++rear].x = u+1; Queue[rear].y = v;
            s[u+1][v] = '#';
        }
        
        if (s[u][v-1]==' ') {
            Queue[++rear].x = u; Queue[rear].y = v-1;
            s[u][v-1]= '#';
        }
        
        if (s[u][v+1]==' ') {
            Queue[++rear].x = u; Queue[rear].y = v+1;
            s[u][v+1]= '#';
        }
    }
}

main() {
//    freopen("784.inp","r",stdin);
//    freopen("784.out","w",stdout);
    int kase, i, j, n;
    cin >> kase; getchar();
    while (kase--) {
        n = -1;
        while (gets(s[++n])) {
            if (s[n][0]=='_') break;
        }
        bool f = false;
        for (i=0;i<=n && !f;i++)
            for (j=0;j<strlen(s[i]) && !f;j++)
                if (s[i][j]=='*') {
                    f = true;
                    start.x = i; start.y = j;
                }
        BFS();
        for (i=0;i<=n;i++)
            puts(s[i]);
    }
}
