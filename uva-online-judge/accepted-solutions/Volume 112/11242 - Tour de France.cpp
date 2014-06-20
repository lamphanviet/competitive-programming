// 11242 - Tour de France
#include <iostream>

using namespace std;

main() {
    int n, m, k, i, j, a[15], b[15];
    double ans, c[105];
    while (cin >> n && n) {
        cin >> m;
        for (i=0; i<n; i++) scanf("%d", &a[i]);
        for (i=0, k=0; i<m; i++) {
            scanf("%d", &b[i]);
            for (j=0; j<n; j++)
                c[k++] = (double)b[i]/a[j];
        }
        sort(c, c+k);
        for (i=1, ans=-1; i<k; i++)
            ans = max(ans, c[i]/c[i-1]);
        printf("%.2lf\n", ans);
    }
}
