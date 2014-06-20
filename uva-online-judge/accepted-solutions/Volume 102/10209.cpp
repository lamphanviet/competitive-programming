#include <stdio.h>
#include <math.h>

main() {
    double rad,PI,dt1,dt2,dt3;
    double dtVuong,dtTron,dtGoc,dtCung;
    PI=2*acos(0.0);
    while (scanf("%lf",&rad)!=EOF) {
        dtVuong = rad*rad;
        dtTron = dtVuong*PI/4;
        dtGoc = dtVuong-dtTron;
        dtCung = dtTron*4/3;
        double p = rad*(2+sqrt(3))/2;
        dtCung = dtCung - sqrt(p*(p-rad)*(p-rad)*(p-rad*sqrt(3)));
        dt1 = dtGoc-(dtTron-dtCung);
        dt2 = dtGoc-(2*dt1);
        dt1*=4; dt2*=4;
        dt3 = dtVuong-dt1-dt2;
        
        printf("%.3lf %.3lf %.3lf\n",dt3,dt2,dt1);
    }
}
