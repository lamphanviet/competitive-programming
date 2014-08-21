// 10370 - Above Average
#include <iostream>

using namespace std;

main() {
    int kase, i, sum, n, a[1005], dem;
    double aver;
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=sum=0; i<n; i++) {
            cin >> a[i]; sum += a[i];
        }
        aver = sum/(double)n;
        for (i=dem=0; i<n; i++)
            if (a[i]>aver) dem++;
        printf("%.3lf", (double)dem*100.0/n);
        printf("%%");
        cout << endl;
    }
}
