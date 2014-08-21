#include <stdio.h>
#include <iostream>

bool a[55];
long long lt2[55];
int n,n1,n0;
long long rs;

void Luythua() {
    lt2[0]=1;
    for (int i=1;i<=50;i++)
        lt2[i]=2*lt2[i-1];
}

void Find1() {
    int i,k=2;
    a[0]=1; n1--;
    a[1]=0; n0--;
    
    while (k<n) {
        if (n1==0) {
            for (i=k;i<n;i++) a[i]=0;
            break;
        }
        if (a[k-1] && a[k-2]) {
            a[k++]=0; n0--;
        }
        else {
            a[k++]=1; n1--;
        }
    }
    for (i=n-1;i>=0;i--) {
        if (a[i]) rs+=lt2[i];
 //       printf("%d",a[i]);
    }
 //   printf("\n");
}

void Find2() {
    int i,k=1; a[0]=1; n1--;
    if (n0>0) {
        a[1]=0; n0--; k++;
    }
    
    while (k<n) {
        if (n0==0) {
            for (i=k;i<n;i++) a[i]=1;
            break;
        }
        if (a[k-1] && a[k-2]) {
            a[k++]=0; n0--;
        }
        else {
            a[k++]=1; n1--;
        }
    }
    
    for (i=0;i<n;i++) {
        if (a[i]) rs+=lt2[n-i-1];
 //       printf("%d",a[i]);
    }
//    printf("\n");
}

main() {
    Luythua();
    int time;
    scanf("%d",&time);
    while (time--) {
        scanf("%d %d",&n1,&n0); n=n1+n0;
        if (n1==0) rs=0;
        else if (n1==1) rs=1;
        else {
            memset(a,n+3,false); rs=0;
            if (n0*2>=n1) Find1();
            else Find2();
        }
        printf("%lld\n",rs);
    }
}
