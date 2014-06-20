//*****************
// LAM PHAN VIET **
// UVA 12012 - Detection of Extraterrestrial
// Time limit: 1.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Forv(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 1002
using namespace std;

int n, p[maxN];
char s[maxN];

int Check(int k) {
    int len = n/k;
    while (len) {
        p[1] = 0;
        For (i, 2, k) p[i] = p[i-1] + len;
  //      printf("Len %d:", len);
  //      For (i, 1, k) printf(" %d", p[i]);
  //      printf("\n");
        int tmplen = 0;
        while (p[k]<n) {
            char ch = s[p[1]];
            bool ok = true;
            For (i, 1, k)
                if (s[p[i]++]!=ch) ok = false;
            if (ok) {
                if (++tmplen == len) return len*k;
            }
            else tmplen = 0;
        }
        len--;
    }
    return 0;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case); getchar();
    For (kk, 1, Case) {
        gets(s); n = strlen(s);
        printf("Case #%d: %d", kk, n);
        For (i, 2, n) {
   //         printf("\n%d Doan: \n", i);
            int k = Check(i);
            if (k==0) {
                For (j, i, n) printf(" 0");
                break;
            }
            printf(" %d", k);
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
