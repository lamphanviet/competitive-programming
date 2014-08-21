#include <stdio.h>

char a[12][12];
short int n;

void Enter() {
    scanf("%d",&n); getchar();
    for (int i=0;i<n;i++) gets(a[i]);
}

bool Check(int i, int j, char K) {
    int u,v;
    if (i!=0 && a[i-1][j]==K) return 0;
    if (i!=n-1 && a[i+1][j]==K) return 0;
    if (j!=0 && a[i][j-1]==K) return 0;
    if (j!=n-1 && a[i][j+1]==K) return 0;
    return 1;
}

void Fill() {
    int i,j,k;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) if (a[i][j]=='.') {
            for (k='A';k<='Z';k++)
                if (Check(i,j,k)) {
                    a[i][j]=k;
                    break;
                }
        }
    }
}

void Result(int t) {
    printf("Case %d:\n",t);
    for (int i=0;i<n;i++)
        puts(a[i]);
}

main() {
//    freopen("520inp.txt","r",stdin);
//    freopen("520out.txt","w",stdout);
    int time;
    scanf("%d",&time);
    for (int t=1;t<=time;t++) {
        Enter();
        Fill();
        Result(t);
    }
}
