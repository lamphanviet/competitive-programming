//----------------------------
// LAM PHAN VIET
// UVA 11714 - Blind Sorting
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef unsigned long long ULL;

main() {
    ULL n;
    while (scanf("%lld", &n)!=EOF) {
        printf("%lld\n", n-1 + (ULL)log2(n-1));
    }
}
