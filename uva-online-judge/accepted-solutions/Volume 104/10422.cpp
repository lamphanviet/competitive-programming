#include <iostream>
#include <string.h>

#define n 5

using namespace std;

int Step;
char final[7][7],a[7][7];

void Pre() {
    strcpy(final[1],"11111");
    strcpy(final[2],"01111");
    strcpy(final[3],"00 11");
    strcpy(final[4],"00001");
    strcpy(final[5],"00000");
}

bool Check() {
    for (int i=1;i<=n;i++)
        for (int j=0;j<n;j++)
            if (a[i][j]!=final[i][j]) return 0;
    return 1;
}

void Swap (int x1, int y1, int x2, int y2) {
    char temp = a[x1][y1];
    a[x1][y1] = a[x2][y2];
    a[x2][y2] = temp;
}

void Found(int st,  int x, int y, int u, int v, int k) {
    Swap(x,y,u,v);
//    char temp = a[x][y];
//    a[x][y] = a[u][v];
//    a[u][v] = temp;
//    for (int i=1;i<=n;i++)
//        puts(a[i]);
//    cout << endl;
    if (st<Step) {
        if (Check()) Step=st;
        else {
            if (u>=3 && v>=1 && k!=5) Found(st+1,u,v,u-2,v-1,1);
            if (u>=3 && v<=3 && k!=6) Found(st+1,u,v,u-2,v+1,2);
            if (u>=2 && v<=2 && k!=7) Found(st+1,u,v,u-1,v+2,3);
            if (u<=4 && v<=2 && k!=8) Found(st+1,u,v,u+1,v+2,4);
            if (u<=3 && v<=3 && k!=1) Found(st+1,u,v,u+2,v+1,5);
            if (u<=3 && v>=1 && k!=2) Found(st+1,u,v,u+2,v-1,6);
            if (u<=4 && v>=2 && k!=3) Found(st+1,u,v,u+1,v-2,7);
            if (u>=2 && v>=2 && k!=4) Found(st+1,u,v,u-1,v-2,8);
        }
    }
    Swap(x,y,u,v);
}

main() {
//    freopen("422.inp","r",stdin);
//    freopen("422.out","w",stdout);
    Pre();
    int kase, x, y, found;
    cin >> kase; getchar();
    while (kase--) {
        for (x=1;x<=n;x++)
            gets(a[x]);
        found = 0;
        for (x=1;x<=n;x++) {
            for (y=0;y<n;y++)
                if (a[x][y]==' ') {
                found=1; break;
            }
            if (found) break;
        }
        Step = 11;
        Found(0,x,y,x,y,0);
//        cout << endl;
//        cout << "Goc" << endl;
//        for (int i=1;i<=n;i++)
//            puts(a[i]);
//        cout << endl;
//        cout << Step << endl;
        if (Step>=11) cout << "Unsolvable in less than 11 move(s)." << endl;
        else cout << "Solvable in " << Step << " move(s)." << endl;
    }
}
