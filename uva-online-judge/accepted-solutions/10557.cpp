#include <iostream>

using namespace std;

#define MIN -1000000

int ener[110],numc[110],n;
int connect[110][110];

void Enter() {
    int i,j;
    for (i=1;i<=n;i++) {
        cin >> ener[i] >> numc[i];
        for (j=1;j<=numc[i];j++)
            cin >> connect[i][j];
    }
}

bool Bellman_Ford() {
    int u,v,j,temp;
    int d[110];
    for (u=2;u<=n;u++)  d[u]=MIN;
    d[1]=100;
    
    int t=20000;
    while (t--) {
        for (u=1;u<=n;u++) {
            if (d[u]<0) continue;
            for (j=1;j<=numc[u];j++) {
                v = connect[u][j];
                temp = d[u]+ener[v];
                if (d[v]<temp) d[v]=temp;
                if (d[n]>0) return 1;
            }
        }
    }
    if (d[n]>0) return 1;
    return 0;
}

main() {
//    freopen("557.inp","r",stdin);
//    freopen("557.out","w",stdout);
    while (cin >> n) {
        if (n==-1) break;
        Enter();
        bool hope=Bellman_Ford();
        if (hope) cout << "winnable";
        else cout << "hopeless";
        cout << endl;
        
    }
}
