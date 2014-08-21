// 11269 - Setting Problems
#include <iostream>

using namespace std;

typedef struct Work {
    int x, y;
};

Work a[25], a1[25], a2[25];
int n, n1, n2;

bool cmp1(Work a, Work b) {
    return (a.x<b.x);
}
bool cmp2(Work a, Work b) {
    return (a.y>b.y);
}

main() {
    int i, j;
    while (cin >> n) {
        for (i=0; i<n; i++) scanf("%d", &a[i].x);
        for (i=0; i<n; i++) scanf("%d", &a[i].y);
        
        n1 = n2 = 0;
        for (i=0; i<n; i++) {
            if (a[i].x<=a[i].y) a1[n1++] = a[i];
            else a2[n2++] = a[i];
        }
        
        sort(a1, a1+n1, cmp1);
        sort(a2, a2+n2, cmp2);
        
        for (i=n1, j=0; j<n2; i++, j++)
            a1[i] = a2[j];
        
 //       for (i=0; i<n; i++) printf("%4d", a1[i].x); cout << endl;
 //       for (i=0; i<n; i++) printf("%4d", a1[i].y); cout << endl;
        
        int w1=a1[0].x, w2=a1[0].x;
        for (i=1; i<n; i++) {
            w1 += a1[i].x;
            w2 = max (w2+a1[i-1].y, w1);
        }
        
        
        w2 += a1[n-1].y;
        cout << w2 << endl;
    }
}
