// UVA Problem 369 - Combinations
#include <iostream>

using namespace std;

long C[110][110];

void PreCal() {
    int n,k;
//    for (n=0;n<=100;n++)
//        for (k=0;k<=100;k++)
//            C[n][k] = 1;
    for (n=0;n<=100;n++)
        C[n][0] = C[n][n] = 1;
    
    for (n=2;n<=100;n++)
        for (k=1;k<=n/2;k++)
            C[n][k] = C[n][n-k] = C[n-1][k] + C[n-1][k-1];
}

main() {
    PreCal();
//    Print();
    int n,k;
    while (cin >> n >> k) {
        if (n==0 && k==0) break;
        printf("%d things taken %d at a time is %ld exactly.\n",n,k,C[n][k]);
    }
}
