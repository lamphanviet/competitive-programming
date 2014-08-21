// 10282 - Babelfish
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

main() {
    string s, ans;
    map <string,string> mapchar;
    
    while (getline(cin,s) && s!="") {
        int space = s.find_first_of(' ',0);
        mapchar[s.substr(space+1,s.length())] = s.substr(0,space);
    }
    while (getline(cin,s)) {
        ans = mapchar[s];
        if (ans!="") cout << ans << endl;
        else cout << "eh" << endl;
    }
}
