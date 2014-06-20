// 750 - 8 Queens Chess Problem
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

bool topleft[17], topright[17], hor[10];
int ans[10], fx, fy, sol;

void Print() {
    printf("%2d     ", ++sol);
    for (int i=1; i<=8; i++)
        printf(" %d", ans[i]);
    cout << endl;
}

void Barrack(int row) {
    if (row == fx) {
        Barrack(row+1);
        return;
    }
    
    if (row>8) {
        Print();
        return;
    }
    
    for (int col=1; col<=8; col++) {
        if (topleft[row+col] && topright[col-row+8] && hor[col]) {
            ans[row] = col;
            topleft[row+col] = topright[col-row+8] = hor[col] = false;
            Barrack(row+1);
            topleft[row+col] = topright[col-row+8] = hor[col] = true;
        }
    }
}

main() {
//    freopen("out.out", "w", stdout);
    int kase;
    cin >> kase;
    while (kase--) {
        cin >> fy >> fx;
        memset(topleft, true, 17);
        memset(topright, true, 17);
        memset(hor, true, 10);
        topleft[fx+fy] = topright[fy-fx+8] = hor[fy] = false;
        ans[fx] = fy; sol = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        Barrack(1);
        if (kase) cout << endl;
    }
}
