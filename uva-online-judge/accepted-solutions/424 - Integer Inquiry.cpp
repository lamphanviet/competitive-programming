// Problem 424 - Integer Inquiry
#include <iostream>
#include <string.h>

using namespace std;

main() {
//    freopen("424.inp","r",stdin);
//    freopen("424.out","w",stdout);
    
    int i,j,du,len;
    int rs[115],a[110][110],n;
    char s[110];
    n = 0;
    while (gets(s)) {
        len = strlen(s);
        if (len==0 && s[0]=='0') break;
        n++;
        for (i=len-1,j=1;i>=0;i--,j++)
            a[n][j] = s[i]-48;
        for (;j<=100;j++) a[n][j]=0;
    }
    du = 0; j = 1;
    while (j<=100 || du!=0) {
        for (i=1;i<=n;i++) du+=a[i][j];
        rs[j] = du%10;
        du = du/10;
        j++;
    }
    j--;
    while (rs[j]==0) j--;
    while (j>=1) cout << rs[j--];
    cout << endl;
}
