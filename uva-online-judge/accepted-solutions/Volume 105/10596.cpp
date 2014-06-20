#include <iostream>

using namespace std;

int n,a[210];

main() {
    int m,i,x,y;
    bool dk;
    while (cin >> n >> m) {
        for (i=0;i<n;i++) a[i]=0;
        while (m--) {
            cin >> x >> y;
            a[x]++;
            a[y]++;
        }
        
        dk=true;
        for (i=0;i<n && dk;i++)
            if (!(a[i]!=0 && a[i]%2==0)) dk=false;
        if (dk) cout << "Possible" << endl;
        else cout << "Not Possible" << endl;
    }
}
