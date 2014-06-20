/*************************/
/* Author: LAM PHAN VIET */
/* lamphanviet@gmail.com */
/*************************/
/* UVA 11703 - sqrt log sin
// Time limit: 3.000
/********************************/
#include <stdio.h>
#include <math.h>

#define maxN 1000001
#define MOD 1000000

int res[maxN];

int main() {
    int i;
    res[0] = 1;
    for (i = 1; i <= MOD; i++) {
        res[i] = res[(int)(i-sqrt(i))] + res[(int)log(i)] + res[(int)(i*sin(i)*sin(i))];
        res[i] = res[i] % MOD;
    }
    while (scanf("%d", &i) && i!=-1) {
        printf("%d\n", res[i]);
    }
    return 0;
}
