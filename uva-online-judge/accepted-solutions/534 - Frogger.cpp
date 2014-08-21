// 534 - Frogger
#include <iostream>
#include <math.h>

using namespace std;

#define N 200

int x[N+5], y[N+5], n;
double a[N+5][N+5];

double Distance(int i, int j) {
    int a = x[i]-x[j], b = y[i]-y[j];
    return sqrt(a*a + b*b);
}

void Print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            printf("%6.3lf", a[i][j]);
        cout << endl;
    }
}

main() {
    int i, j, k, kase=0;
    while (cin >> n && n) {
        for (i=0; i<n; i++)
            cin >> x[i] >> y[i];
        for (i=0; i<n; i++)
            for (j=i; j<n; j++)
                a[i][j] = a[j][i] = Distance(i,j);
//        Print();
        
        for (k=0; k<n; k++)
            for (i=0; i<n; i++)
                for (j=0; j<n; j++)
                    a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));
  /*      double ans;
        for (i=0, ans=1000000; i<n; i++)
            for (j=i; j<n; j++)
                if (i!=j && a[i][j] < ans) ans = a[i][j];   */
        printf("Scenario #%d\n", ++kase);
        printf("Frog Distance = %.3lf\n\n", a[0][1]);
    }
}
