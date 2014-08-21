#include <stdio.h>
#include <math.h>

long long a,b,c;

int Check() {
    if (a<=0 || b<=0 || c<=0) return 1;
    if (a+b<=c || a+c<=b || b+c<=a) return 1;
    if (a==b && b==c) return 2;
    if (a==b || a==c || b==c) return 3;
    return 4;
}

main() {
    int time;
    scanf("%d",&time);
    for (int t=1;t<=time;t++) {
        scanf("%lld %lld %lld",&a,&b,&c);
        int k=Check();
        printf("Case %d: ",t);
        if (k==1) printf("Invalid");
        else if (k==2) printf("Equilateral");
        else if (k==3) printf("Isosceles");
        else printf("Scalene");
        printf("\n");
    }
}
