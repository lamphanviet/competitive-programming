// 11362 - Phone List
#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, int> Free;
map <string, int>::iterator it;

main() {
    int kase, i, len, j, n;
    string str[10005];
    cin >> kase; cin.get();
    while (kase--) {
        cin >> n ; cin.get();
        for (i=1;i<=n;i++)
            cin >> str[i];
        sort(str+1,str+n+1);
        
        for (i=1;i<=n;i++) {
  //          cout << str[i] << endl;
            len = str[i].length();
            for (j=1;j<len;j++) {
                string temp(str[i],0,j);
                Free[temp] = -1;
            }
            Free[str[i]] = i;
        }
//        for (it=Free.begin();it!=Free.end();it++)
//            cout << it->first << " " << it->second << endl;
        
        bool ans = true;
        for (i=1;i<=n && ans;i++)
            if (Free[str[i]]==-1) ans = false;
            
        if (ans) cout << "YES";
        else cout << "NO";
        cout << endl;
        Free.clear();
    }
}
