// Problem 10106 - Product
#include <iostream>

using namespace std;

main() {
 //   freopen("106.inp","r",stdin);
 //   freopen("106.out","w",stdout);
    
    char x[255],y[255];
    int a[255],b[255],rs[505];
    int na,nb,i,j,k,du;
    
    while (gets(x) && gets(y)) {
        na = strlen(x);     nb = strlen(y);
        for (i=0;i<na;i++) a[na-i] = x[i]-48;
        for (i=0;i<nb;i++) b[nb-i] = y[i]-48;
        for (i=1;i<=500;i++) rs[i]=0;
        for (i=1;i<=nb;i++) {
            for (j=1,k=i;j<=na;j++,k++) rs[k] += b[i]*a[j];
        }
        du = 0;
        for (i=1;i<=500;i++) {
            du += rs[i];
            rs[i] = du%10;
            du /= 10;
        }
        k = 500;
        while (k>=1 && rs[k]==0) k--;
        if (k==0) cout << "0";
        else while (k>=1) cout << rs[k--];
        cout << endl;
    }
}
