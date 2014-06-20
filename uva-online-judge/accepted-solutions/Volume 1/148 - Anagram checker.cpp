//*****************
// LAM PHAN VIET **
// UVA 148 - Anagram checker
// Time limit:
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define maxN 2010
#define maxS 25
char word[maxN][maxS], s[maxN];
int nw, len[maxN], n;
vector<int> num(100);
vector<string> ss;

void Backtracking(int k, vector<int> num, vector<int>ans) {
    for (int i=0; i<len[k]; i++) {
        num[word[k][i]]--;
        if (num[word[k][i]]<0) return;
    }
    bool f = true;
    for (int i='A'; i<='Z' && f; i++)
        if (num[i]) f = false;
    if (f) {
        vector<string> a;
        a.push_back(word[k]);
        for (int i=0, size=ans.size(); i<size; i++)
            a.push_back(word[ans[i]]);
        if (a.size()==ss.size()) {
            sort(a.begin(), a.end());
            bool same = true;
            for (int i=0, size=a.size(); i<size && same; i++)
                if (a[i]!=ss[i]) same = false;
            if (same) return;
        }
        
        printf("%s = ", s);
        for (int i=0, size=ans.size(); i<size; i++)
            printf("%s ", word[ans[i]]);
        printf("%s\n", word[k]);
        return;
    }
    ans.push_back(k);
    for (k++; k<nw; k++)
        Backtracking(k, num, ans);
}

main() {
    freopen("148.inp", "r", stdin); freopen("148.out", "w", stdout);
    nw = 0;
    while (gets(word[nw])) {
        if (word[nw][0]=='#') break;
        len[nw] = strlen(word[nw]); nw++;
    }
    while (gets(s)) {
        if (s[0]=='#') break;
        n = strlen(s);
        for (int i='A'; i<='Z'; i++) num[i] = 0;
        for (int i=0; i<n; i++) num[s[i]]++;
        
        ss.clear();
        char tmpstr[maxS];
        int x = 0;
        while (x<n) {
            while (x<n && s[x]==' ') x++;
            if (x<n) {
                sscanf(s+x, "%s", &tmpstr);
                ss.push_back(tmpstr);
            }
            while (x<n && s[x]!=' ') x++;
        }
        sort(ss.begin(), ss.end());
        vector<int> tmpans;
        for (int i=0; i<nw; i++)
            Backtracking(i, num, tmpans);
    }
}

/* lamphanviet@gmail.com - 2011 */
