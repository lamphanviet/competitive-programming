//*****************
// LAM PHAN VIET **
// UVA 11955 - Binomial Theorem
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define maxN 105
#define maxC 51
typedef unsigned long long ULL;
ULL C[maxC][maxC];

void PreCal() {
    C[0][0] = 1;
    for (int i=1; i<maxC; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j=1; j<i; j++)
            C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
}

main() {
//    freopen("ee.inp", "r", stdin); freopen("ee.out", "w", stdout);
    PreCal();
    int Case, K, n;
    string a, b;
    char s[maxN];
    scanf("%d", &Case); gets(s);
    for (int kk=1; kk<=Case; kk++) {
        gets(s); n = strlen(s);
        a = b = "";
        int k = 1;
        while (s[k]!='+') a += s[k++];
        k++;
        while (s[k]!=')') b += s[k++];
        k += 2;
        sscanf(s+k, "%d", &K);
        printf("Case %d: ", kk);
        cout << a;
        if (K>1) printf("^%d", K);
        
        for (k=1; k<K; k++) {
            printf("+%lld*", C[K][k]);
            cout << a;
            if (K-k>1) printf("^%d", K-k);
            cout << "*" << b;
            if (k>1) printf("^%d", k);
        }
        
        printf("+");
        cout << b;
        if (K>1) printf("^%d", K);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
