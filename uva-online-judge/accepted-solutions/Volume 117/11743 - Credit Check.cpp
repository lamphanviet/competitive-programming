// 11743 - Credit Check
#include <iostream>

using namespace std;

int Tinh(int a) {
    a -= 48;
    a *= 2;
    int kq = 0;
    while (a) {
        kq += a%10;
        a /= 10;
    }
    return kq;
}

main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        char s[10];
        int sum = 0;
        for (int i=0; i<4; i++) {
            scanf("%s", &s);
            sum += s[1] + s[3] - 96;
            sum += Tinh((int)s[0]) + Tinh((int)s[2]);
        }
        if (sum%10==0) printf("Valid\n");
        else printf("Invalid\n");
    }
}
