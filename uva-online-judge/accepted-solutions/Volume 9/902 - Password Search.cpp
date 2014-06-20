// 
#include <iostream>
#include <string>
#include <map>

using namespace std;

main() {
    map <string, int> App;
    map <string, int>::iterator it,ans;
    string str;
    int k, n, i, len;
    while (cin >> k >> str) {
        n = str.length();
        i = 0;
        while (i+k<=n) {
            string temp(str,i,k);
            ++App[temp];
            i++;
        }
        
        for (it = ans = App.begin(), k = 0; it!=App.end(); it++)
            if (it->second > k) {
                ans = it; k = it->second;
            }
        cout << ans->first << endl;
        App.clear();
    }
}
