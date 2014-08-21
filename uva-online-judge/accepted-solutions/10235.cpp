#include <stdio.h>
#include <math.h>

int n;

bool isNgto(int n) {
    if (n<2) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    int k=(int)sqrt(n);
    for (int i=3;i<=k;i+=2)
        if (n%i==0) return 0;
    return 1;
}

int Check() {
    if (!isNgto(n)) return 1;
    int nn=n;
    int temp[10],i,j,k=0;
    while (n!=0) {
        temp[++k]=n%10;
        n/=10;
    }
    n=0;
    for (i=k,j=1;i>=1;i--,j*=10)
        n += temp[i]*j;
  //  printf("dao %d\n",n);
    if (nn!=n && isNgto(n)) return 2;
    else return 3;
}

main() {
    while (scanf("%d",&n)!=EOF) {
        printf("%d is ",n);
        int k=Check();
        if (k==1) printf("not prime.");
        else if (k==2) printf("emirp.");
        else printf("prime.");
        printf("\n");
    }
}
