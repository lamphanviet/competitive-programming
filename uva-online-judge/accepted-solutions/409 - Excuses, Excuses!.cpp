/*****************/
/* LAM PHAN VIET */
/* UVA 409 - Excuses, Excuses!
/* Time limit: 3.000s
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
#define maxN 25
using namespace std;

int n, m, word_count[maxN];
map<string, int> store;
char s[maxN][1000];

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    while (scanf("%d %d ", &m, &n) != EOF) {
        store.clear();
        while (m--) {
            scanf(" %s ", &s[0]);
            store[s[0]] = 1;
        }
        int word_max = -1;
        FOR (i, 1, n) {
            gets(s[i]);
            word_count[i] = 0;
            int len = strlen(s[i]), k = 0;
            string word = "";
            while (k < len) {
                if (isalpha(s[i][k]))
                    word += tolower(s[i][k]);
                else {
                    if (word != "") word_count[i] += store[word];
                    word = "";
                }
                k++;
            }
            if (word != "") word_count[i] += store[word];
            word_max = max(word_count[i], word_max);
        }
        
        printf("Excuse Set #%d\n", ++Case);
        FOR (i, 1, n)
            if (word_count[i] == word_max)
                puts(s[i]);
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
