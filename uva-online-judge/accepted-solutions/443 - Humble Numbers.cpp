// 443 - Humble Numbers
#include <iostream>
#define LIM 2000000000

using namespace std;

int humble[5850], nh=0;
const int m2=30, m3=19, m5=13, m7=11;
char s[5][5];

void PreCal() {
    int i, j, u, v;
    long long a, b, c, d;
    for (i=0, a=1; i<=m2; i++) {
        if (a>LIM) break;
        for (j=0, b=a; j<=m3; j++) {
            if (b>LIM) break;
            for (u=0, c=b; u<=m5; u++) {
                if (c>LIM) break;
                for (v=0, d=c; v<=m7; v++) {
                    if (d>LIM) break;
                    humble[++nh] = (int)d;
                    d *= 7;
                }
                c *= 5;
            }
            b *= 3;
        }
        a *= 2;
    }
    strcpy(s[0], "th");
    strcpy(s[1], "st");
    strcpy(s[2], "nd");
    strcpy(s[3], "rd");
}

main() {
    PreCal();
    sort(humble+1, humble+nh+1);
    int n, k;
    while (scanf("%d", &n) && n) {
        int nn = n%100;
        if (nn==11 || nn==12 || nn==13) k=0;
        else switch (n%10) {
            case 1: k=1; break;
            case 2: k=2; break;
            case 3: k=3; break;
            default: k=0;
        }
        printf("The %d%s humble number is %d.\n", n, s[k], humble[n]);
    }
}
