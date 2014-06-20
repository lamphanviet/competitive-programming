//*****************
// LAM PHAN VIET **
// UVA 10508 - Word Morphing
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
#define maxN 2005
vector<string> word;
vector<bool> Free;

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int n, m;
    while (scanf("%d %d", &n, &m)!=EOF) {
        getchar();
        word.resize(n); Free.resize(n);
        For (i, 0, n-1) {
            cin >> word[i];
            Free[i] = true;
        }
        cout << word[0] << endl;
        Free[0] = false;
        string s = word[0];
        while (1) {
            bool f = false;
            For (i, 0, n-1)
                if (Free[i]) {
                    bool dif = false;
                    For (j, 0, m-1)
                        if (word[i][j]!=s[j]) {
                            dif = !dif;
                            if (!dif) break;
                        }
                    if (dif) {
                        cout << word[i] << endl;
                        Free[i] = false;
                        s = word[i];
                        f = true;
                        break;
                    }
                }
            if (!f) break;
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
