// 10066 - The Twin Towers
#include <iostream>

using namespace std;

#define N 105

main() {
    int na, nb, a[N], b[N];
    int x[N], i, k, tempmax, max1, kase = 0;
    while (cin >> na >> nb && (na || nb)) {
        for (i=0;i<na;i++) cin >> a[i];
        for (i=0;i<nb;i++) {
            cin >> b[i];
            x[i] = 0;
        }
        max1 = 0;
        
        for (k=0;k<na;k++) {
            tempmax = 0;
            for (i=0;i<nb;i++)
                if (a[k]==b[i]) {
                    if (x[i]<=tempmax) x[i] = tempmax+1;
                    else tempmax = x[i];
                    if (x[i]>max1) max1 = x[i];
                }
                else if (x[i]>tempmax) tempmax = x[i];
        }
        printf("Twin Towers #%d\n",++kase);
        printf("Number of Tiles : %d\n\n",max1);
        
    }
}
