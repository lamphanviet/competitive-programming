// 673 - Parentheses Balance
#include <iostream>
#include <stack>

using namespace std;

main() {
    int kase, i, n;
    char str[200];
    cin >> kase; cin.get();
    while (kase--) {
        gets(str);
        n = strlen(str);
        bool ans = true;
        stack <char> L;
        for (i=0; i<n && ans; i++) {
            if (str[i]=='(' || str[i]=='[') L.push(str[i]);
            else if (L.empty()) ans = false;
            else if (str[i]==')') {
                if (L.top()=='(') L.pop();
                else ans = false;
            }
            else {
                if (L.top()=='[') L.pop();
                else ans = false;
            }
        }
        if (!L.empty()) ans = false;
        if (ans) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
