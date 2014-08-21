#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n,nn,x[110],y[110];
int a,b;

int Side(int a, int b, int x, int y) {
    return (a*x)+(b*y);
}

main() {
    int i,am,duong;
    bool con;
    while (scanf("%d",&n)) {
        if (n==0) break;
        nn=2*n;
        for (i=1;i<=nn;i++)
            scanf("%d %d",&x[i],&y[i]);
        con=true;
        for (a=-500;a<=500;a++) {
            for (b=-500;b<=500;b++) {
                am=duong=0;
                for (i=1;i<=nn;i++) {
                    int k=Side(a,b,x[i],y[i]);
                    if (k<0) am++;
                    else if (k>0) duong++;
                }
                if (am==duong && am==n) {
                    con=false; break;
                }
            }
            if (!con) break;
        }
        printf("%d %d\n",a,b);
    }
}

/* Cach 2: su dung random
while (1) {
    a=-500+(rand()%1001);
    b=-500+(rand()%1001);
    am=duong=0;
    for (i=1;i<=nn;i++) {
        int k=Side(a,b,x[i],y[i]);
        if (k<0) am++;
        else if (k>0) duong++;
    }
        if (am==duong && am==n) break;
}

*/

