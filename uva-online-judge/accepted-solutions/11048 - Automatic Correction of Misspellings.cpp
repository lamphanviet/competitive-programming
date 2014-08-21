//*****************
// LAM PHAN VIET **
// UVA 11048 - Automatic Correction of Misspellings
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100005
string word, ans;
int k;
map<string, int> Index;

void Check() {
    int n = word.length(), idx;
    For (i, 1, n-1) {
        swap(word[i-1], word[i]);
        idx = Index[word];
        if (idx>0 && idx<k) {
            ans = word; k = idx;
            if (k==1) return;
        }
        swap(word[i-1], word[i]);
    }
    string tmp;
    For (i, 0, n-1) {
        tmp = word;
        tmp.erase(tmp.begin()+i);
        idx = Index[tmp];
        if (idx>0 && idx<k) {
            ans = tmp; k = idx;
            if (k==1) return;
        }
    }
    For (i, 0, n) {
        tmp = word;
        tmp.insert(tmp.begin()+i, 'a');
        for (tmp[i]='a'; tmp[i]<='z'; tmp[i]++) {
            idx = Index[tmp];
            if (idx>0 && idx<k) {
                ans = tmp; k = idx;
                if (k==1) return;
            }
        }
    }
    For (i, 0, n-1) {
        char ch = word[i];
        for (word[i]='a'; word[i]<='z'; word[i]++) {
            idx = Index[word];
            if (idx>0 && idx<k) {
                ans = word; k = idx;
                if (k==1) return;
            }
        }
        word[i] = ch;
    }
    /*
    tmp = "a"; tmp += word;
    for (tmp[0]='a'; tmp[0]<='z'; tmp[0]++) {
        idx = Index[tmp];
        if (idx>0 && idx<k) {
            ans = tmp; k = idx;
            if (k==1) return;
        }
    }
    tmp = word; tmp += 'a';
    for (tmp[n]='a'; tmp[n]<='z'; tmp[n]++) {
        idx = Index[tmp];
        if (idx>0 && idx<k) {
            ans = tmp; k = idx;
            if (k==1) return;
        }
    } */
}

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int n;
    char s[100];
    scanf("%d", &n); getchar();
    For (i, 1, n) {
        scanf("%s", &s);
        Index[s] = i;
    }
    scanf("%d", &n); getchar();
    while (n--) {
        cin >> word;
        cout << word;
        if (Index[word]) puts(" is correct");
        else {
            k = maxN;
            Check();
            if (k<maxN) {
                printf(" is a misspelling of ");
                cout << ans << endl;
            }
            else puts(" is unknown");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
