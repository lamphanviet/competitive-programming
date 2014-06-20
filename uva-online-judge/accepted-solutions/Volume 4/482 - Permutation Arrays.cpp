// 482 - Permutation Arrays
#include <iostream>

using namespace std;

#define MAXN 100000

struct Num {
    int cs;
    char rs[20];
} a[MAXN];

bool cmp(Num a, Num b) {
    return (a.cs<b.cs);
}

main() {
    int kase, i, j, n, k, len;
    char str[1000000];
    cin >> kase; cin.get();
    while (kase--) {
        cin.get();
        gets(str); len = strlen(str);
        n = -1; k = 0;
        do {
            sscanf(str+k,"%d",&a[++n].cs);
            while (k<len && str[k]!=' ') k++;
            while (k<len && str[k]==' ') k++;
        } while (k<len);
        gets(str); len = strlen(str);
        n = -1; k = 0;
        do {
            sscanf(str+k,"%s",&a[++n].rs);
            while (k<len && str[k]!=' ') k++;
            while (k<len && str[k]==' ') k++;
        } while (k<len);
        sort(a,a+n+1,cmp);
        for (i=0;i<=n;i++)
            cout << a[i].rs << endl;
        if (kase) cout << endl;
    }
}
