#include <stdio.h>

long long a[70][70][2];

void Pre() {
    int i,j;
    for (i=1;i<=65;i++) {
        a[i][i][0]=0;
        a[i][i][1]=1;
        a[i][i-1][1]=1;
        a[i][i-1][0]=0;
    }
    a[1][0][0]=1; a[1][0][1]=0;
    a[1][1][1]=1;
    for (i=2;i<=65;i++) {
        for (j=0;j<i-1;j++) {
            a[i][j][0]=a[i-1][j][0]+a[i-1][j+1][1];
            a[i][j][1]=a[i-1][j-1][0]+a[i-1][j-1][1];
        }
    }
}

void Print() {
    int i,j;
    for (i=1;i<=65;i++) {
        for (j=0;j<=65;j++) {
            printf("0:%lld-1:%lld \t",a[i][j][0],a[i][j][1]);
        }
        printf("\n");
    }
}

main() {
//    freopen("420inp.txt","r",stdin);
//    freopen("420out.txt","w",stdout);
    Pre();
//    Print();
    int n,s;
    scanf("%d %d",&n,&s);
    while (n>0 && s>=0) {
        if (n<s) printf("0\n");
        else printf("%lld\n",a[n][s][0]+a[n][s][1]);
        scanf("%d %d",&n,&s);
    }
}
