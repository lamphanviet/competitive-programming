#include <iostream>
#include <math.h>

using namespace std;

double x[110],y[110],rad,radd;
double x1,ya1,x2,y2;
int n;

double Distance(int i, double xc, double yc) {
    return (x[i]-xc)*(x[i]-xc)+(y[i]-yc)*(y[i]-yc);
}

double Distance(int i, int j) {
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int Find_O(int i, int j) {
    double a,b,e,c,d,f,xmid,ymid,det;
    double temp = Distance(i,j)/4.0;
    if (temp > radd) return 0;
    
    a = y[i]-y[j];
    b = x[j]-x[i];
    e = x[i]*y[j]-x[j]*y[i];
    xmid = (x[i]+x[j])/2;
    ymid = (y[i]+y[j])/2;
    
    c = b;
    d = -a;
    f = b*xmid-a*ymid;
    
    e = sqrt(radd-temp)*sqrt(a*a+b*b)-e;
    
    det = (a*d-b*c);
    x1 = (e*d-b*f)/det;
    ya1 = (a*f-c*e)/det;
//    cout << i << " " << j << "  " << x1 << " " << ya1 << endl;
    x2 = 2*xmid - x1;
    y2 = 2*ymid - ya1;
//    cout << x2 << " " << y2 << endl;
    return 1;
}

bool Check() {
    if (n==1) return 1;
    int i,j,k,check;
    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++) {
            bool dk = Find_O(i,j);
            if (!dk) return 0;
            check = 1;
            for (k=1;k<=n;k++)
                if (Distance(k,x1,ya1)>radd) {
  //                  cout << Distance(k,x1,ya1) << endl;
                    check = 0; break;
                }
            if (check) return 1;
            else check = 1;
            
            for (k=1;k<=n;k++)
                if (Distance(k,x2,y2)>radd) {
                    check = 0; break;
                }
            if (check) return 1;
        }
    return 0;
}

main() {
    while (cin >> n) {
        if (n==0) break;
        for (int i=1;i<=n;i++)
            cin >> x[i] >> y[i];
        cin >> rad;
        radd = rad*rad;
        if (Check()) cout << "The polygon can be packed in the circle.";
        else cout << "There is no way of packing that polygon.";
        cout << endl;
    }
}
