//----------------------------
// LAM PHAN VIET
// UVA 11777 - Automate the Grades
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 10

main() {
    int kase;
    scanf("%d", &kase);
    for (int k=1; k<=kase; k++) {
        double kq = 0;
        for (int i=0, j; i<4; i++) {
            scanf("%d", &j);
            kq += j;
        }
        int a[3];
        for (int i=0; i<3; i++)
            scanf("%d", &a[i]);
        sort(a, a+3);
        kq += (a[1]+a[2])/2.0;
        char ch;
        if (kq >= 90) ch = 'A';
        else if (kq >= 80) ch = 'B';
        else if (kq >= 70) ch = 'C';
        else if (kq >= 60) ch = 'D';
        else ch = 'F';
        printf("Case %d: %c\n", k, ch);
    }
}
