//----------------------------
// LAM PHAN VIET
// UVA 11933 - Splitting Numbers
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 50000

main() {
    int n, a, b;
    while (scanf("%d", &n) && n!=0) {
        a = b = 0;
        int k=1, hs=1;
        while (n) {
            if (n%2==1) {
                if (k++%2) a += hs;
                else b += hs;
            }
            n /= 2;
            hs*= 2;
        }
        printf("%d %d\n", a, b);
    }
}
