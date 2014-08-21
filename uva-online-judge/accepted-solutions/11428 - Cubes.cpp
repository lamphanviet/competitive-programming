// 11428 - Cubes
#include <iostream>
#include <algorithm>

using namespace std;

int Lt3[65];

void PreCal() {
    for (int i=0;i<=60;i++)
        Lt3[i] = i*i*i;
}

main() {
    PreCal();
    int n, i, j, x, y;
    while (cin >> n && n!=0) {
        int found = 0;
        for (j=0;j<=60 && !found;j++)
            for (i=j;i<=60 && !found;i++)
                if (Lt3[i]-Lt3[j] == n) {
                    x = i; y = j;
                    found = 1;
                }
        if (found) cout << x << " " << y << endl;
        else cout << "No solution" << endl;
    }
}
