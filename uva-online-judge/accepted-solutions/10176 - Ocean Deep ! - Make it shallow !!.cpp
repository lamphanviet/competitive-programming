/*****************
// LAM PHAN VIET **
// UVA 10176 - Ocean Deep ! - Make it shallow !!
// Time limit: 3.000s
//********************************/
#include <stdio.h>
#include <string.h>

#define maxN 105

const int prime = 131071;
char s[maxN];

int main() {
    while (gets(s)) {
        int remainder = 0;
        bool stop = false;
        do {
            int n = strlen(s), i;
            for (i = 0; i < n; i++)
                if (s[i] == '#') {
                    stop = true;
                    break;
                }
                else {
                    remainder = remainder << 1;
                    remainder += (int)(s[i] - 48);
                    remainder %= prime;
                }
            if (!stop) gets(s);
        } while (!stop);
        if (remainder) puts("NO");
        else puts("YES");
    }
    return 0;
}

/* lamphanviet@gmail.com - 2011 */
