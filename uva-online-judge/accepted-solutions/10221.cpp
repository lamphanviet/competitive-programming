#include <stdio.h>
#include <math.h>

#define Rad 6440

double PI,angle,s,chord,arc;
char str[5];

main() {
 //   freopen("221.inp","r",stdin);
 //   freopen("221.out","w",stdout);
    PI = 2*acos(0.0);
    while (scanf("%lf %lf %s",&s,&angle,&str)!=EOF) {
        s+=Rad;
        if (str[0]=='m') angle=angle/60;
        while (angle>360) angle-=360;
        if (angle>180) angle=360-angle;
        arc = (PI*s*angle)/180;
        angle=angle*PI/180;
        chord = sqrt(2*s*s*(1-cos(angle)));
        printf("%.6lf %.6lf\n",arc,chord);
    }
}
