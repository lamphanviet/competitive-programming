//----------------------------
// LAM PHAN VIET
// UVA 532 - Dungeon Master
// Time limit: 3s
//----------------------------
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAXN 33
#define INF -1

struct Point {
    int x, y, z;
};

int X, Y, Z;
char a[MAXN][MAXN][MAXN];
Point Start, End;
bool Free[MAXN][MAXN][MAXN];
int d[MAXN][MAXN][MAXN];

int Check(int x, int y, int z) {
    if (x<0 || x>X-1 || y<0 || y>Y-1 || z<0 || z>Z-1 || !Free[x][y][z] ||a[x][y][z]=='#' ) return 0;
    return 1;
}

void BFS() {
    int i,j,k, x, y, z;
    Point Queue[100000], p;
    int front, rear;
    front = rear = 1;
    Queue[1] = Start;
    d[Start.x][Start.y][Start.z] = 0;
    Free[Start.x][Start.y][Start.z] = false;
    while (front<=rear) {
        p = Queue[front++];
        x = p.x; y = p.y; z = p.z;
//        printf("front %d:  %d %d %d\n",front-1,x,y,z);
        if (Check(x-1,y,z)) {
            Queue[++rear].x = x-1; Queue[rear].y = y; Queue[rear].z = z;
            d[x-1][y][z] = d[x][y][z] + 1; Free[x-1][y][z] = false;
        }
        if (Check(x+1,y,z)) {
            Queue[++rear].x = x+1; Queue[rear].y = y; Queue[rear].z = z;
            d[x+1][y][z] = d[x][y][z] + 1; Free[x+1][y][z] = false;
        }
        if (Check(x,y-1,z)) {
            Queue[++rear].x = x; Queue[rear].y = y-1; Queue[rear].z = z;
            d[x][y-1][z] = d[x][y][z] + 1; Free[x][y-1][z] = false;
        }
        if (Check(x,y+1,z)) {
            Queue[++rear].x = x; Queue[rear].y = y+1; Queue[rear].z = z;
            d[x][y+1][z] = d[x][y][z] + 1; Free[x][y+1][z] = false;
        }
        if (Check(x,y,z-1)) {
            Queue[++rear].x = x; Queue[rear].y = y; Queue[rear].z = z-1;
            d[x][y][z-1] = d[x][y][z] + 1; Free[x][y][z-1] = false;
        }
        if (Check(x,y,z+1)) {
            Queue[++rear].x = x; Queue[rear].y = y; Queue[rear].z = z+1;
            d[x][y][z+1] = d[x][y][z] + 1; Free[x][y][z+1] = false;
        }
    }
}

void Print() {
    for (int i=0;i<X;i++) {
        cout << endl;
        for (int j=0;j<Y;j++) {
            for (int k=0;k<Z;k++)
                printf("%3d",d[i][j][k]);
            cout << endl;
        }
    }
}

main() {
//    freopen("532.inp","r",stdin);
//    freopen("532.out","w",stdout);
    int i,j,k;
    while (cin >> X >> Y >> Z) {
        if (X==0 && Y==0 && Z==0) break;
        getchar();
        for (i=0;i<X;i++) {
            for (j=0;j<Y;j++) {
                gets(a[i][j]);
                for (k=0;k<Z;k++) {
                    Free[i][j][k] = true;
                    d[i][j][k] = INF;
                }
            }
            getchar();
        }
        int dem = 2;
        for (i=0;i<X && dem;i++)
            for (j=0;j<Y && dem;j++)
                for (k=0;k<Z && dem;k++)
                    if (a[i][j][k]=='S') {
                        Start.x = i; Start.y = j; Start.z = k; dem--;
                    }
                    else if (a[i][j][k]=='E') {
                        End.x = i; End.y = j; End.z = k; dem--;
                    }
//        printf("Start %d %d %d\n",Start.x,Start.y,Start.z);
//        printf("End %d %d %d\n",End.x,End.y,End.z);
        BFS();
        if (d[End.x][End.y][End.z] > 0) cout << "Escaped in " << d[End.x][End.y][End.z] << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
//        Print();
    }
}
