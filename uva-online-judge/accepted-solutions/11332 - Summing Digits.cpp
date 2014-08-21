//----------------------------
// LAM PHAN VIET
// UVA 11332 - Summing Digits
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

main() {
    int n;
    while (scanf("%d", &n) && n) {
        while (n/10) {
            int tmp = 0;
            while (n) {
                tmp += n%10;
                n/=10;
            }
            n = tmp;
        }
        printf("%d\n", n);
    }
}
