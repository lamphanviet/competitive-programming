/*****************/
/* LAM PHAN VIET */
/* UVA 11283 - Playing Boggle
/* Time limit: 2.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 6
using namespace std;

const int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int n = 4, word_len;
char s[maxN][maxN], word[maxN * maxN];
bool flag[maxN][maxN];
bool found;

void dfs(int x, int y, int k) {
    if (k == word_len - 1)
        found = true;
    if (found) return;
    REP(i, 8) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if (flag[xx][yy] && s[xx][yy] == word[k + 1]) {
            flag[xx][yy] = false;
            dfs(xx, yy, k + 1);
            flag[xx][yy] = true;
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m;
    scanf("%d ", &Case);
    FOR (test, 1, Case) {
        Fill(flag, true);
        int score = 0;
        
        REP(i, n) gets(s[i]);
        scanf("%d ", &m);
        while (m--) {
            gets(word);
            word_len = strlen(word);
            found = false;
            for (int i = 0; i < n && !found; i++)
                for (int j = 0; j < n && !found; j++)
                    if (s[i][j] == word[0]) {
                        flag[i][j] = false;
                        dfs(i, j, 0);
                        flag[i][j] = true;
                    }
            if (found) {
                if (word_len <= 4) score++;
                else if (word_len == 5) score += 2;
                else if (word_len == 6) score += 3;
                else if (word_len == 7) score += 5;
                else if (word_len >= 8) score += 11;
            }
        }
        printf("Score for Boggle game #%d: %d\n", test, score);
        gets(word);
    }
}

/* lamphanviet@gmail.com - 2011 */
