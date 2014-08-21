//----------------------------
// LAM PHAN VIET
// UVA 11948 - Reading a Quadtree
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 20000
#define maxS 50000
int n, len;
char s[maxS], mp[maxN][maxN];

bool isPow2(int l) {
    while (l && l%2==0) l/=2;
    return (l==1);
}

void Fill(char color, int x1, int y1, int x2, int y2) {
    for (int i=x1; i<=x2; i++)
        for (int j=y1; j<=y2; j++)
            mp[i][j] = color;
}

int Process(int k, int x1, int y1, int x2, int y2) {
    if (s[k]!='*') {
        Fill(s[k], x1, y1, x2, y2);
        return k+1;
    }
    int xm = (x1+x2)/2, ym = (y1+y2)/2;
    
    k = Process(k+1, x1, y1, xm, ym); // Part 1
    k = Process(k, x1, ym+1, xm, y2); // Part 2
    k = Process(k, xm+1, y1, x2, ym); // Part 3
    k = Process(k, xm+1, ym+1, x2, y2); // Part 4
    return k;
}

void Print() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            printf("%c", mp[i][j]);
        printf("\n");
    }
}

void Result() {
    bool cmm = false;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            if (mp[i][j]=='1') {
                int y = j;
                while (y<n && mp[i][y+1]=='1') y++;
                if (cmm) printf(","); cmm = true;
                if (y==j) printf("(%d,%d)", j, i);
                else printf("(%d-%d,%d)", j, y, i);
                j = y;
            }
    }
}

main() {
//    freopen("948.inp", "r", stdin); freopen("948.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        scanf("%s", &s); len = strlen(s);
        if (!isPow2(n)) printf("Invalid length");
        else {
            Process(0, 1, 1, n, n);
 //           Print();
            Result();
        }
        printf("\n");
    }
}
