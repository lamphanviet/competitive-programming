// 10192 - Vacation
#include <iostream>

using namespace std;

main() {
    char a[105], b[105];
    int na, nb, x[105], i, k, max1, tempmax, kase=0;
    while (gets(a)) {
        if (a[0]=='#') break;
        gets(b);
        na = strlen(a); nb = strlen(b);
        for (i=0;i<=nb;i++)
            x[i] = 0;
        max1 = 0;
        for (k=0;k<na;k++) {
            tempmax = 0;
            for (i=0;i<nb;i++) {
                if (a[k]==b[i]) {
                    if (x[i]<=tempmax) x[i]=tempmax+1;
                    else tempmax = x[i];
                    if (x[i]>max1) max1 = x[i];
                }
                else if (x[i]>tempmax) tempmax = x[i];
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",++kase, max1);
    }
}
