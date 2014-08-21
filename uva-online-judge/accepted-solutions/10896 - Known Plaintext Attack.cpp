//*****************
// LAM PHAN VIET **
// UVA 10896 - Known Plaintext Attack
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
char word[75];
int wordlength;

int Num(int a, int b) {
    if (a>=b) return a-b;
    return (26 - (b-a));
}

int Check(string s) {
    if (s.length()!=wordlength) return -1;
    int k = Num(s[0], word[0]);
    For (i, 1, wordlength-1)
        if (Num(s[i], word[i])!=k) return -1;
    return k;
}

main() {
//    freopen("896.inp", "r", stdin); freopen("896.out", "w", stdout);
    int Case, n;
    char line[75];
    scanf("%d", &Case); getchar();
    while (Case--) {
        gets(line); n = strlen(line); line[n] = ' ';
        gets(word); wordlength = strlen(word);
        int i = 0;
        vector<char> ans;
        string s = "";
        while (i<=n) {
            if (line[i]!=' ') s += line[i];
            else if (s!="") {
                int k = Check(s);
                if (k>=0) ans.push_back('a'+k);
                s = "";
            }
            i++;
        }   
        
        sort(ans.begin(), ans.end());
        For (i, 0, ans.size()-1) printf("%c", ans[i]);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
