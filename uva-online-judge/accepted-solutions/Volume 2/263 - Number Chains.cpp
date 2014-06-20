//*****************
// LAM PHAN VIET **
// UVA 263 - Number Chains
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 15
map<string, int> Exist;

bool cmp(char a, char b) {
    return (a>b);
}

string Chain(string s1) {
    string s2 = s1;
    sort(s1.begin(), s1.end(), cmp);
    sort(s2.begin(), s2.end());
    int a = 0, b = 0;
    for (int i=s1.size()-1, hs=1; i>=0; i--, hs*=10)
        a += (s1[i]-48)*hs;
    for (int i=s2.size()-1, hs=1; i>=0; i--, hs*=10)
        b += (s2[i]-48)*hs;
    printf("%d - %d = ", a, b);
    a -= b; cout << a << endl;
    s1 = "";
    while (a) {
        s1 += a%10 + 48;
        a /= 10;
    }
    reverse(s1.begin(), s1.end());
    return s1;
}

main() {
//    freopen("263.inp", "r", stdin); freopen("263.out", "w", stdout);
    int Count;
    string s;
    while (cin >> s && s[0]!='0') {
        Exist.clear();
        Count = 0;
        printf("Original number was "); cout << s << endl;
        do {
            Exist[s] = 1;
            s = Chain(s);
            Count++;
        } while (Exist[s]==0);
        printf("Chain length %d\n\n", Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
