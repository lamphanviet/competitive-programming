//*****************
// LAM PHAN VIET **
// UVA 401 - Palindromes
// Time limit: 3.000s
//********************************
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
int n;
char s[maxN], Reverse[100];

void PreCal() {
    memset(Reverse, 0, sizeof(Reverse));
    Reverse['A'] = 'A'; Reverse['T'] = 'T';
    Reverse['E'] = '3'; Reverse['U'] = 'U';
    Reverse['H'] = 'H'; Reverse['V'] = 'V';
    Reverse['I'] = 'I'; Reverse['W'] = 'W';
    Reverse['J'] = 'L'; Reverse['X'] = 'X';
    Reverse['L'] = 'J'; Reverse['Y'] = 'Y';
    Reverse['M'] = 'M'; Reverse['Z'] = '5';
    Reverse['O'] = 'O'; Reverse['1'] = '1';
    Reverse['S'] = '2'; Reverse['2'] = 'S';
    Reverse['3'] = 'E'; Reverse['5'] = 'Z';
    Reverse['8'] = '8';
}

bool PalinCheck() {
    int i = 0, j = n-1;
    while (i<j)
        if (s[i++]!=s[j--]) return false;
    return true;
}

bool MirrorCheck() {
    int i = 0, j = n-1;
    while (i<=j)
        if (s[i++]!=Reverse[s[j--]]) return false;
    return true;
}

int Check() {
    n = strlen(s);
    bool p = PalinCheck();
    bool m = MirrorCheck();
    if (p && m) return 1;
    if (p) return 2;
    if (m) return 3;
    return 4;
}

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    PreCal();
    while (scanf("%s", &s)!=EOF) {
        int ans = Check();
        printf("%s -- ", s);
        switch (ans) {
            case 1: puts("is a mirrored palindrome."); break;
            case 2: puts("is a regular palindrome."); break;
            case 3: puts("is a mirrored string."); break;
            case 4: puts("is not a palindrome."); break;
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
