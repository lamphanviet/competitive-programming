// 729 - The Hamming Distance Problem
#include <iostream>
#include <algorithm>

using namespace std;

main() {
    int kase, n, k, i;
    char a[18];
    cin >> kase;
    while (kase--) {
        cin >> n >> k;
        for (i=0;i<n-k;i++) a[i] = '0';
        for (i=n-k;i<n;i++) a[i] = '1';
        a[n] = '\0';
        do {
            puts(a);
        } while (next_permutation(a,a+n));
        if (kase) cout << endl;
    }
}
