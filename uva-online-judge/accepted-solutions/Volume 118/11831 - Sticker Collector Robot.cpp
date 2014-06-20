// UVA Problem 11831 - Sticker Collector Robot
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2931
#include <iostream>

using namespace std;

int n,m,len;
char a[110][110],ins[50100];
int u,v,orien;

int Process() {
    int x,y,k;
    int count=0;
    for (k=0;k<len;k++) {
        if (ins[k]=='D') {
            orien = (orien+1)%4;
        }
        else if (ins[k]=='E') {
            orien = orien-1;
            if (orien<0) orien = 3;
        }
        else {
            x=u; y=v;
            if (orien==0) x--;
            else if (orien==1) y++;
            else if (orien==2) x++;
            else y--;
            
            if (y<0 || y>=m || x<1 || x>n || a[x][y]=='#') continue;
            else {
                a[u][v]='.';
                if (a[x][y]=='*') count++;
                u=x; v=y;
            }
        }
    }
    return count;
}

main() {
 //   freopen("b.inp","r",stdin);
//    freopen("b.out","w",stdout);
    
    while (cin >> n >> m >> len) {
        if (n==0 && m==0 && len==0) break;
        scanf(" ");
        for (int i=1;i<=n;i++)
            gets(a[i]);
        gets(ins);
        
        int f = 1;
        for (u=1;u<=n;u++) {
            for (v=0;v<m;v++)
                if (a[u][v]!='.' && a[u][v]!='*' && a[u][v]!='#') {
                    f = 0;
                    break;
                }
            if (!f) break;
        }
        if (a[u][v]=='N') orien=0;
        else if (a[u][v]=='L') orien=1;
        else if (a[u][v]=='S') orien=2;
        else if (a[u][v]=='O') orien=3;
        
        cout << Process() << endl;
    }
}
