// 623 - 500!
#include <iostream>

using namespace std;

main() {
    int len, i, n, m, ans[20000], du;
    while (cin >> n) {
        len = 1;
        ans[1] = 1;
        printf("%d!\n", n);
        for (m=2; m<=n; m++) {
            for (du=0, i=1; i<=len; i++) {
                ans[i] = ans[i]*m+du;
                du = ans[i]/10;
                ans[i] %= 10;
            }
            while (du!=0) {
                ans[++len] = du%10;
                du /= 10;
            }
        }
        for (i=len; i>=1; i--)
            printf("%d", ans[i]);
        cout << endl;
    }
}
