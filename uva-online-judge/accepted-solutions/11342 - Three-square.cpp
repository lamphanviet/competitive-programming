//*****************
// LAM PHAN VIET **
// UVA 11342 - Three-square
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 50000
class Answer {
public:
    int a, b, c;
    bool exist;
    Answer() { a=b=c=0; exist=false; }
    void Get(int x, int y, int z) {
        if (exist) return;
        a=x; b=y; c=z;
        exist=true;
    }
    void Print() {
        if (!exist) {
            printf("-1\n");
            return;
        }
        printf("%d %d %d\n", a, b, c);
    }
};
Answer ans[maxN+1];

void PreCal() {
    for (int a=0; a<=maxN; a++) {
        int aa = a*a;
        if (aa>maxN) break;
        for (int b=a; b<=maxN; b++) {
            int ab = aa + b*b;
            if (ab>maxN) break;
            for (int c=b; c<=maxN; c++) {
                int abc = ab+c*c;
                if (abc>maxN) break;
                ans[abc].Get(a, b, c);
            }
        }
    }
}

main() {
    PreCal();
    int Case, n;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        ans[n].Print();
    }
}

/* lamphanviet@gmail.com - 2011 */
