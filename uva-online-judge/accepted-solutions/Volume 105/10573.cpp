#include <stdio.h>
#include <math.h>
#include <string.h>

bool Check(char s[]) {
    int n=strlen(s);
    for (int i=0;i<n;i++)
        if (s[i]==' ') return 0;
    return 1;
}

main() {
    double PI = 2*acos(0.0);
    int kase,r1,r2,t;
    char temps[20];
    double dt;
    
    scanf("%d",&kase); getchar();
    while (kase--) {
        gets(temps);
        if (Check(temps)) {
            sscanf(temps,"%d",&t);
            dt = PI*t*t/8;
        }
        else {
            sscanf(temps,"%d %d",&r1,&r2);
            dt = PI*2*r1*r2;    // PI*(r3*r3-r1*r1-r2*r2);
        }
        printf("%.4lf\n",dt);
    }
}
