//----------------------------
// LAM PHAN VIET
// UVA 324 - Factorial Frequencies
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 1001
#define maxLen 10000
class BigNum {
public:
    int d[maxLen];
    int len;
    BigNum() { len=1; d[0] = 1; }
    void Rut() {
        int du = 0;
        for (int i=0; i<len; i++) {
            d[i] += du;
            du = d[i]/10;
            d[i] %= 10;
        }
        while (du) {
            d[len++] = du%10;
            du /= 10;
        }
    }
    void Multi(int n) {
        for (int i=0; i<len; i++)
            d[i] *= n;
        Rut();
    }
};

main() {
    int n, num[10];
    while (scanf("%d", &n) && n) {
        BigNum a;
        for (int i=2; i<=n; i++)
            a.Multi(i);
        printf("%d! --\n", n);
        for (int i=0; i<10; i++) num[i] = 0;
        for (int i=0; i<a.len; i++)
            num[a.d[i]]++;
        for (int i=0; i<5; i++)
            printf("   (%d)%5d", i, num[i]);
        printf("\n");
        for (int i=5; i<10; i++)
            printf("   (%d)%5d", i, num[i]);
        printf("\n");
    }
}
