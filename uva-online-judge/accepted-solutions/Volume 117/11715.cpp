// Problem 11715 - Car
#include <iostream>
#include <math.h>

using namespace std;

int sitt;
double x,y,z;

void Cal() {
    double u,v,t,s,a;
    if (sitt==1) {
        a = (y-x)/z;
        s = (y*y-x*x)/(2*a);
        printf("%.3lf %.3lf",s,a);
        return;
    }
    if (sitt==2) {
        s = (y*y-x*x)/(2*z);
        t = (y-x)/z;
        printf("%.3lf %.3lf",s,t);
        return;
    }
    if (sitt==3) {
        v = sqrt(2*y*z+x*x);
        t = (v-x)/y;
        printf("%.3lf %.3lf",v,t);
    }
    else {
        u = sqrt(x*x-2*y*z);
        t = (x-u)/y;
        printf("%.3lf %.3lf",u,t);
    }
}

main() {
    int kase = 0;
    while (cin >> sitt && sitt!=0) {
        kase++;
        cin >> x >> y >> z;
        cout << "Case " << kase << ": ";
        Cal();
        cout << endl;
    }
}
