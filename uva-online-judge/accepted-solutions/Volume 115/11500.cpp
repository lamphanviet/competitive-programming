#include <stdio.h>
#include <math.h>

int ev1,ev2,at,d;

float Run() {
    int a,b;
    float p;
    
    if (ev1%d==0) a=ev1/d;
    else a=1+ev1/d;
    if (ev2%d==0) b=ev2/d;
    else b=1+ev2/d;
    
 //   printf("ab %d %d\n",a,b);
    
    if (at==3) p = (float)a*100/(float)(a+b);
    else {
        float pat=(6.0-at)/at; // printf("pat %f\n",pat);
        p = 100.0*(1.0-pow(pat,a))/(1-pow(pat,a+b));
    }
    return p;
}

main() {
    scanf("%d %d %d %d",&ev1,&ev2,&at,&d);
    while (ev1!=0 && ev2!=0 && at!=0 &&d!=0) {
        printf("%.1f\n",Run());
        scanf("%d %d %d %d",&ev1,&ev2,&at,&d);
    }
}
