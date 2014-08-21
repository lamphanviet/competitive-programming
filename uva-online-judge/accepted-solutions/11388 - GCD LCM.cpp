//*****************
// LAM PHAN VIET **
// UVA 11388 - GCD LCM
// Time limit: 1.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

main() {
    int Case, a, b;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &a, &b);
        if (b%a) puts("-1");
        else printf("%d %d\n", a, b);
    }
}
