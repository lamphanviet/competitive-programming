//----------------------------
// LAM PHAN VIET
// UVA 11879 - Multiple of 17
// Time limit: 1s
//----------------------------
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int first, last, a[10105];

int Check() {
    int i, j, b;
    while (last-first+1>15) {
        b = a[last]*5;
        i = --last;
        while (b>0) {
            int temp = a[i];
            while (temp<b) temp+=10;
            a[i] = temp-b;
            b = temp/10;
            i--;
        }
        
/*        for (i=first; i<=last; i++)
            printf("%d", a[i]);
        cout << endl;   */
    }
    
    long long hs, ans = 0;
    
    for (i=last, hs=1; i>=first; i--, hs*=10)
        ans += a[i]*hs;
    if (ans%17) return 0;
    else return 1;
}

main() {
//    freopen("879.inp", "r", stdin); freopen("879.out", "w", stdout);
    char s[10105];
    int i, j;
    while (gets(s)) {
        last = strlen(s);
        if (last==1 && s[0]=='0') break;
        for (i=1; i<=last; i++)
            a[i] = s[i-1]-48;
        first = 1;
        printf("%d\n", Check());
    }
}
