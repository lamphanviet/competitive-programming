//----------------------------
// LAM PHAN VIET
// UVA 386 - Perfect Cubes
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 200

main() {
    int aa, bb, cc, dd;
    for (int a=6; a<=N; a++) {
        aa = a*a*a;
        for (int b=2; b<=N; b++) {
            bb = b*b*b;
            for (int c=b+1; c<=N; c++) {
                cc = c*c*c;
                for (int d=c+1; d<N; d++) {
                    dd = d*d*d;
                    if (aa==bb+cc+dd)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
}
