// Problem 748 - Exponentiation
#include <iostream>

using namespace std;

main() {
//    freopen("748.inp","r",stdin);
//    freopen("748.out","w",stdout);
    
    char x[10];
    int a[10],rs[500],n,m,dot;
    int i,j,k;
    
    while (scanf("%s %d",&x,&m)!=EOF) {
        n = strlen(x);
        dot = 0;
        while (dot< n && x[dot]!='.') dot++;
        k = 1;
        for (i=n-1;i>dot;i--,k++) a[k] = rs[k] = x[i]-48;
        for (i=dot-1;i>=0;i--,k++) a[k] = rs[k] = x[i]-48;
        n = k-1;
        for (i=n+1;i<=500;i++) rs[i] = 0;
        for (i=1;i<=n;i++) cout << a[i];
        cout << endl;
        for (i=2;i<=m;i++) {
            for (j=1;j<=n;j++)
        }
        
        while (rs[k]==0) k--;
        while (k>=1) cout << rs[k--];
        cout << endl;
    }
}
