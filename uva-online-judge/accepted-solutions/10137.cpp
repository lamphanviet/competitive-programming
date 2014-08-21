#include <stdio.h>

int n,i;
double tong,avg,rs,a[1010];

main() {
    scanf("%d",&n);
    while (n!=0) {
        tong=0;
        for (i=1;i<=n;i++) {
            scanf("%f",&a[i]);
            tong+=a[i];
        }
        
        avg=tong/n;
        avg*=100;
        avg=(int)avg;
        avg/=100;
        
        rs=0.0;
        for (i=1;i<=n;i++)
            if (a[i]<avg) rs+=avg-a[i];
            
        rs*=100;
        rs=(int)rs;
        rs/=100;
        
        printf("%.2f\n",rs);
        
        scanf("%d",&n);
    }
}
