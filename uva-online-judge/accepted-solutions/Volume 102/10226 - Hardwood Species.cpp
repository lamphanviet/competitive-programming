// 10226 - Hardwood Species
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

main() {
 //   freopen("226.inp","r",stdin);
//    freopen("226.out","w",stdout);
    
    map <string,int> mapPer;
    map <string,int>::iterator it;
    string s;
    int kase, sum;
    
    cin >> kase;
    cin.ignore(2);
    while (kase--) {
        sum = 0;
        while (getline(cin,s) && s.length()) {
            mapPer[s]++;
            sum++;
        }
        for (it = mapPer.begin(); it!=mapPer.end(); it++) {
            cout << it->first << " ";
            printf("%.4lf\n",(it->second)*100.0/(double)sum);
        }
        if (kase) cout << endl;
        mapPer.clear();
    }
}
