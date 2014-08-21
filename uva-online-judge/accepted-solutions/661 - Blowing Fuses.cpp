// 661 - Blowing Fuses
#include <iostream>

using namespace std;

main() {
    long n,m,c,max, sum, a[22];
    int i,k,kase = 0;
    bool safe, On[22];
    while (cin >> n >> m >> c) {
        if (n==0 && m==0 && c==0) break;
        for (i=1;i<=n;i++) {
            cin >> a[i];
            On[i] = false;
        }
        safe = true; max = sum = 0;
        for (i=1;i<=m;i++) {
            cin >> k;
            if (On[k]) sum -= a[k];
            else {
                sum += a[k];
                if (max<sum) max = sum;
                if (sum>c) safe = false;
            }
            On[k] = !On[k];
        }
        printf("Sequence %d\n",++kase);
        if (safe) printf("Fuse was not blown.\nMaximal power consumption was %ld amperes.",max);
        else printf("Fuse was blown.");
        cout << endl << endl;
    }
}
