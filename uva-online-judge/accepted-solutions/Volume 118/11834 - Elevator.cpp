// UVA Problem 11834 - Elevator
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2934
#include <iostream>
#include <math.h>

using namespace std;

int Check(int a, int b, int r1, int r2) {
    int temp, d;
    d = r1+r2;
    if (2*r1>b) return 0;
    if (a>=2*d) return 1;
    temp = b-d;
    double a1 = sqrt(d*d-temp*temp);

    a1 += d;
    if (a1<=a) return 1;
    
    return 0;
}

main() {
 //   freopen("e.inp","r",stdin);
 //   freopen("e.out","w",stdout);
    int temp,a,b,r1,r2;
    while (cin >> a >> b >> r1 >> r2) {
        if (a==0 && b==0 && r1==0 && r2==0) break;
        
        if (a<b) {
            temp = a; a = b; b = temp;
        }
        if (r1<r2) {
            temp = r1; r1 = r2; r2 = temp;
        }
        int k = Check(a,b,r1,r2);
        if (k==1) cout << "S";
        else cout << "N";
        cout << endl;
    }
}
