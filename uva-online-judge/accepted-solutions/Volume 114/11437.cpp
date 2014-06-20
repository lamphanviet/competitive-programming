#include <stdio.h>
#include <math.h>

double ax,ay,bx,by,cx,cy;
double dx,dy,ex,ey,fx,fy;
double rx,ry,px,py,qx,qy;


double mid(double u1, double u2) {
    return u1+(u2-u1)/3;
}

void Tinh_RPQ(int k, double a1x, double a1y, double b1x, double b1y, double a2x, double a2y, double b2x, double b2y) {
    double x,y;
    double a,b,c,d,e,f;
    
    a = b1y-a1y;
    b = a1x - b1x;
    e = a1x*b1y - a1y*b1x;      //Phuong trinh canh 1: ax+by=e
    
    c = b2y-a2y;
    d = a2x - b2x;
    f = a2x*b2y - a2y*b2x;      //Phuong trinh canh 2: cx+dy=f
    
    double dt = a*d - b*c;
    x = (e*d-b*f)/dt;   y = (a*f-c*e)/dt;
    
    if (k==1) {
        rx=x; ry=y;
    }
    else if (k==2) {
        px=x; py=y;
    }
    else {
        qx=x; qy=y;
    }
}

void Area() {
    double area,p,a,b,c;
    double t1,t2;
    t1=rx-px; t2=ry-py;
    a = sqrt(t1*t1+t2*t2);      //a = RP
    
    t1=px-qx; t2=py-qy;
    b = sqrt(t1*t1+t2*t2);      //b = PQ
    
    t1=qx-rx; t2=qy-ry;
    c = sqrt(t1*t1+t2*t2);      //c = QR
    
    p = (a+b+c)/2;
    
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    
    printf("%.0lf\n",area);
}

double Process() {
    dx=mid(bx,cx); dy=mid(by,cy);
    ex=mid(cx,ax); ey=mid(cy,ay);
    fx=mid(ax,bx); fy=mid(ay,by);
    
//    printf("d %.3lf %.3lf\n",dx,dy);
//    printf("e %.3lf %.3lf\n",ex,ey);
//    printf("f %.3lf %.3lf\n",fx,fy);
    
    // R=1;     P=2;    Q=3;
    Tinh_RPQ(1,ax,ay,dx,dy,cx,cy,fx,fy);
    Tinh_RPQ(2,bx,by,ex,ey,ax,ay,dx,dy);
    Tinh_RPQ(3,cx,cy,fx,fy,bx,by,ex,ey);
    
//    printf("r %.3lf %.3lf\n",rx,ry);
//    printf("p %.3lf %.3lf\n",px,py);
//    printf("q %.3lf %.3lf\n",qx,qy);
    
    Area();
//    printf("\n");
}

main() {
 //   freopen("437inp.txt","r",stdin);
 //   freopen("437out.txt","w",stdout);
    
    int time;
    scanf("%d",&time);
    while (time--) {
        scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);
        Process();
    }
}
