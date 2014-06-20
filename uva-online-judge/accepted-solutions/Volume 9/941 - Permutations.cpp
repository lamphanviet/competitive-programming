// 941 - Permutations
#include <iostream>

using namespace std;

char s[22];
bool Free[22];
int len;
long long GT[22], n;

void GiaiThua() {
    GT[0] = 1;
    for (int i=1;i<=19;i++)
        GT[i] = GT[i-1]*i;
}

int VT(int m) {
    int i, k = 0;
    for (i=0;i<len;i++)
        if (Free[i]) {
            k++;
            if (k==m) return i;
        }
}

void Found() {
    int p, k, m = len;
    while (m) {
        double temp = (double)n/GT[m-1];
        if (temp > n/GT[m-1]) p = (int)temp+1;
        else p = (int)temp;
        k = VT(p);
 //       cout << k << endl;
        printf("%c",s[k]);
        Free[k] = false;
        n %= GT[m-1];
        if (n==0) n = GT[m-1];
        m--;
    }
    cout << endl;
}

main() {
//    freopen("941.inp","r",stdin);
//    freopen("941.out","w",stdout);
    GiaiThua();
    int kase, i, j;
    cin >> kase;
    while (kase--) {
        cin.get(); gets(s);
        scanf("%lld",&n); len = strlen(s);
        n++;
        memset(Free,true,len+1);
        sort(s,s+len);
  //      puts(s);
        Found();
    }
}
