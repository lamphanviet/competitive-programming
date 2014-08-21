// UVA Problem 11850 - Alaska
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2950
#include <iostream>

using namespace std;

main() {
    int i,j,n;
    int a[1430];
    bool f;
    while (cin >> n && n!=0) {
        for (i=1;i<=n;i++)
            cin >> a[i];
        for (i=1;i<n;i++)
            for (j=i+1;j<=n;j++)
                if (a[i]>a[j]) {
                    int temp=a[i]; a[i]=a[j]; a[j]=temp;
                }
        f = true;
        if (1422-a[n]>100) f = false;
        else
            for (i=2;i<=n;i++)
                if (a[i]-a[i-1]>200) {
                    f = false; break;
                }
        if (f) cout << "POSSIBLE";
        else cout << "IMPOSSIBLE";
        cout << endl;
    }
}
