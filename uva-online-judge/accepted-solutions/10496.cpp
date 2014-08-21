#include <iostream>
#include <math.h>

using namespace std;

int n,m,x[12],y[12],a[12][12];
bool Free[12];
int Min;

void Enter() {
    int i,j,temp;
    cin >> n >> i;
    cin >> x[1] >> y[1];
    cin >> n;
    n++;
    for (i=2;i<=n;i++)
        cin >> x[i] >> y[i];
    for (i=1;i<=n;i++) {
        for (j=i+1;j<=n;j++)
            a[i][j]=a[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
        a[i][i]=0;
    }
    memset(Free,true,n+2);
    Free[1]=false;
}

int Find(int u, int dis, int k) {
    if (dis>=Min) return 0;
    if (k==n) {
        dis += a[u][1];
        if (dis<Min) Min=dis;
        return 0;
    }
    Free[u]=false;
    for (int i=1;i<=n;i++)
        if (Free[i]) Find(i,dis+a[u][i],k+1);
    Free[u]=true;
    
}

main() {
    int kase;
    cin >> kase;
    while (kase--) {
        Enter();
        Min=1000000;
        Find(1,0,1);
        cout << "The shortest path has length " << Min << endl;
    }
}
