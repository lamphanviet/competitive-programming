#include <iostream>

using namespace std;

int n, Left[505][505],Right[505][505],Up[505][505],Down[505][505];
char a[505][505];
int Count;

int min(int a, int b) {
    if (a<b) return a;
    return b;
}

int min(int a, int b, int c, int d) {
    return min(min(a,b),min(c,d));
}

void Count_Drt() {
    int i,j;
    for (i=0;i<=n;i++) {
        Left[i][0]=Right[i][n+1]=Up[0][i]=Down[n+1][i]=0;
    }
    for (i=1;i<=n;i++)
        for (j=0;j<n;j++) {
            Left[i][j+1]=Right[i][n-j]=Up[i][j+1]=Down[n-i+1][j+1]=0;
            if (a[i][j]=='x') Left[i][j+1]=Left[i][j]+1;
            if (a[i][n-j-1]=='x') Right[i][n-j]=Right[i][n-j+1]+1;
            if (a[i][j]=='x') Up[i][j+1]=Up[i-1][j+1]+1;
            if (a[n-i+1][j]=='x') Down[n-i+1][j+1]=Down[n-i+2][j+1]+1;
        }
}

void Count_Squares() {
    int i,j,k,size;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            size = min(Down[i][j],Right[i][j]);
  //          printf("Size %d %d %d\n",i,j,size);
            if (size<2) continue;
            for (k=1;k<size;k++) {
                if (Up[i+k][j+k]<k+1 || Left[i+k][j+k]<k+1) break;
            }
            Count += k-1;
        }
}

void Count_Diamond() {
    int i,j,k,size,u,temp;
    bool con;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            size = min(Up[i][j],Down[i][j],Left[i][j],Right[i][j]);
            if (size<2) continue;
//            printf("size %d %d %d\n",i,j,size);
            for (k=size-1;k>=1;k--) {
                con=true;
                for (u=1;u<=k;u++) {
                    temp = min(Up[i][j+u],Down[i][j+u],Up[i][j-u],Down[i][j-u]);
//                    cout << "temp " << temp << endl;
                    if (temp<k-u+1) {
                        con=false;
                        break;
                    }
                }
                if (con) break;
            }
            Count += k;
        }
}

main() {
//    freopen("593.inp","r",stdin);
//    freopen("593.out","w",stdout);
    while (cin >> n) {
        getchar();
        for (int i=1;i<=n;i++) gets(a[i]);
        Count_Drt();
        Count=0;
        Count_Squares();
        Count_Diamond();
        cout << Count << endl;
    }
}
