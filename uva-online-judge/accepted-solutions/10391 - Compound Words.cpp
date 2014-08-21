//*****************
// LAM PHAN VIET **
// UVA 10391 - Compound Words
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
vector<string> word;
map<string, int> Exist;

main() {
 //   freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    string a, b;
    char s[50];
    while (gets(s)) {
        Exist[s] = 1;
        word.push_back(s);
    }
    For (i, 0, word.size()-1) {
        int len = word[i].length();
        For (j, 1, len-2) {
            a = word[i].substr(0, j);
            b = word[i].substr(j, len);
            if (Exist[a] && Exist[b]) {
                cout << word[i] << endl;
                break;
            }
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
