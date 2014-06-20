// 974 - Kaprekar Numbers
#include <iostream>
#define N 40000

using namespace std;

//int kar[100], nk;
const int nk = 19, kar[] = {9,45,55,99,297,703,999,2223,2728,4879,4950,5050,5292,7272,7777,9999,17344,22222,38962 };

int Find(int X, int u, int v) {
    while (u<v) {
        int mid = (u+v)/2;
        if (kar[mid]<X) u = mid+1;
        else v = mid;
    }
    return u;
}
/*
bool isKar(int n) {
    int part = 0, nn = n*n, hs=1;
    while (nn!=0) {
        part += (nn%10)*hs; nn/=10;
        if (part && nn && (part+nn)==n) return true;
        hs *= 10;
    }
    return false;
}

void PreCal() {
    nk = 0;
    for (int i=2; i<=N; i++)
        if (isKar(i))
            kar[nk++] = i;
}
*/
main() {
//    PreCal();
    int kk, kase, n, u, v, s, f;
    cin >> kase;
    for (kk=1; kk<=kase; kk++) {
        scanf("%d %d", &s, &f);
        u = Find(s, 0, nk);
        v = Find(f, 0, nk-1);
 //       printf("%d %d\n", u, v);
        if (f<kar[v]) v--;
 //       printf("%d %d\n", u, v);
        printf("case #%d\n", kk);
        if (u>v) printf("no kaprekar numbers\n");
        while (u<=v) {
            printf("%d\n", kar[u++]);
        }
        
        if (kk<kase) cout << endl;
    }
}
