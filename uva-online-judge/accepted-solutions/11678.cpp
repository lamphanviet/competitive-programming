#include <stdio.h>

int n,m,a[10010],b[10010];

void Enter() {
    int i,j,k,x;
    for (i=1,k=1;i<=n;i++) {
        scanf("%d",&x);
        if (x!=a[k-1]) a[k++]=x;
    }
    n=k-1;
    for (i=1,k=1;i<=m;i++) {
        scanf("%d",&x);
        if (x!=b[k-1]) b[k++]=x;
    }
    m=k-1;
}

int Process() {
    int i,j,k,tn=n,tm=m;
    for (i=1,j=1;i<=n;i++) {
        while (j<=m && a[i]>b[j]) j++;
        if (j>m) break;
        if (a[i]==b[j]) {
            tn--; tm--; j++;
        }
    }
    
    if (tn<tm) return tn;
    else return tm;
}

void Print() {
    for (int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    for (int i=1;i<=m;i++)
        printf("%d ",b[i]);
    printf("\n");
}

main() {
//    freopen("678inp.txt","r",stdin);
//    freopen("678out.txt","w",stdout);
    scanf("%d %d",&n,&m); a[0]=b[0]=0;
    while (n!=0 && m!=0) {
        Enter(); // Print();
        printf("%d\n",Process());
        scanf("%d %d",&n,&m);
    }
}
