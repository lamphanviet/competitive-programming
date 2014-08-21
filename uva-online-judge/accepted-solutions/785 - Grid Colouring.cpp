// 785 - Grid Colouring
#include <iostream>

using namespace std;

char s[35][85];
bool Free[35][85];
int n;

void DFS_Fill(int u, int v, char ch) {
    if (u<0 || u>=n || v<0 || v>=strlen(s[u]) || s[u][v]!=' ') return;
    s[u][v] = ch; Free[u][v] = false;
    DFS_Fill(u+1, v, ch); DFS_Fill(u, v+1, ch);
    DFS_Fill(u-1, v, ch); DFS_Fill(u, v-1, ch);
}

main() {
//    freopen("785.inp", "r", stdin); freopen("785.out", "w", stdout);
    while (gets(s[0])) {
        n=0;
        while (gets(s[++n])) {
            if (s[n][0]=='_') break;
        }
        for (int i=0; i<n; i++)
            memset(Free[i], true, strlen(s[i])+1);
        for (int i=0; i<n; i++)
            for (int j=0; j<strlen(s[i]); j++)
                if (Free[i][j] && s[i][j]!=' ' && s[i][j]!='X') {
                    char ch = s[i][j]; s[i][j] = ' ';
                    DFS_Fill(i, j, ch);
                }
        
        for (int i=0; i<=n; i++) puts(s[i]);
    }
}
