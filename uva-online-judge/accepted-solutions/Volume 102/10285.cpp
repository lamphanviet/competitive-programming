#include <iostream>

using namespace std;

int a[110][110],len[110][110];
int maxi,m,n;
char name[10];

int max(int a, int b) {
    if (a>b) return a;
    return b;
}

void Enter() {
    scanf("%s %d %d",&name,&m,&n);
    int i,j;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++) {
            cin >> a[i][j];
            len[i][j]=0;
        }
    
    for (i=0;i<=m+1;i++)
        len[0][i]=len[i][0]=len[m+1][i]=len[i][n+1]=110;
        
    maxi=0;
}

void Barrack(int len2, int x, int y) {
    int temp;
//    cout << a[x][y] << endl;
    if (len2>len[x][y]) {
        len[x][y]=len2;
        if (len[x][y]>maxi) maxi = len[x][y];
        temp = a[x][y];
        if (a[x+1][y]<temp)
            Barrack(len2+1,x+1,y);
        if (a[x-1][y]<temp)
            Barrack(len2+1,x-1,y);
        if (a[x][y+1]<temp)
            Barrack(len2+1,x,y+1);
        if (a[x][y-1]<temp)
            Barrack(len2+1,x,y-1); 
    }
}

main() {
 //   freopen("285.inp","r",stdin);
//    freopen("285.out","w",stdout);
    
    int kase,i,j;
    cin >> kase;
    while (kase--) {
        Enter();
        for (i=1;i<=m;i++)
            for (j=1;j<=n;j++)
                Barrack(1,i,j);
        cout << name << ": " << maxi << endl;
        
 //       for (i=0;i<=m+1;i++) {
 //           for (j=0;j<=n+1;j++)
 //               printf("%5d ",len[i][j]);
 //           cout << endl;
 //       }
    }
}
