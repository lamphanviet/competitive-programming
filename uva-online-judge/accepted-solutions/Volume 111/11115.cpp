#include <stdio.h>
#include <math.h>
#include <string.h>

int a,b,len;
char rs[30];

void Result() {
    for (int i=len;i>=1;i--)
        printf("%c",rs[i]);
    printf("\n");
}

void Multi() {
    int i,du=0,temp;
    len=1; rs[1]='1';
    while (b-->0) {
        for (i=1;i<=len;i++) {
            temp=(rs[i]-48)*a;
            temp+=du;
            rs[i]=(temp%10)+48;
            du=temp/10;
        }
        if (du>0) {
            rs[++len]=du+48; du=0;
        }
    }
    Result();
}

main() {
    int time,i,k;
    scanf("%d %d",&a,&b);
    while (a!=0 || b!=0) {
        if (b==0) printf("1\n");
        else if (b==1) printf("%d\n",a);
        else if (a==10) {
            printf("1");
            for (i=1;i<=b;i++) printf("0");
            printf("\n");
        }
        else Multi();
        scanf("%d %d",&a,&b);
    }
}
