// UVA Problem 439 - Knight Moves
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=380
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define n 8
#define Key "0abcdefgh"
#define INF 9999

int a[10][10];
int sx,sy,ex,ey;

void Init() {
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j] = INF;
}

void DFS(int u, int v, int move) {
    if (u<1 || u>n || v<1 || v>n) return;
    if (a[u][v]<=move) return;
    a[u][v] = move;
                 DFS(u-2,v-1,move+1);        DFS(u-2,v+1,move+1);
           DFS(u-1,v-2,move+1);                     DFS(u-1,v+2,move+1);
                           /* u - v */
           DFS(u+1,v-2,move+1);                     DFS(u+1,v+2,move+1);
                 DFS(u+2,v-1,move+1);        DFS(u+2,v+1,move+1);
}

main() {
    char s[10];
    while (gets(s)) {
        Init();
        sx = s[0]-96; sy = s[1]-48;
        ex = s[3]-96; ey = s[4]-48;
        DFS(sx,sy,0);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",sx+96,sy,ex+96,ey,a[ex][ey]);
    }
}
