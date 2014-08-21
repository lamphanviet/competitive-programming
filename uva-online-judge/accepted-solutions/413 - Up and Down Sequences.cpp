//----------------------------
// LAM PHAN VIET
// UVA 413 - Up and Down Sequences
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

main() {
    int len, a, b, n;
    int sumup, sumdown, nup, ndown;
    bool goup, godown;
    while (scanf("%d", &a) && a) {
        goup = godown = false;
        nup = ndown = 0;
        sumup = sumdown = 0;
        len = 0; n = 1;
        while (scanf("%d", &b) && b) {
            if (a==b) len++;
            else if (a<b) {
                if (godown){
                    sumdown += len; ndown++;
                    len=1;
                    godown = false; goup = true;
                }
                else {
                    len++;
                    goup = true;
                }
            }
            else {
                if (goup) {
                    sumup += len; nup++;
                    len = 1;
                    godown = true; goup = false;
                }
                else {
                    len++;
                    godown = true;
                }
            }
            n++; a = b;
        }
        if (goup) {
            sumup += len; nup++;
        }
        else if (godown) {
            sumdown += len; ndown++;
        }
        printf("Nr values = %d:  %.6lf %.6lf\n", n, (nup!=0)?((double)sumup/nup):0.0, (ndown!=0)?((double)sumdown/ndown):0.0);
    }
}
