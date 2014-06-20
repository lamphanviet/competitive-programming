// 507 - Jill Rides Again
#include <iostream>

using namespace std;

main() {
//    freopen("507.inp", "r", stdin); freopen("507.out", "w", stdout);
    int kase, n, maxsum, i, k, u;
    int sum[20000+5], a[20000+5], len[20000+5];
    cin >> kase;
    sum[0] = 0;
    for (k=1; k<=kase; k++) {
        cin >> n;
        for (i=1; i<n; i++) cin >> a[i];
        
        maxsum = -1;
        sum[0] = -1;
        len[0] = u = 0;
        for (i=1; i<n; i++) {
            if (sum[i-1]<0) {
                sum[i] = a[i];
                len[i] = 1;
            }
            else {
                sum[i] = a[i]+sum[i-1];
                len[i] = len[i-1]+1;
            }
            if (sum[i]>maxsum || (sum[i]==maxsum && len[i]>len[u])) {
                maxsum = sum[i];
                u = i;
            }
        }
        
//        for (i=1; i<n; i++) printf(" %d", sum[i]); cout << endl;
        if (maxsum<0) printf("Route %d has no nice parts", k);
        else printf("The nicest part of route %d is between stops %d and %d", k, u-len[u]+1, u+1);
        cout << endl;
    }
}
