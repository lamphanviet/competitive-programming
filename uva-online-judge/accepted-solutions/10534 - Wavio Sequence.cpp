// UVA Problem 10534 - Wavio Sequence
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1475
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 10005

vector<int> a;
int n;

void DP(vector<int> &len, int begin, int end, int k) {
    int i, u, v;
    vector<int> b;
    b.push_back(begin); len[begin] = 1;
    
    for (i=begin+k; i!=end; i+=k) {
        if (a[i] > a[b.back()]) {
            b.push_back(i);
            len[i] = b.size();
            continue;
        }
        
        for (u=0, v=b.size()-1; u<v; ) {
            int mid = (u+v)/2;
            if (a[b[mid]] < a[i]) u = mid+1;
            else v = mid;
        }
        
        if (a[i] < a[b[u]])
            b[u] = i;
        len[i] = u+1;
    }
}

main() {
//    freopen("534.inp","r",stdin);
//    freopen("534.out","w",stdout);
    
    int i, m;
    while (cin >> n) {
        a.clear();
        for (i=0; i<n; i++) {
            cin >> m;
            a.push_back(m);
        }
        
        vector<int> inc(n+2), dec(n+2);
        DP(inc, 0, n, 1); DP(dec, n-1, -1, -1);
/*        
        for (i=0; i<n; i++)
            printf(" %d",inc[i]);
        cout << endl;
        for (i=0; i<n; i++)
            printf(" %d",dec[i]);
        cout << endl;
*/  
        int temp, maxlen = 0;
        for (i=0; i<n; i++) {
            temp = min(inc[i], dec[i]);
            if (temp > maxlen) maxlen = temp;
        }
        
        cout << maxlen*2-1 << endl;
//        inc.clear(); dec.clear();
    }
}
