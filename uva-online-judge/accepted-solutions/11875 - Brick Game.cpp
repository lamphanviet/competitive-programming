// 	11875 - Brick Game
#include <iostream>

using namespace std;

main() {
    int kase, n, i, a[20];
    cin >> kase;
    for (int k = 1; k <=kase; k++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort (a, a+n);
        printf("Case %d: %d\n",k,a[n/2]);
    }
}
