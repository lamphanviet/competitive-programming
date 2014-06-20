//*****************
// LAM PHAN VIET **
// UVA 11943 - The heart flu
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#define maxN 10000
char s[maxN];

main() {
 //   freopen("943.inp", "r", stdin); freopen("943.out", "w", stdout);
    bool line = false;
    while (gets(s)) {
        int age, len = strlen(s), i = 0;
        
        if (line) printf("---\n"); line = true;
        while (i<len) {
            if (s[i]=='*') break;
            printf("%c", s[i]);     // name
            i++;
        }
        printf("\n"); i++;
        sscanf(s+i, "%d", &age);
        printf("%d\n", age);        // age
        
        int duration = -1;
        double a, Min = maxN, Max = -maxN;
        bool pass = true;
        
        while (s[i]!='*') i++;
        while (i<len && pass) {
            i++;
            sscanf(s+i, "%lf", &a);
            Min = min(Min, a);
            Max = max(Max, a);
            if (++duration>10 || Max-Min>35) pass = false;
            while (i<len && s[i]!=',') i++;
        }
        if (duration<6) pass = false;
        
        printf("Triage ");
        if (!pass) printf("NO ");
        printf("PASS\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
