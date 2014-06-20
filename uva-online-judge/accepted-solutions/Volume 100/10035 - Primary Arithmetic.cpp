//UVA Problem 10035 - Primary Arithmetic
#include <iostream>

using namespace std;

main() {
    long a,b,dem,x,y,du;
    while (cin >> a >> b) {
        if (a==0 && b==0) break;
        dem = 0; du = 0;
        while (a!=0 || b!=0) {
            x = a%10; a/=10;
            y = b%10; b/=10;
            if (x+y+du>9) {
                dem++; du=1;
            }
            else du=0;
            if ((a==0 || b==0) && du==0) break;
        }
        
        if (dem==0) cout << "No";
        else cout << dem;
        cout << " carry operation";
        if (dem>1) cout << "s.";
        else cout << ".";
        cout << endl;
    }
}
