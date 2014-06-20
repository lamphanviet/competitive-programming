// UVA Problem 11000 - Bee
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1941
#include <iostream>

using namespace std;

int k;
long male[1000],female[1000];

void Generate(int n) {
    for (int i=k+1;i<=n;i++) {
        male[i] = female[i-1]+male[i-1];
        female[i] = male[i-1]+1;
    }
}

main() {
    k = 0;
    male[0] = 0; female[0] = 1;
    int n;
    while (cin >> n && n>=0) {
        if (n>k) Generate(n);
        cout << male[n] << " " << female[n]+male[n] << endl;
    }
}
