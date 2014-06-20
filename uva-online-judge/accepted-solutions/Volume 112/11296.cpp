#include <stdio.h>
#include <math.h>

int n;

long Count() {
    long rs=0,x,nchan;
    if (n==0) return 1;
    if (n%2==0) x=0;
    else x=1;
    
    for (;x<=n;x+=2) {
        nchan=(n-x)/2+1;
        rs += nchan;
 //       if (nchan%2!=0) rs--;
    }
    
    return rs;
}

main() {
    while (scanf("%d",&n)!=EOF) {
        printf("%ld\n",Count());
    }
}
