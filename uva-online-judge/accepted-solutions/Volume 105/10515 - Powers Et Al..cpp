// 10515 - Powers Et Al.
#include <stdio.h>
#include <math.h>
#include <string.h>

char x[110],y[110];
int mlen,nlen;
int a[10][10];

void Pre() {
    a[2][1]=2; a[2][2]=4; a[2][3]=8; a[2][0]=6;
    a[3][1]=3; a[3][2]=9; a[3][3]=7; a[3][0]=1;
    a[7][1]=7; a[7][2]=9; a[7][3]=3; a[7][0]=1;
    a[8][1]=8; a[8][2]=4; a[8][3]=2; a[8][0]=6;
}

int LastDigit() {
    int lastm=x[mlen-1]-48,lastn=y[nlen-1]-48;
    if (lastm==0) return 0;
    if (lastm==1) return 1;
    if (nlen==1 && y[0]=='1') return lastm;
    else if (nlen==1 && y[0]=='0') return 1;
    
    if (lastm==5) return 5;
    if (lastm==6) return 6;
    
    if (lastm==4) {
        if (lastn%2==0) return 6;
        else return 4;
    }
    
    if (lastm==9) {
        if (lastn%2==0) return 1;
        else return 9;
    }
    
    if (nlen>=2) lastn+=(y[nlen-2]-48)*10;
    
    return a[lastm][lastn%4];
}

main() {
    Pre();
    while (scanf("%s %s",&x,&y)) {
        mlen=strlen(x); nlen=strlen(y);
        if (mlen==1 && nlen==1 && x[0]=='0' && y[0]=='0') break;
        printf("%d\n",LastDigit());
    }
}
