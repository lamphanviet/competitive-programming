//----------------------------
// LAM PHAN VIET
// UVA 417 - Word Index
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

#define maxN 83685
int nword = 0;
map<string, int> wIndex;
string word[maxN];

bool cmp(string a, string b) {
    int lena = a.length(), lenb = b.length();
    return (lena<lenb || (lena==lenb && a<b));
}

void Backtracking(string s, char lastch, int len) {
    if (lastch=='z') return;
    for (char ch=lastch+1; ch<='z'; ch++) {
        word[nword++] = s+ch;
        if (len<5) Backtracking(s+ch, ch, len+1);
    }
}

main() {
    Backtracking("", 'a'-1, 1);
    sort(word, word+nword, cmp);
    for (int i=0; i<nword; i++)
        wIndex[word[i]] = i+1;
    char str[7];
    while (scanf("%s", &str)!=EOF) {
        printf("%d\n", wIndex[str]);
    }
}
