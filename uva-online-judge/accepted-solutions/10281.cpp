#include <iostream>

using namespace std;

struct Time {
    int h,m,s;
};

Time nw,ls;

double lastspeed, speed, KM, tme;
int n,out;

main() {
//    freopen("281.inp","r",stdin);
//    freopen("281.out","w",stdout);
    
    ls.h = ls.m = ls.s = 0;
    lastspeed = 0;
    KM = 0;
    char s[30];
    while (gets(s)) {
        n = strlen(s);
        s[2]=s[5]=' ';
  //      puts(s);
 //       cout << n << endl;
        if (n==8) {
            sscanf(s,"%d %d %d",&nw.h,&nw.m,&nw.s);
            out = 1;
        }
        else {
            sscanf(s,"%d %d %d %lf",&nw.h,&nw.m,&nw.s,&speed);
            out = 0;
        }
  //      cout << nw.h << ":" << nw.m << ":" << nw.s << endl;
        tme = (nw.h-ls.h) + (nw.m-ls.m)/60.0 + (nw.s-ls.s)/3600.0;
  //      cout << tme << endl;
        KM += tme*lastspeed;
        
        if (out) {
            if (nw.h<10) cout << "0";
            printf("%d:",nw.h);
            if (nw.m<10) cout << "0";
            printf("%d:",nw.m);
            if (nw.s<10) cout << "0";
            printf("%d ",nw.s);
            printf("%.2lf ",KM);
            cout << "km" << endl;
        }
        else {
            lastspeed = speed;
        }
        ls = nw;
    }
}
