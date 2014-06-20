//----------------------------
// LAM PHAN VIET
// UVA 11608 - No Problem
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 12

main() {
    int created[maxN], required[maxN], k, kase=0;
    while (scanf("%d", &k) && k>=0) {
        for (int i=0; i<maxN; i++)
            scanf("%d", &created[i]);
        for (int i=0; i<maxN; i++)
            scanf("%d", &required[i]);
        printf("Case %d:\n", ++kase);
        for (int i=0; i<maxN; i++) {
            if (k<required[i]) printf("No problem. :(");
            else {
                printf("No problem! :D");
                k -= required[i];
            }
            k += created[i];
            printf("\n");
        }
    }
}
