// 10931 - Parity
#include <iostream>

using namespace std;

const char bit[] = "01";

main() {
    int x, n, ans[50], dem, i;
    while (scanf("%d", &x) && x) {
        n = dem = 0;
        while (x!=0) {
            ans[n++] = bit[x%2];
            x /= 2;
            if (ans[n-1]=='1') dem++;
        }
        printf("The parity of ");
        for (i=n-1; i>=0; i--)
            printf("%c", ans[i]);
        printf(" is %d (mod 2).\n", dem);
    }
}
