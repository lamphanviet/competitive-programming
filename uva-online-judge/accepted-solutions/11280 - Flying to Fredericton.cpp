// 11280 - Flying to Fredericton
#include <iostream>
#include <map>
#include <string>
#define INF 10000000

using namespace std;

map <string, int> VT;
int n, a[105][105], d[105][105];


void Print() {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=0; j<=n; j++)
            printf("%5d", d[j][i]);
        cout << endl;
    }
}

void Print2() {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++)
            printf("%5d", a[j][i]);
        cout << endl;
    }
}

void BFord() {
    int i, j, k;
    for (i=1; i<=n; i++) d[0][i] = a[1][i];
    for (k=1; k<=n; k++) {
        for (i=1; i<=n; i++) {
            d[k][i] = d[k-1][i];
            for (j=1; j<=n; j++)
                d[k][i] = min(d[k][i], d[k-1][j]+a[j][i]);
        }
    }
}

main() {
 //   freopen("280.inp", "r", stdin); freopen("280.out", "w", stdout);
    int kase, kk, i, j, m, w;
    string s1, s2; char line[10];
    cin >> kase;
    for (kk=1; kk<=kase; kk++) {
        cin >> n; gets(line);
        for (i=1; i<=n; i++) {
            cin >> s1; VT[s1] = i;
            a[i][i] = 0;
            for (j=i+1; j<=n; j++)
                a[i][j] = a[j][i] = INF;
        }
        cin >> m; gets(line);
        while (m--) {
            cin >> s1 >> s2 >> w;
            i = VT[s1]; j = VT[s2];
            if (i<j) a[i][j] = min(a[i][j], w);
            else a[j][i] = min(a[j][i], w);
        }
 //       Print2();
        BFord();
 //       Print();
        cout << "Scenario #" << kk << endl;
        cin >> w;
        while (w--) {
            cin >> m; if (m>n) m=n;
            if (d[m][n]!=INF) cout << "Total cost of flight(s) is $" << d[m][n];
            else cout << "No satisfactory flights";
            cout << endl;
        }
        if (kk<kase) cout << endl;
        VT.clear();
    }
}
