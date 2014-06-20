#include <iostream.h>
#include <math.h>

double x[110],y[110];
int n;

void Swap(int i, int j) {
    double temp;
    temp=x[i]; x[i]=x[j]; x[j]=temp;
    temp=y[i]; y[i]=y[j]; y[j]=temp;
}

double Theta(int i, int j) {
    double dx, dy, ax, ay, t;
    dx = x[j]-x[i];     ax = fabs(dx);
    dy = y[j]-y[i];     ay = fabs(dy);
    if (dx==0 && dy==0) t=0;
    else t = dy/(ax+ay);
    if (dx<0) t=2-t;
    else if (dy<0) t+=4;
    return t*90.0;
}

void Wrap() {
    int i,k,m,u;
    double min;
    
    for (i=1,k=0;i<n;i++)
        if (y[i]<y[k] || (y[i]==y[k] && x[i]>x[k])) k=i;
    Swap(0,k);
    x[n]=x[0]; y[n]=y[0]; m=0;
    do {
        min=360; u=m+1;
        for (i=m+1;i<=n;i++) {
            double goc = Theta(m,i);
            if (goc!=0 && goc<min) {
                min = goc;
                u = i;
            }
        }
        Swap(++m,u);
    } while (u!=n);
    n=m;
}

double DT(int i, int j) {
    return (x[0]*y[i]-y[0]*x[i]+y[0]*x[j]-x[0]*y[j]+x[i]*y[j]-x[j]*y[i])/2;
}

int Solve() {
    if (n>=3) Wrap();
    int i,j;
    
 //   for (i=0;i<n;i++)
 //       cout << x[i] << " " << y[i] <<endl;
 //   cout << endl;
    
    double F, xi, yi, dt=0, yc=0 ,xc=0;
    
    for (i=0;i<n;i++) {
        j=(i+1)%n;
        dt += (x[i]*y[j]-x[j]*y[i]);
    }
    dt = fabs(dt)/2;
    for (i=1;i<n-1;i++) {
        F = DT(i,i+1);
        xi = (x[0]+x[i]+x[i+1])/3.0;
        yi = (y[0]+y[i]+y[i+1])/3.0;
        xc += xi*F;
        yc += yi*F;
    }
    xc/=dt;
    yc/=dt;
    
    printf("%.3lf %.3lf\n",xc,yc);
}

main() {
//    freopen("002.inp","r",stdin);
//    freopen("002.out","w",stdout);
    while (cin >> n) {
        if (n<3) break;
        for (int i=0;i<n;i++)
            cin >> x[i] >> y[i];
        Solve();
    }
}
