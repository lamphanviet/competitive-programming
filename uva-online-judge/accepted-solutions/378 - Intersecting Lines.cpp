#include <stdio.h>
#include <math.h>

int x1,x2,x3,x4,ya1,y2,y3,y4;

void Check() {
    int a,b,e,c,d,f;
    a=-(ya1-y2);
    b=x1-x2;
    e=x1*y2-x2*ya1;
    
    c=-(y3-y4);
    d=x3-x4;
    f=x3*y4-x4*y3;
    
    double detA=a*d-b*c;
    
    if (detA!=0) {
        double x,y;
        x=(e*d-b*f)/detA;
        y=(a*f-e*c)/detA;
        printf("POINT %.2lf %.2lf\n",x,y);
    }
    else if (a*x3+b*y3-e==0) printf("LINE\n");
    else printf("NONE\n");
}

main() {
    int kase;
    scanf("%d",&kase);
    printf("INTERSECTING LINES OUTPUT\n");
    while (kase-->0) {
        scanf("%d %d %d %d",&x1,&ya1,&x2,&y2);
        scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
        Check();
    }
    printf("END OF OUTPUT\n");
}
