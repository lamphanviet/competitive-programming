//----------------------------
// LAM PHAN VIET
// UVA 10220 - I Love Big Numbers !
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
    int Sum_Digit() {
        int sum = 0;
        for (int i=0; i<len; i++)
            sum += d[i];
        return sum;
    }
};

main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        BigNum a;
        for (int i=2; i<=n; i++)
            a.Multi(i);
        printf("%d\n", a.Sum_Digit());
    }
}
