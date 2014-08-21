#include <stdio.h>

char s[110][110];
int m,n,a[110][110];

void Print() {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
}

int Count() {
    int i,j,u,v;
    if (s[0][0]=='1') a[0][0]=1;
    else a[0][0]=0;
    for (j=1;j<n;j++) {
        a[0][j]=a[0][j-1];
        if (s[0][j]=='1') a[0][j]++;
    }
    for (i=1;i<m;i++) {
        a[i][0]=a[i-1][0];
        if (s[i][0]=='1') a[i][0]++;
    }
    for (i=1;i<m;i++)
        for (j=1;j<n;j++) {
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if (s[i][j]=='1') a[i][j]++;
        }
//    Print();
    
    int sum,count=0;
    for (i=0;i<m;i++)
        for (j=0;j<n;j++) {
            for (u=i;u<m;u++)
                for (v=j;v<n;v++) {
                    sum = a[u][v]-a[u][j-1]-a[i-1][v]+a[i-1][j-1];
                    if (sum==(u-i+1)*(v-j+1)) count++;
                }
        }
    
    return count;
}


main() {
    while (scanf("%d",&m)) {
        if (m==0) break;
        scanf("%d",&n); getchar();
        for (int i=0;i<m;i++)
            gets(s[i]);
        printf("%d\n",Count());
    }
}
