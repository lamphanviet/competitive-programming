// 11456 - Trainsorting
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

void Increase(vector<int> &len) {
    vector<int> b;
    
    b.push_back(n-1); len[n-1] = 1;
    for (int i=n-1; i>=0; i--) {
        if (a[i] > a[b.back()]) {
            b.push_back(i);
            len[i] = b.size();
            continue;
        }
        
        int u, v;
        for (u = 0, v = b.size()-1; u<v; ) {
            int mid = (u+v)/2;
            if (a[b[mid]] < a[i]) u = mid+1;
            else v = mid;
        }
        
        if (a[i] < a[b[u]]) b[u] = i;
        len[i] = u+1;
    }
}

void Decrease(vector<int> &len) {
    vector<int> b;
    
    b.push_back(n-1); len[n-1] = 1;
    for (int i=n-1; i>=0; i--) {
        if (a[i] < a[b.back()]) {
            b.push_back(i);
            len[i] = b.size();
            continue;
        }
        
        int u, v;
        for (u = 0, v = b.size()-1; u<v; ) {
            int mid = (u+v)/2;
            if (a[b[mid]] > a[i]) u = mid+1;
            else v = mid;
        }
        
        if (a[i] > a[b[u]]) b[u] = i;
        len[i] = u+1;
    }
}

main() {
    int kase, i, m, maxlen;
    
    cin >> kase;
    while (kase--) {
        cin >> n;
        a.clear();
        for (i=0; i<n; i++) {
            cin >> m;
            a.push_back(m);
        }
        
        vector<int> inc(n+2), dec(n+2);
        if (!a.empty()) {
            Increase(inc);
            Decrease(dec);
        }
        
        maxlen = 0;
        for (i=0; i<n; i++)
            if (inc[i]+dec[i]-1 > maxlen)
                maxlen = inc[i]+dec[i]-1;
/*
        for (i=0; i<n; i++)
            printf(" %d", inc[i]);
        cout << endl;
        for (i=0; i<n; i++)
            printf(" %d", dec[i]);
        cout << endl;
*/
        cout << maxlen << endl;
        inc.clear(); dec.clear();
    }
}
