// 231 - Testing the CATCHER
#include <iostream>

using namespace std;

main() {
    int n, i, j, a[100000], max1, len[100000];
    int kase = 0;
    bool End = false;
    while (cin >> a[0]) {
        if (a[0]==-1) break;
        if (End) cout << endl;
        End = true;
        n = 0;
        while (cin >> a[++n])
            if (a[n]==-1) break;
        max1 = 0;
        for (i=0;i<n;i++) {
            len[i] = 1;
            for (j=i-1;j>=0;j--)
                if (a[i]<a[j] && len[j]+1>len[i])
                    len[i] = len[j] + 1;
            if (len[i]>max1) max1 = len[i];
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++kase,max1);
    }
}
