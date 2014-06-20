// 10684 - The jackpot
#include <iostream>

using namespace std;

main() {
    int n, i, maxsum, sum[10000+5], a[10000+5];
    while (cin >> n && n) {
        for (i=1; i<=n; i++)
            cin >> a[i];
        maxsum = sum[0] = -1;
        for (i=1; i<=n; i++) {
            if (sum[i-1]<0) sum[i] = a[i];
            else sum[i] = sum[i-1]+a[i];
            
            if (sum[i]>maxsum) maxsum = sum[i];
        }
        if (maxsum<=0) printf("Losing streak.");
        else printf("The maximum winning streak is %d.", maxsum);
        cout << endl;
    }
}
