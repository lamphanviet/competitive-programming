// 11878 Homework Checker
#include <iostream>
#include <string.h>

using namespace std;

main() {
    int a, b, c, dem, dau, i, n;
    dem = 0;
    char s[1000];
    while (gets(s)) {
        n = strlen(s);
        if (s[n-1]=='?') continue;
        sscanf(s, "%d", &a);
        i = 0;
        while (isdigit(s[i])) i++;
        dau = 1;
        if (s[i]=='-') dau=-1;
        i++;
        sscanf(s+i, "%d", &b);
        while (isdigit(s[i])) i++;
        i++;
        sscanf(s+i, "%d", &c);
        if (a+dau*b == c) dem++;
  //      printf("%d %d %d %d\n", a, b, c, dau);
    }
    cout << dem << endl;
}
