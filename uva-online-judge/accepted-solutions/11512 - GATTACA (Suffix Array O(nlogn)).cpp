/*****************/
/* LAM PHAN VIET */
/* UVA 11512 - GATTACA
/* Time limit: 7.000s
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
#define maxN 1010
using namespace std;

int n;
char s[maxN];
int H, Bucket[maxN], nBucket[maxN];

struct Suffix {
    int idx;
    bool operator < (const Suffix& sfx) const {
        if (H == 0) return s[idx] < s[sfx.idx];
        if (Bucket[idx] == Bucket[sfx.idx])
            return Bucket[idx + H] < Bucket[sfx.idx + H];
        else
            return Bucket[idx] < Bucket[sfx.idx];
    }
    bool operator == (const Suffix& sfx) const {
        return !(*this < sfx) && !(sfx < *this);
    }
} P[maxN];

int bucket_update() {
    int start = 0, id = 0, c = 0;
    REP(i, n) {
        if (i != 0 && !(P[i] == P[i - 1]))
            start = i, id++;
        if (i != start) c = 1;
        nBucket[P[i].idx] = id;
    }
    memcpy(Bucket, nBucket, 4 * (n + 1));
    return c;
}

void suffix_sort() {
    REP(i, n) P[i].idx = i;
    H = 0;
    sort(P, P + n);
    int c = bucket_update();
    for (H = 1; c; H *= 2) {
        sort(P, P + n);
        c = bucket_update();
    }
}

int find_len_max(int i, int j) {
    int len = 0;
    while (i < n && j < n)
        if (s[i++] != s[j++]) break;
        else len++;
    return len;
}

int find_number_repeated(string str) {
    int len = str.length(), Count = 0;
    for (int i = 0; i + len <= n; i++) {
        int j = 0;
        while (j < len && s[i + j] == str[j]) j++;
        if (j == len) Count++;
    }
    return Count;
}

void solve() {
    int len_max = 0, start = 0;
    for (int i = 1; i < n - 1; i++) {
        int len = find_len_max(P[i].idx, P[i + 1].idx);
        if (len > len_max) {
            len_max = len;
            start = P[i].idx;
        }
    }
    if (!len_max) {
        puts("No repetitions found!");
        return;
    }
    string result = "";
    for (int i = start; len_max--; i++)
        result += s[i];
    cout << result;
    printf(" %d\n", find_number_repeated(result));
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        gets(s);
        n = strlen(s) + 1;
        suffix_sort();
        solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
