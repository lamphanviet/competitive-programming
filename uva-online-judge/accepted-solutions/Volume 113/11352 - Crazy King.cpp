//*****************
// LAM PHAN VIET **
// UVA 11352 - Crazy King
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define INF 999999
#define maxN 102
class Point {
public:
    int x, y;
    Point() { x=y=0; }
    Point(int i, int j) { x=i; y=j; }
};
const int npos = 8, pos[][2] = { {-2, -1}, {-2, 1}, {-1, 2} , {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2} };
int n, m, a[maxN][maxN];
char s[maxN][maxN];
Point A, B;


bool isOK(int i, int j) {
    return (i>=0 && i<n && j>=0 && j<m);
}

void Fill(int i, int j) {
    for (int k=0; k<npos; k++) {
        int u = i+pos[k][0], v = j+pos[k][1];
        if (isOK(u, v) && s[u][v]=='.')
            s[u][v] = '*';
    }
}

bool isOK2(int i, int j) {
    if (!isOK(i, j)) return false;
    return (s[i][j]!='*' && s[i][j]!='Z' && a[i][j]==INF);
}

void BFS() {
    queue<Point> Queue;
    Queue.push(A); a[A.x][A.y] = 0;
    while (!Queue.empty()) {
        Point u = Queue.front(); Queue.pop();
        if (u.x==B.x && u.y==B.y) return;
        for (int i=u.x-1; i<=u.x+1; i++)
            for (int j=u.y-1; j<=u.y+1; j++)
                if (isOK2(i, j)) {
                    a[i][j] = a[u.x][u.y]+1;
                    Queue.push(Point(i, j));
                }
    }
}

void Print() {
    for (int i=0; i<n; i++)
        puts(s[i]);
    printf("\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

main() {
//    freopen("352.inp", "r", stdin); freopen("352.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m); gets(s[0]);
        for (int i=0; i<n; i++) {
            gets(s[i]);
            for (int j=0; j<m; j++)
                a[i][j] = INF;
        }
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (s[i][j]=='Z') Fill(i, j);
                else if (s[i][j]=='A') A = Point(i, j);
                else if (s[i][j]=='B') B = Point(i, j);
            }
        BFS();
        if (a[B.x][B.y]==INF) puts("King Peter, you can't go now!");
        else printf("Minimal possible length of a trip is %d\n", a[B.x][B.y]);
    }
}

/* lamphanviet@gmail.com - 2011 */
