// 11860 - Document Analyzer
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

#define maxN 100000+5
int n, a[maxN], numword;
string s;
map <string, int> Val;
int p, q;

bool IsAlpha(char c) {
    return ('a'<=c && c<='z');
}

void Init() {
    numword = n = 0;
    Val.clear();
}

void Enter_Process() {
    char ch[200];
    while (scanf("%s", &ch)) {
        s = ch;
        if (s=="END") break;
        int i=0, k, len;
        string tmp;
        len = s.length();
        while (i<len) {
            while (i<len && !IsAlpha(s[i])) i++;
            if (i>=len) break;
            k = 1;
            while (i+k<len && IsAlpha(s[i+k])) k++;
            tmp = s.substr(i, k);
            i += k;
 //           cout << tmp << " ";
            int u = Val[tmp];
            if (u==0) {
                Val[tmp] = ++numword;
                a[n++] = numword;
            }
            else a[n++] = u;
        }
    }
//    cout << endl;
}

void Solve() {
    int kount, t[numword+5];
    kount = numword;
    for (int i=1; i<=numword; i++) t[i] = 0;
    p = n; q = 0;
    for (int i=0, j=0; i<n; i++) {
        if (++t[a[i]]==1) kount--;
        while (j<n && t[a[j]]-1>0) {
            t[a[j]]--;
            j++;
        }
        if (!kount && i-j<p-q) {
            p = i; q = j;
        }
    }
}

main() {
//    freopen("doc.inp", "r", stdin); freopen("doc.out", "w", stdout);
    int kase;
    char line[10];
    scanf("%d", &kase); gets(line);
    for (int kk=1; kk<=kase; ++kk) {
        Init();
        Enter_Process();
        Solve();
        printf("Document %d: %d %d\n", kk, q+1, p+1);
    }
}
