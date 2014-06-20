// 10405 - Longest Common Subsequence
#include <iostream>

using namespace std;

main() {
 //   freopen("405.inp","r",stdin);
//    freopen("405.out","w",stdout);
    char a[1005], b[1005];
    int x[1005], i, k, tempmax, max1, na, nb;
    while (gets(a) && gets(b)) {
        na = strlen(a); nb = strlen(b);
        for (i=0;i<nb;i++)
            x[i] = 0;
        max1 = 0;
        for (k=0;k<na;k++) {
            tempmax = 0;
            for (i=0;i<nb;i++)
                if (a[k]==b[i]) {
                    if (x[i]<=tempmax) x[i] = tempmax+1;
                    else tempmax = x[i];
                    if (x[i]>max1) max1 = x[i];
                }
                else if (x[i]>tempmax) tempmax = x[i];
        }
        cout << max1 << endl;
    }
}
