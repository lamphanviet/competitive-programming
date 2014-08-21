// 11233 - Deli Deli
#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, string> Irr;

void Ans(string s) {
    int n = s.length();
    char last = s[n-1];
    string last2;
    if (n>1) last2 = s.substr(n-2, 2);
    if (last=='y') {
        char temp = last2[0];
        if (temp!='a' && temp!='o' && temp!='e' && temp!='u' && temp!='i') {
            s.erase(n-1, 1);
            s += "ies";
            cout << s << endl;
        }
        else cout << s << "s" << endl;
    }
    else if (last=='o' || last=='s' || last=='x' || last2=="ch" || last2=="sh") {
        cout << s << "es" << endl;
    }
    else cout << s << "s" << endl;
}

main() {
//    freopen("233.inp", "r", stdin); freopen("233.out", "w", stdout);
    string s, tmps, temp;
    int n, m, i, j;
    while (scanf("%d %d", &m, &n)!=EOF) {
        cin.get();
        while (m--) {
            cin >> s >> tmps;
            Irr[s] = tmps;
        }
        while (n--) {
            cin >> s;
            temp = Irr[s];
            if (temp!="") cout << temp << endl;
            else Ans(s);
        }
    }
}
