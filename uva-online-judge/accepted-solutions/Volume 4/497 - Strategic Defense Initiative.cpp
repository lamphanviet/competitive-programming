// 497 - Strategic Defense Initiative
#include <iostream>
#include <vector>

using namespace std;

vector<int> a, b;

void LIS(vector<int> &Trace) {
    int u, v, mid, i;
    
    b.push_back(0);
    for (i=1; i<a.size(); i++) {
        if (a[i] > a[b.back()]) {
            Trace[i] = b.back();
            b.push_back(i);
            continue;
        }
        
        for (u=0, v=b.size()-1; u<v; ) {
            mid = (u+v)/2;
            if (a[b[mid]] < a[i]) u = mid+1;
            else v = mid;
        }
        
        if (a[i] < a[b[u]]) {
            if (u>0) Trace[i] = b[u-1];
            b[u] = i;
        }
    }
    
    for (u=b.size(), v = b.back(); u--; v = Trace[v]) b[u] = v;
}

main() {
    int kase, m;
    char s[15];
    cin >> kase; cin.ignore(2);
    while (kase--) {
        while (gets(s) && strlen(s)) {
            sscanf(s,"%d",&m);
            a.push_back(m);
        }
        vector<int> Trace(a.size());
        
        LIS(Trace);
        
        cout << "Max hits: " << b.size() << endl;
        for (int i=0; i<b.size(); i++)
            cout << a[b[i]] << endl;
        
        if (kase) cout << endl;
        a.clear(); b.clear(); Trace.clear();
    }
}
