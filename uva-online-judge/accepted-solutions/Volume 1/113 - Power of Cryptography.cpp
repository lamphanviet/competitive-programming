// UVA Problem 113 - Power of Cryptography
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=49
#include <iostream>
#include <math.h>

using namespace std;

main() {
    double n,p,k;
    while (cin >> n >> p) {
        k = exp(log(p)/n);
        printf("%.0lf\n",k);
    }
}
