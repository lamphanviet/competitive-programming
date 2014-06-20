#include <iostream>
#include <string.h>

using namespace std;

main() {
//    freopen("51.inp","r",stdin);
//    freopen("51.out","w",stdout);
    int kase, i, k, tempmax;
    int a[1010], n, max;
    char s[1010];
    cin >> kase; getchar();
    while (kase--) {
        gets(s);
        n = strlen(s);
        for (i=0;i<=n;i++) a[i]=0;
        max = 0;
        for (k=0;k<n;k++) {
            tempmax = 0;
            for (i=n-1;i>=0;i--) {
                if (s[i]==s[k]) {
                    if (a[i]<=tempmax) a[i]=tempmax+1;
                    else tempmax = a[i];
                    if (a[i]>max) max = a[i];
                }
                else if (a[i]>tempmax) tempmax = a[i];
            }
        }
//        for (i=0;i<n;i++)
//            printf("%3d",a[i]);
//        cout << endl;
        cout << max << endl;
    }
}
