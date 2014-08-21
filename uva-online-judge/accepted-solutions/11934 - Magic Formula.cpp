//----------------------------
// LAM PHAN VIET
// UVA 11934 - Magic Formula
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

main() {
    int a, b, c, d, L;
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &L)) {
        if (!a && !b && !c && !d && !L) break;
        int kount = 0;
        for (int i=0; i<=L; i++) {
            int tmp = a*i*i + b*i + c;
            if (tmp%d == 0) kount++;
        }
        printf("%d\n", kount);
    }
}
