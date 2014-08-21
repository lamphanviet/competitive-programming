#include <stdio.h>

int n,np,Lab[30010],max;

int GetRoot (int v) {
    while (Lab[v]>0) v=Lab[v];
    return v;
}

void Union(int r1, int r2) {
    int x=Lab[r1]+Lab[r2];
    if (Lab[r1]>Lab[r2]) {
        Lab[r1]=r2;
        Lab[r2]=x;
    }
    else {
        Lab[r1]=x;
        Lab[r2]=r1;
    }
    if (x<max) max=x;
}

void Kruskal() {
    int i,r1,r2;
    for (i=1;i<=n;i++)
        Lab[i]=-1;
    
    for (i=1;i<=np;i++) {
        scanf("%d %d",&r1,&r2);
        r1=GetRoot(r1); r2=GetRoot(r2);
        if (r1!=r2) {
            Union(r1,r2);
        }
    }
}

main() {
 //   freopen("608inp.txt","r",stdin);
 //   freopen("608out.txt","w",stdout);
    int kase;
    scanf("%d",&kase);
    while (kase-->0) {
        scanf("%d %d",&n,&np);
        max=-1;
        Kruskal();
        printf("%d\n",-max);
    }
}
