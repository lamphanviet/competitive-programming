//*****************
// LAM PHAN VIET **
// UVA 10815 - Andy's First Dictionary
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
vector<string> ans;

main() {
//    freopen("815.inp", "r", stdin); freopen("815.out", "w", stdout);
    string s;
    while (cin >> s) {
        s += '.';
        string tmp = "";
        int len = s.length(), i = 0;
        while (i<len) {
            if (isalpha(s[i])) tmp += tolower(s[i]);
            else {
                if (tmp!="") ans.push_back(tmp);
                tmp = "";
            }
            i++;
        }
    }
    sort(ans.begin(), ans.end());
    int size = ans.size();
    if (size>0) cout << ans[0] << endl;
    For (i, 1, size-1)
        if (ans[i-1]!=ans[i]) cout << ans[i] << endl;
}

/* lamphanviet@gmail.com - 2011 */
