//----------------------------
// LAM PHAN VIET
// UVA 10346 - Peter's Smokes
// Time limit: 3S
//----------------------------
#include <iostream>

using namespace std;

main() {
    int n, k;
//    while (cin >> n >> k) {
    while (scanf("%d %d", &n, &k)!=EOF) {
        int ans = n;
        while (n>=k) {
            ans += n/k;
            n = n/k + n%k;
        }
        printf("%d\n", ans);
    }
}
