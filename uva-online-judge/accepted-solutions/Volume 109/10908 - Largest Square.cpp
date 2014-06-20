// 10908 - Largest Square
#include <iostream>
#include <string.h>
#define N 105

using namespace std;

int n, m, up[N][N], down[N][N];
char s[N][N];
/*
void Print() {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=0; j<m; j++)
            printf("%4d", down[i][j]);
        cout << endl;
    }
    cout << endl;
    for (i=1; i<=n; i++) {
        for (j=0; j<m; j++)
            printf("%4d", up[i][j]);
        cout << endl;
    }
}
*/
void Process(int x, int y) {
    char ch = s[x][y];
    int j, lm, temp;
    lm = min(up[x][y], down[x][y]);
//    printf("start %c %d\n", s[x][y], lm);
    for (j=1; j<=lm && (y-j>=0); j++) {
        if (s[x][y-j]!=ch) break;
        temp = min(up[x][y-j], down[x][y-j]);
        if (temp<j) break;
        if (temp<lm) lm=temp;
    }
    lm = j-1;
    for (j=1; j<=lm && (y+j<m); j++) {
        if (s[x][y+j]!=ch) break;
        temp = min(up[x][y+j], down[x][y+j]);
        if (temp<j) break;
        if (temp<lm) lm=temp;
    }
    lm = j-1;
    printf("%d\n", lm*2+1);
}

main() {
//    freopen("908.inp", "r", stdin); freopen("908.out", "w", stdout);
    int kase, i, j, ques, x, y;
    cin >> kase;
    while (kase--) {
        scanf("%d %d %d", &n, &m, &ques);
        printf("%d %d %d\n", n, m, ques);
        
        for (i=1; i<=n; i++)
            scanf("%s", s[i]);
            
        for (j=0; j<m; j++)
            up[n][j] = down[1][j] = 0;
            
        for (i=2; i<=n; i++)
            for (j=0; j<m; j++)
                if (s[i][j]==s[i-1][j]) down[i][j] = down[i-1][j]+1;
                else down[i][j] = 0;
                
        for (i=n-1; i>=1; i--)
            for (j=0; j<m; j++)
                if (s[i][j]==s[i+1][j]) up[i][j] = up[i+1][j]+1;
                else up[i][j] = 0;
 //       Print();
        
        while (ques--) {
            scanf("%d %d", &x, &y);
            Process(x+1, y);
        }
    }
}
