// UVA Problem 10019 - Funny Encryption Method
// Accepted
#include <iostream>

using namespace std;

main() {
    int kase,i,j;
    int p,q,n,nn;
    cin >> kase;
    while (kase--) {
        cin >> n;
        p = q = 0;
        nn = n;
        while (nn!=0) {
            if (nn%2) p++;
            nn/=2;
        }
        
        nn = n; n = 0;
        int k=1;
        while (nn!=0) {
            int a = nn%10; nn/=10;
            n += a*k;
            k*=16;
        }
        nn = n; q = 0;
        while (nn!=0) {
            if (nn%2) q++;
            nn/=2;
        }
        cout << p << " " << q << endl;
    }
}
