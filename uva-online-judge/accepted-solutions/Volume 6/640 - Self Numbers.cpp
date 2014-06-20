//----------------------------
// LAM PHAN VIET
// UVA 640 - Self Numbers
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 1000000
bool isSelf[maxN+1];

int Next(int n) {
    int next = n;
    while (n) {
        next += n%10;
        n /= 10;
    }
    return next;
}

main() {
    memset(isSelf, true, maxN+1);
    for (int i=1; i<=maxN; i++) {
        int next = Next(i);
        if (next<=maxN) isSelf[next] = false;
        if (isSelf[i]) printf("%d\n", i);
    }
}
