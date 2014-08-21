// 628 - Passwords
#include <iostream>
#include <string>

using namespace std;

void Print(string rule, int rlen, string word, int k, string output) {
    if (k==rlen) {
        cout << output << endl; return;
    }
    
    if (rule[k]=='0') {
        for (char num='0'; num<='9'; num++) {
            Print(rule, rlen, word, k+1, output+num);
        }
    }
    else {
        while (k<rlen && rule[k]!='0') {
            output += word; k++;
        }
        Print(rule, rlen, word, k, output);
    }
}

main() {
 //   freopen("628.inp", "r", stdin); freopen("628.out", "w", stdout);
    string rule[1005], word[105];
    int n, m, i, j;
    while (scanf("%d", &n)==1) {
        cin.get();
        for (i=0; i<n; i++) cin >> word[i];
        scanf("%d", &m); cin.get();
        for (i=0; i<m; i++) cin >> rule[i];
        
        printf("--\n");
        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                Print(rule[i], rule[i].length(), word[j], 0, "");
    }
}
