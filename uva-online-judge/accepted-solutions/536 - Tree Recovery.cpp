//*****************
// LAM PHAN VIET **
// UVA 536 - Tree Recovery
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100000
bool Exist[maxN];
char key[maxN];

void PostOrder(int p) {
    if (p>=maxN || !Exist[p]) return;
    PostOrder(p+p);
    PostOrder(p+p+1);
    printf("%c", key[p]);
}

main() {
//    freopen("536.inp", "r", stdin); freopen("536.out", "w", stdout);
    char preord[30], inord[30];
    while (scanf("%s %s", &preord, &inord)!=EOF) {
        memset(Exist, false, maxN);
        int n = strlen(preord);
        Exist[1] = true; key[1] = preord[0];
        For (i, 1, n-1) {
            char ch = preord[i];
            int p = 1;
            while (Exist[p]) {
                bool left = true;
                For (i, 0, n-1)
                    if (inord[i]==ch) break;
                    else if (inord[i]==key[p]) left = false;
                p += p;
                if (!left) p++;
            }
            Exist[p] = true;
            key[p] = ch;
        }
        PostOrder(1);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
