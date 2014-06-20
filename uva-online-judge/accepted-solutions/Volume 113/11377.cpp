#include <stdio.h>
#include <iostream>

#define Max 5555

int n;
bool sb[2010], a[2010][2010];

void Enter() {
    int i,j,u,v,m,k;
    scanf("%d %d %d",&n,&m,&k);
    
    memset(sb,false,n+3);
    for (i=1;i<=n;i++)
        memset(a[i],false,n+3);
    
    for (i=1;i<=k;i++) {
        scanf("%d",&u);
        sb[u]=true;
    }
    
    for (i=1;i<=m;i++) {
        scanf("%d %d",&u,&v);
        a[u][v]=a[v][u]=true;
    }
}

void SolveDijsktra(int s, int f) {
    int d[n+3],i,u,min;
    bool Free[n+3];
    
    memset(Free,true,n+3);
    for (i=1;i<=n;i++)
        d[i]=Max;
    
    if (sb[s]) d[s]=0;
    else d[s]=1;
    while (1) {
        u=0; min=Max;
        for (i=1;i<=n;i++)
            if (Free[i] && d[i]<min) {
                u=i; min=d[i];
            }
        if (u==0 || u==f) break;
        Free[u]=false;
        
        for (i=1;i<=n;i++)
            if (Free[i] && a[i][u]) {
                if (sb[i] && d[u]<d[i]) d[i]=d[u];
                else if (!sb[i] && d[u]+1<d[i]) d[i]=d[u]+1;
            }
    }
//    printf("d:  "); for (i=1;i<=n;i++)  printf("%d ",d[i]); printf("\n");
    
    if (d[f]==Max) printf("-1\n");
    else printf("%d\n",d[f]);
}

void Result() {
    int m,s,f;
    scanf("%d",&m);
    while (m-->0) {
        scanf("%d %d",&s,&f);
        if (s==f) printf("0\n");
        else SolveDijsktra(s,f);
    }
}

main() {
 //   freopen("377inp.txt","r",stdin);
 //   freopen("377out.txt","w",stdout);
    
    int time;
    scanf("%d",&time);
    for (int t=1;t<=time;t++) {
        Enter();
        printf("Case %d:\n",t);
        Result();
        printf("\n");
    }
}
