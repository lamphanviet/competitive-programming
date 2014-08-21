#include <stdio.h>
#include <math.h>

int n;
double y[1010],x[1010],px,py;

void Enter() {
    for (int i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    scanf("%lf %lf",&px,&py);
}

bool Check() {
    int i,count,check,xcut;
    double a,b,c;
    count=0;
    for (i=0;i<=n-1;i++) {
        if (y[i]==py) {
            if (x[i]>=px) {
                if (((y[(i+n-1)%n]<y[i])&&(y[i]<y[(i+n+1)%n])) || ((y[(i+n-1)%n]>y[i])&&(y[i]>y[(i+n+1)%n])))
                    count++;
                if (y[(i+n+1)%n]==py)
                    if (((y[(i+n-1)%n]<y[i])&&(y[i]<y[(i+n+2)%n])) || ((y[(i+n-1)%n]>y[i])&&(y[i]>y[(i+n+2)%n])))
                        count++;
            }
        }
        else if (((y[i]<py)&&(py<y[(i+n+1)%n])) || ((y[i]>py)&&(py>y[(i+n+1)%n]))) {
            a=x[(i+n+1)%n]-x[i];
            b=py-y[i];
            c=y[(i+n+1)%n]-y[i];
            xcut=x[i]+round(a*b/c);
            if (xcut>px) count++;
        }
    }
    check=count%2;
    return (check!=0);
}

main() {
    while (scanf("%d",&n)) {
        if (n==0) break;
        Enter();
        if (Check()) printf("T\n");
        else printf("F\n");
    }
}
