#include <iostream>
#include <string.h>

using namespace std;

#define Key "IEHOVA#"

int m,n;
char a[10][10], way[3][6];

void Pre() {
    strcpy(way[0],"forth");
    strcpy(way[1],"right");
    strcpy(way[2],"left");
}

void Process() {
    int x,y,u;
    y=0; x=m;
    while (a[m][y]!='@') y++;
    u=0;
    while (u<=6) {
        if (u!=0) cout << " ";
        if (y>0 && a[x][y-1]==Key[u]) {
            cout << way[2];
            y--;
        }
        else if (y<n-1 && a[x][y+1]==Key[u]) {
            cout << way[1];
            y++;
        }
        else {
            cout << way[0];
            x--;
        }
        u++;
    }
}

main() {
//    freopen("452.inp","r",stdin);
//    freopen("452.out","w",stdout);
    int kase,i;
    Pre();
    cin >> kase;
    while (kase--) {
        cin >> m >> n;
        getchar();
        for (i=1;i<=m;i++) gets(a[i]);
        Process();
        cout << endl;
    }
}
