//*****************
// LAM PHAN VIET **
// UVA 11062 - Andy's Second Dictionary
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 500
vector<string> word;

main() {
    freopen("062.inp", "r", stdin); freopen("062.out", "w", stdout);
    char s[50000];
    string tmpword = "";
    while (gets(s)) {
        int len = strlen(s);
        For (i, 0, len-1)
            if (isalpha(s[i])) tmpword += tolower(s[i]);
            else if (s[i]=='-') {
                if (i!=len-1) tmpword += s[i];
            }
            else if (tmpword!="") {
                word.push_back(tmpword);
                tmpword = "";
            }
        if (s[len-1]!='-' && tmpword!="") {
            word.push_back(tmpword);
            tmpword = "";
        }
    }
    sort(word.begin(), word.end());
    cout << word[0] << endl;
    For (i, 1, word.size()-1)
        if (word[i-1]!=word[i])
            cout << word[i] << endl;
}

/* lamphanviet@gmail.com - 2011 */
