//*****************
// LAM PHAN VIET **
// UVA 11056 - Formula 1
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 101
struct Pilot {
    string name;
    int time;
};
int n;
vector<Pilot> p;

bool cmp(Pilot a, Pilot b) {
    if (a.time<b.time) return true;
    if (a.time==b.time) {
        int n = min(a.name.length(), b.name.length());
        For (i, 0, n) {
            char x = tolower(a.name[i]), y = tolower(b.name[i]);
            if (x<y) return true;
            else if (x>y) return false;
        }
        return (a.name.length() == n);
    }
    return false;
}

void ReadInput() {
    int m, s, ms;
    char a[10];
    p.resize(n);
    getchar();
    For (i, 0, n-1) {
        cin >> p[i].name;
        scanf("%s %d %s %d %s %d %s", &a, &m, &a, &s, &a, &ms, &a);
        p[i].time = ms + 1000*s + 60000*m;
    }
}

main() {
//    freopen("056.inp", "r", stdin); freopen("056.out", "w", stdout);
    while (scanf("%d", &n)!=EOF) {
        ReadInput();
        sort(p.begin(), p.end(), cmp);
        For (i, 0, n-1) {
            if (i%2==0) printf("Row %d\n", i/2 + 1);
            cout << p[i].name << endl;
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
