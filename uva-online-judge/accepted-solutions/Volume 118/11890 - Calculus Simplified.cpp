// 11890 - Calculus Simplified
#include <iostream>

using namespace std;

#define N 100000

int n, len, a[60000], tru;
char s[N+5], line[10];

int Barrack(int i, int sign) {
    int tmpsign;
    while (i<len) {
        if (s[i]==')') return i+1;
        else if (s[i]=='x') {
            if (i==0 || s[i-1]=='+' || s[i-1]=='(') tmpsign = sign;
            else tmpsign = -sign;
            if (tmpsign<0) tru++;
            i++;
        }
        else if (s[i]=='(') {
            if (i==0 || s[i-1]=='(' || s[i-1]=='+') tmpsign = sign;
            else tmpsign = -sign;
            i = Barrack(i+1, tmpsign);
        }
        else i++;
    }
}

main() {
    int kase, i;
    scanf("%d", &kase);
    while (kase--) {
        gets(line);
        gets(s); len = strlen(s);
        scanf("%d", &n);
        for (i=0; i<n; i++)
            scanf("%d", &a[i]);
        tru = 0;
        Barrack(0, 1);
        sort(a, a+n);
//        printf("cong %d; tru %d\n", cong, tru);
        int sum = 0;
        for (i=0; i<tru; i++) sum -= a[i];
        for (; i<n; i++) sum += a[i];
        
        printf("%d\n", sum);
    }
}
