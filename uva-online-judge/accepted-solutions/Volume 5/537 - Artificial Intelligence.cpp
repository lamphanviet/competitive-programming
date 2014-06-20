//*****************
// LAM PHAN VIET **
// UVA 537 - Artificial Intelligence
// Time limit: 3.000s
// Run Time: 
//********************************
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 200
double P, U, I;
bool isP, isU, isI;

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int Case;
    char s[maxN];
    double val;
    scanf("%d", &Case); getchar();
    For (kk, 1, Case) {
        gets(s);
        int len = strlen(s), i = 0;
        isP = isU = isI = false;
        while (i<len)
            if (s[i]=='=') {
                char ch = s[i-1];
                i++;
                sscanf(s+i, "%lf", &val);
                while (isdigit(s[i])) i++;
                if (s[i]=='.') i++;
                while (isdigit(s[i])) i++;
                if (s[i]=='m') val /= 1000.0;
                else if (s[i]=='k') val *= 1000;
                else if (s[i]=='M') val *= 1000000;
                switch (ch) {
                    case 'P': P = val; isP = true; break;
                    case 'U': U = val; isU = true; break;
                    case 'I': I = val; isI = true; break;
                }
            }
            else i++;
        printf("Problem #%d\n", kk);
        if (!isP) printf("P=%.2lfW", U*I);
        else if (!isU) printf("U=%.2lfV", P/I);
        else printf("I=%.2lfA", P/U);
        printf("\n\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
