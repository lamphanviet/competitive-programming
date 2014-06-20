#include <stdio.h>
#include <string.h>

int Yet;
int fb[100000][1010],len[100000];

void Pre() {
    fb[1][1]=fb[2][1]=1;
    len[1]=len[2]=1;
    Yet=2;
}

void Cong(int n) {
    int k,i,a,b;
    
    for (k=Yet+1;k<=n;k++) {
        i=1; a=k-1; b=k-2;
        while (i<=len[a] && i<=len[b]) {
            fb[k][i]=fb[a][i]+fb[b][i];
            i++;
        }
        if (i>len[a]) {
            for (;i<=len[b];i++)
                fb[k][i]=fb[b][i];
        }
        else if (i>len[b]) {
            for (;i<=len[a];i++)
                fb[k][i]=fb[a][i];
        }
        len[k]=i-1;
        int du=0,temp;
        for (i=1;i<=len[k];i++) {
            fb[k][i]+=du;
            temp=fb[k][i]%10;
            du=fb[k][i]/10;
            fb[k][i]=temp;
        }
        if (du>0) fb[k][++len[k]]=du;
    }
    Yet=n;
}

main() {
    Pre();
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n>Yet) Cong(n);
        for (int i=len[n];i>=1;i--)
            printf("%d",fb[n][i]);
        printf("\n");
    }
}
