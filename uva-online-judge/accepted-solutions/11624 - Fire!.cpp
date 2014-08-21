//----------------------------
// LAM PHAN VIET
// UVA 11624 - Fire!
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define maxN 1005
#define INF 9999
class Point {
public:
    int r, c;
    Point() { r = c = 0; }
    Point(int x, int y) {
        r = x; c = y;
    }
    void Get(int x, int y) {
        r = x; c = y;
    }
};
int n, m, level[maxN][maxN];
char str[maxN][maxN];

bool isOKF(int r, int c, int lvl) {
    return (r>=0 && r<n && c>=0 && r<m && str[r][c]!='#' && lvl<level[r][c]);
}

bool isOKJ(int r, int c) {
    return (r>=0 && r<n && c>=0 && r<m && str[r][c]!='#');
}

bool isF(int r, int c, int lvl) {
    return (-level[r][c] < lvl-1);
}

void BFS_Fire(Point start) {
    queue<Point> Queue;
    Queue.push(start);
    while (!Queue.empty()) {
        Point p = Queue.front();
        Queue.pop();
        int lvl = level[p.r][p.c]+1;
        if (isOKF(p.r-1, p.c, lvl)) {
            Queue.push(Point(p.r-1, p.c));
            level[p.r-1][p.c] = lvl;
        }
        if (isOKF(p.r+1, p.c, lvl)) {
            Queue.push(Point(p.r+1, p.c));
            level[p.r+1][p.c] = lvl;
        }
        if (isOKF(p.r, p.c-1, lvl)) {
            Queue.push(Point(p.r, p.c-1));
            level[p.r][p.c-1] = lvl;
        }
        if (isOKF(p.r, p.c+1, lvl)) {
            Queue.push(Point(p.r, p.c+1));
            level[p.r][p.c+1] = lvl;
        }
    }
}

int BFS_John(Point start) {
    queue<Point> Queue;
    Queue.push(start);
    while (!Queue.empty()) {
        Point p = Queue.front();
        Queue.pop();
        
        if (p.r==0 || p.r==n-1 || p.c==0 || p.c==m-1)
            return -(level[p.r][p.c]-1);
        
        int lvl = level[p.r][p.c];
        if (isOKJ(p.r-1, p.c) && isF(p.r-1, p.c, lvl)) {
            Queue.push(Point(p.r-1, p.c));
            level[p.r-1][p.c] = lvl-1;
        }
        if (isOKJ(p.r+1, p.c) && isF(p.r+1, p.c, lvl)) {
            Queue.push(Point(p.r+1, p.c));
            level[p.r+1][p.c] = lvl-1;
        }
        if (isOKJ(p.r, p.c-1) && isF(p.r, p.c-1, lvl)) {
            Queue.push(Point(p.r, p.c-1));
            level[p.r][p.c-1] = lvl-1;
        }
        if (isOKJ(p.r, p.c+1) && isF(p.r, p.c+1, lvl)) {
            Queue.push(Point(p.r, p.c+1));
            level[p.r][p.c+1] = lvl-1;
        }
    }
    return -1;
}

void Print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            printf("%6d", level[i][j]);
        cout << endl;
    }
}


int Solve() {
    Point startJ, startF;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            if (str[i][j] == 'J')
                startJ.Get(i, j);
            else if (str[i][j] == 'F') {
                startF.Get(i, j);
                level[startF.r][startF.c] = 0;
                BFS_Fire(startF);
            }
    }
    level[startJ.r][startJ.c] = 0;
    return BFS_John(startJ);
}

main() {
//    freopen("624.inp", "r", stdin); freopen("624.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    while (Cases--) {
        scanf("%d %d", &n, &m); scanf(" ");
        for (int i=0; i<n; i++) {
            gets(str[i]);
            for (int j=0; j<m; j++)
                level[i][j] = INF;
        }
        
        int result = Solve();
 //       Print();
        if (result>0) printf("%d\n", result);
        else printf("IMPOSSIBLE\n");
    }
}
