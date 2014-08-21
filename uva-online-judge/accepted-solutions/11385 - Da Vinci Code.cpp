// // 11385 - Da Vinci Code----VIET
#include <iostream>
#include <map>

using namespace std;

int F[50];
map <int, int> Stt;

void PreCal() {
    F[0] = 1; Stt[1] = 0;
    F[1] = 2; Stt[2] = 1;
    for (int i=2;i<=45;i++) {
        F[i] = F[i-1] + F[i-2];
        Stt[F[i]] = i;
    }
}

main() {
    PreCal();
//    freopen("A.INP", "r", stdin);
//    freopen("A.OUT", "w", stdout);
    int kase, i;
    int len, n, k, a[105];
    char str[105], ans[105];
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=0;i<n;i++) cin >> a[i];
        cin.get();
        gets(str); len = strlen(str);
        
        memset(ans,' ', sizeof (ans));
        k = 0;
        for (i=0;i<len && k<n;i++)
            if (isupper(str[i]))
                ans[Stt[a[k++]]] = str[i];
                
        k = 104;
        while (ans[k]==' ') k--;
        ans[k+1] = '\0';
        puts(ans);
    }
}
