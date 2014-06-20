#include <stdio.h>
#include <math.h>

int n;
double x[55],y[55],vx[55],vy[55],T[55];

bool Check() {
    int i,j;
    for (i=0;i<n;i++) {
        j=(i+1)%n;
        vx[i]=x[j]-x[i];
        vy[i]=y[j]-y[i];
    }
    
    for (i=0;i<n;i++) {
        j=(i+1)%n;
        T[i]=vx[i]*vy[j]-vy[i]*vx[j];
    }
    
    if (T[0]<0) {
        for (i=1;i<n;i++)
            if (T[i]>0) return 1;
    }
    else {
        for (i=1;i<n;i++)
            if (T[i]<0) return 1;
    }
    return 0;
}

main() {
//    freopen("078.inp","r",stdin);
//    freopen("078.out","w",stdout);
    while (scanf("%d",&n)) {
        if (n==0) break;
        for (int i=0;i<n;i++)
            scanf("%lf %lf",&x[i],&y[i]);
        if (Check()) printf("Yes\n");
        else printf("No\n");
    }
}
