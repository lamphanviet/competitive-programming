// 10591 - Happy Number
#include <iostream>

using namespace std;

int Check_isH(int n) {
    int nn=n, sum, d, first;
    bool Free[740];
    memset(Free, true, 740);
    do {
        sum = 0;
        while (nn!=0) {
            d = nn%10;
            sum += d*d;
            nn /= 10;
        }
        nn = sum;
        if (Free[nn]) Free[nn] = false;
        else break;
    } while (nn!=1);
    return (nn==1);
}

main() {
    int kase, kk, n;
    scanf("%d", &kase);
    for (kk=1; kk<=kase; kk++) {
        scanf("%d", &n);
        printf("Case #%d: ", kk);
        if (Check_isH(n)) printf("%d is a Happy number.\n", n);
        else printf("%d is an Unhappy number.\n", n);
    }
}
