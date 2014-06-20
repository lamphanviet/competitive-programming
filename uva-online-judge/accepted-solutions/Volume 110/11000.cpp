#include <stdio.h>

long rsduc,rstt;
int n;

struct Year {
    
} a[100];

void Count() {
    long nduc,ncai,i,temp;
    ncai=1; nduc=0;
    for (i=1;i<=n;i++) {
        temp=nduc;
        nduc=ncai+nduc;
        ncai=temp+1;
    }
    rsduc=nduc;
    rstt=nduc+ncai;
}

main() {
    scanf("%d",&n);
    while (n!=-1) {
        Count();
        printf("%ld %ld\n",rsduc,rstt);
        scanf("%d",&n);
    }
}
