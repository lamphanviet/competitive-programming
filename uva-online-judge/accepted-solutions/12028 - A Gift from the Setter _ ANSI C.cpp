/******************
// LAM PHAN VIET **
// UVA 12028 - A Gift from the Setter - ANSI C - 0.232s
// Time limit: 2.000s
//*********************************/
#include <stdio.h>
#include <math.h>
#include <string.h>

#define uint64 unsigned long long
#define MOD 1000007

int c, n, num[MOD];
uint64 k;

int main() {
    memset(num, 0, MOD);
    int Case, kk, i, Max = 0, val;
    scanf("%d", &Case);
    for (kk = 1; kk <= Case; kk++) {
        scanf("%lld %d %d %d", &k, &c, &n, &val);
        Max = val;
        
        num[val]++;
        for (i = 1; i < n; i++) {
            val = (k * val + c) % MOD;
            if (val > Max) Max = val;
            num[val]++;
        }

        int last = 0;
        while (last<=Max && !num[last]) last++;
        k = num[last];
        num[last] = 0;
        
        uint64 res = 0, diff = 0;
        for (i = last + 1; i<=Max; i++)
            if (num[i]) {
                diff += k * (i - last);
                res += diff * num[i];
                
                last = i;
                k += num[i];
                num[i] = 0;
            }
        printf("Case %d: %lld\n", kk, res);
    }
    return 0;
}

/* lamphanviet@gmail.com - 2011 */
