// 10803 - Thunder Mountain
#include <iostream>
#include <math.h>
#define N 105
#define INF 1000000

using namespace std;

int x[N], y[N], n;
double a[N][N];

double Distance(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

main() {
 //   freopen("803.inp", "r",stdin); freopen("803.out", "w",stdout);
    int kase, kk, i, j, k;
    cin >> kase;
    for (kk=1; kk<=kase; kk++) {
        cin >> n;
        for (i=1; i<=n; i++)
            cin >> x[i] >> y[i];
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++) {
                a[i][j] = Distance(i, j);
                if (a[i][j]>10) a[i][j] = INF;
                a[j][i] = a[i][j];
            }
        
        for (k=1; k<=n; k++)
            for (i=1; i<=n; i++)
                for (j=1; j<=n; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                    
        double ans = 0.0;
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++) {
                ans = max(ans, a[i][j]);
        }
        printf("Case #%d:\n", kk);
        if (ans==INF) puts("Send Kurdy");
        else printf("%.4lf\n", ans);
        cout << endl;
    }
}
