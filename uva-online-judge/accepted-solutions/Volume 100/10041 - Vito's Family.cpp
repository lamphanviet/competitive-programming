// 10041 - Vito's Family
#include <iostream>
#define INF 10000000

using namespace std;

main() {
    int kase, i, j, n, a[505], sum, ans;
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n); ans = INF;
        for (i=0; i<n; i++) {
            sum = 0;
            for (j=i+1; j<n; j++)
                sum += a[j]-a[i];
            for (j=0; j<i; j++)
                sum += a[i]-a[j];
            if (sum<ans) ans = sum;
        }
        cout << ans << endl;
    }
}
