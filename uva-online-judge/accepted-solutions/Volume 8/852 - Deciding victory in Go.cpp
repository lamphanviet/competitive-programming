//----------------------------
// LAM PHAN VIET
// UVA 852 - Deciding victory in Go
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 9
int Count, white, black;
bool isb, isw;
char s[N+2][N+2];

void DFS(int x, int y) {
    if (x<0 || x>=N || y<0 || y>=N) return;
    if (s[x][y]=='.') {
        s[x][y] = '*'; Count++;
    }
    else {
        if (s[x][y]=='O') isw = true;
        else if (s[x][y]=='X') isb = true;
        return;
    }
    DFS(x-1, y); DFS(x+1, y);
    DFS(x, y-1); DFS(x, y+1);
}

main() {
//    freopen("852.inp", "r", stdin); freopen("852.out", "w", stdout);
    int Case;
    scanf("%d", &Case); gets(s[0]);
    while (Case--) {
        white = black = 0;
        for (int i=0; i<N; i++) {
            gets(s[i]);
            for (int j=0; j<N; j++)
                if (s[i][j]=='O') white++;
                else if (s[i][j]=='X') black++;
        }
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                if (s[i][j]=='.') {
                    isb = isw = false;
                    Count = 0;
                    DFS(i, j);
                    if (isb && isw) continue;
                    if (isb) black += Count;
                    else white += Count;
                }
        printf("Black %d White %d\n", black, white);
    }
}
