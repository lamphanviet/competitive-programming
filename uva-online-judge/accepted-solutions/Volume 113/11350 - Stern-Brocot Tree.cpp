//*****************
// LAM PHAN VIET **
// UVA 11350 - Stern-Brocot Tree
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 92
typedef unsigned long long ULL;
class Node {
    ULL x, y, lx, ly, rx, ry;
public:
    Node() {
        x = y = ly = rx = 1;
        lx = ry = 0;
    }
    void GoLeft() {
        rx = x; ry = y;
        x = lx+rx; y = ly+ry;
    }
    void GoRight() {
        lx = x; ly = y;
        x = lx+rx; y = ly+ry;
    }
    void Print() {
        printf("%lld/%lld\n", x, y);
    }
};

main() {
    Node a;
    int Case, n;
    char s[maxN];
    scanf("%d", &Case); gets(s);
    while (Case--) {
        gets(s); n = strlen(s);
        a = Node();
        for (int i=0; i<n; i++)
            if (s[i]=='L') a.GoLeft();
            else a.GoRight();
        a.Print();
    }
}
/* lamphanviet@gmail.com - 2011 */
