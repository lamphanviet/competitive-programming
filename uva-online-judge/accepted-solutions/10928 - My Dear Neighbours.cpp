//*****************
// LAM PHAN VIET **
// UVA 10928 - My Dear Neighbours
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001
int n, num[maxN];

main() {
 //   freopen("928.inp", "r", stdin); freopen("928.out", "w", stdout);
    int Case;
    char s[maxN*10];
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n); getchar();
        int tmpmin = maxN;
        For (i, 1, n) {
            num[i] = 0;
            gets(s);
            int len = strlen(s), k = 0;
            while (k<len) {
                while (k<len && s[k]==' ') k++;
                if (k<len) num[i]++;
                while (k<len && s[k]!=' ') k++;
            }
            tmpmin = min(tmpmin, num[i]);
        }
        vector<int> ans;
        For (i, 1, n)
            if (num[i]==tmpmin) ans.push_back(i);
        sort(ans.begin(), ans.end());
        printf("%d", ans[0]);
        for (int i=1, size=ans.size(); i<size; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
