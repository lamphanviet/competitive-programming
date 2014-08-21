#include <iostream>
#include <math.h>

using namespace std;

const double PI = 2.0*acos(0.0);

double alpha,N,R, r, blue, green;

main() {
 //   freopen("283.inp","r",stdin);
 //   freopen("283.out","w",stdout);
    
    while (cin >> R >> N) {
        if (N<2) {
            printf("%.10lf %.10lf %.10lf\n",R,0.0,0.0);
            continue;
        }
        alpha = PI*(1-(N-2)/N)/2;
        r = R*sin(alpha)/(sin(alpha)+1.0);
        double areasmall = PI*r*r*N;
        double b = PI/2.0-alpha;
        b = r*r*b/2;
        double a1 = sqrt((R-r)*(R-r)-r*r);
        blue = r*a1/2.0;
        blue = blue-b;
        blue *= N*2;
        green = PI*R*R-areasmall-blue;
        
        printf("%.10lf %.10lf %.10lf\n",r,blue,green);
    }
}
