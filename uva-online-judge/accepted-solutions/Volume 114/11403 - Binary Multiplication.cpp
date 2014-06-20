//----------------------------
// LAM PHAN VIET
// UVA 11403 - Binary Multiplication
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 35
char a[maxN], b[maxN];
int ans[maxN+maxN];
int lena, lenb, len;

void PrintResult() {
    int i, lm, maxlen;
    maxlen = max(lena+lenb-1, len);
    
    for (i=0, lm=maxlen-lena; i<lm; i++) printf(" ");
    puts(a);
    
    for (i=0, lm=maxlen-lenb; i<lm; i++) printf(" ");
    puts(b);
    
    for (i=0, lm=maxlen-max(lena, lenb); i<lm; i++) printf(" ");
    while (i<maxlen) {
        printf("-"); i++;
    }
    printf("\n");
    
    lm = maxlen-lena;
    for (int j=lenb-1; j>=0; j--) {
        for (i=0; i<lm; i++) printf(" ");
        if (b[j]=='0') {
            for (i=0; i<lena; i++) printf("0");
            printf("\n");
        }
        else puts(a);
        lm--;
    }
    
    for (i=0; i<maxlen; i++) printf("-");
    printf("\n");
    
    for (i=0, lm=maxlen-len; i<lm; i++) printf(" ");
    while (len>0) printf("%d", ans[--len]);
    printf("\n\n");
}

main() {
//    freopen("403.inp", "r", stdin); freopen("403.out", "w", stdout);
    while (scanf("%s %s", &a, &b)!=EOF) {
        lena = strlen(a); lenb = strlen(b);
        if (lena==1 && lenb==1 && a[0]=='0' && b[0]=='0') break;
        len = lena + lenb - 1;
        for (int i=0; i<len; i++)
            ans[i] = 0;
        for (int i=lena-1, m1=0; i>=0; i--, m1++)
            for (int j=lenb-1, m2=0; j>=0; j--, m2++)
                ans[m1+m2] += (a[i]-48)*(b[j]-48);
        int du = 0;
        for (int i=0; i<len; i++) {
            ans[i] += du;
            du = ans[i]/2;
            ans[i] = ans[i]%2;
        }
        while (du) {
            ans[len++] = du%2;
            du /= 2;
        }
        while (len>1 && ans[len-1]==0) len--;
        PrintResult();
    }
}
