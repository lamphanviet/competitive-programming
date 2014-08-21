//----------------------------
// LAM PHAN VIET
// UVA 11926 - Multitasking
// Time limit: 1s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
using namespace std;

#define maxN 1000000
bool Free[maxN], ok;

void Check(int u, int v) {
    while (ok && u<v && u<maxN)
        if (Free[u]) Free[u++] = false;
        else ok = false;
}

main() {
    int n, m, u, v, interval;
    while (scanf("%d %d", &n, &m)) {
        if (!n && !m) break;
        memset(Free, true, maxN);
        ok = true;
        while (n--) {
            scanf("%d %d", &u, &v);
            if (ok) Check(u, v);
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &interval);
            while (ok && u<maxN) {
                if (ok) Check(u, v);
                u += interval;
                v += interval;
            }
        }
        if (ok) printf("NO ");
        printf("CONFLICT\n");
    }
}
