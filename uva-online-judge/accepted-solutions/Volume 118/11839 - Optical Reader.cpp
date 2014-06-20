// UVA Problem 11839 - Optical Reader
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2939
#include <iostream>

using namespace std;

main() {
//    freopen("j.inp","r",stdin);
//    freopen("j.out","w",stdout);
    
    int n,vt,b;
    int i,a[10];
    while (cin >> n) {
        if (n==0) break;
        
        while (n-->0) {
            b = 0;
            for (i=1;i<=5;i++) {
                cin >> a[i];
                if (a[i]<=127) {
                     b++;
                     vt=i;
                }
            }
            
            if (b!=1) cout << '*';
            else {
                if (vt==1) cout << 'A';
                else if (vt==2) cout << 'B';
                else if (vt==3) cout << 'C';
                else if (vt==4) cout << 'D';
                else cout << 'E';
            }
            
            cout << endl;
        }
    }
}
