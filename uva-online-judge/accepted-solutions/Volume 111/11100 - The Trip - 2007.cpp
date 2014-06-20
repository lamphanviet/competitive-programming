#include <iostream>

using namespace std;

#define MAXN 10005

int a[MAXN], n, nTT;
int ans[MAXN][MAXN];

void Run() {
    int i, j , k;
    int maxlen, templen;
    
    maxlen = 0; a[n] = -1;
    
    templen = 1;
    for (i=1;i<=n;i++)
        if (a[i]!=a[i-1]) {
            if (templen>maxlen) maxlen = templen;
            templen = 1;
        }
        else templen++;

    cout << maxlen << endl;
    for (i=0; i<maxlen; i++) {
        cout << a[i];
        for (j=i+maxlen; j<n; j+=maxlen)
            printf(" %d",a[j]);
        cout << endl;
    }
    
}

main() {
//    freopen("100.inp","r",stdin);
//    freopen("100.out","w",stdout);
    int i;
    bool End = false;
    while (cin >> n && n!=0) {
        if (End) cout << endl;
        End = true;
        for (i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        Run();
    }
}
