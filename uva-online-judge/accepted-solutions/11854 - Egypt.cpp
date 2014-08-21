// UVA Problem 11854 - Egypt
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2954
#include <iostream>
#include <math.h>

using namespace std;

int a,b,c;

int Check() {
    int temp;
    if (a==0 || b==0 || c==0) return 0;
    if (a<b) {
        temp=a; a=b; b=temp;
    }
    if (a<c) {
        temp=a; a=c; c=temp;
    }
    if ((b*b+c*c)==a*a) return 1;
    return 0;
}

main() {
    while (cin >> a >> b >> c) {
        if (a==0 && b==0 && c==0) break;
        int k = Check();
        if (k==1) cout << "right";
        else cout << "wrong";
        cout << endl;
    }
}
