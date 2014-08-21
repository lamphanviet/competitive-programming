// 11003 - Boxes
#include <iostream>
#include <vector>

#define N 3005

using namespace std;

struct Box {
    int wei, load;
} a[N];

int n;

int FindLIS() {
    if (n==0) return 0;
    
    int i, j;
    vector<int> b;
    
    b.push_back(a[0].load);
    for (i=1; i<n; i++) {
        if (b.size() && a[i].wei <= b.back())
            b.push_back( min(a[i].load, b.back()-a[i].wei) );
            
        for (j=b.size()-2; j>=0; j--) {
            if (a[i].wei <= b[j]) {
                b[j+1] = max(b[j+1], min(a[i].load, b[j]-a[i].wei));
            }
        }
        
        if (a[i].load > b[0])
            b[0] = a[i].load;
    }
    
    return b.size();
}

main() {
    while (cin >> n && n) {
        for (int i=0; i<n; i++)
            cin >> a[i].wei >> a[i].load;
        cout << FindLIS() << endl;
    }
}
