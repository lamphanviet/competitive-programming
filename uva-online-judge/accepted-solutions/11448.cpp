#include <stdio.h>
#include <string.h>

char x[5][10010];
int a,b,c=3,na,nb,nc;
bool dau;

void DaoChuoi() {
    char temp; int i,j;
    for (i=0,j=na-1;i<na/2;i++,j--) {
        temp=x[1][i];
        x[1][i]=x[1][j];
        x[1][j]=temp;
    }
    for (i=0,j=nb-1;i<nb/2;i++,j--) {
        temp=x[2][i];
        x[2][i]=x[2][j];
        x[2][j]=temp;
    }
}

int Cmp(char a[10010], char b[10010]) {
    int n,m,i;
    n=strlen(a); m=strlen(b);
    if (n>m) return 1;
    if (n<m) return -1;
    for (i=n-1;i>=0;i--)
        if (a[i]!=b[i]) {
            if (a[i]>b[i]) return 1;
            else return -1;
        }
    return 0;
}

bool Enter() {
    int i;
    scanf("%s %s",&x[1],&x[2]);
    a=1; b=2; dau=true;
    na=strlen(x[1]); nb=strlen(x[2]);
    DaoChuoi();
    
    while (x[a][na-1]=='0') {
        x[a][na-1]='\0'; na--;
    }
    while (x[b][nb-1]=='0') {
        x[b][nb-1]='\0'; nb--;
    }
    
    int k=Cmp(x[1],x[2]);
    
    if (k==0) return false;
    if (k<0) {
        a=2; b=1; dau=false;
        na=na+nb;
        nb=na-nb;
        na=na-nb;
    }
    
    nc=na;
    for (i=nb;i<nc;i++) x[b][i]='0';
    x[b][nc]='\0';
    return true;
}

void Print() {
    if (!dau) printf("-");
    while (x[c][nc-1]=='0') nc--;
    for (int i=nc-1;i>=0;i--)
        printf("%c",x[c][i]);
    printf("\n");
}

int Minus() {
    short int i;
    bool muon=false;
    
    if (!Enter()) {
        printf("0\n");
        return 0;
    }
    
    for (i=0;i<nc;i++) {
        if (muon) {
            x[b][i]++; muon=false;
        }
        
        if (x[a][i]-x[b][i]<0) {
            x[c][i]=x[a][i]-x[b][i]+58;     //58=10+48
            muon=true;
        }
        else x[c][i]=x[a][i]-x[b][i]+48;
    }
    x[c][nc]='\0';
    Print();
    return 0;
}

main() {
    int time;
    scanf("%d",&time); getchar();
    while (time-->0) {
        Minus();
    }
}
