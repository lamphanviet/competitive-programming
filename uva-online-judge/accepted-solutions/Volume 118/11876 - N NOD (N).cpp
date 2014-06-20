//----------------------------
// LAM PHAN VIET
// UVA 11876 - N + NOD (N)
// Time limit: 2s
//----------------------------
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAXN 64725

using namespace std;

int N[MAXN+10];
int ans[1000005];
bool Exist[1000005];

//map <int , int> Exist;

int Nod(int x) {
    int i, limit, sum = 0;
    for (i = 2, limit = (int)sqrt(x); i <= limit; i++)
        if (x%i==0) sum++;
    sum *= 2;
    if (limit-sqrt(x)==0) sum--;
    return sum+2;
}

void PreCal() {
    N[0] = 1; N[1] = 2;
    memset(Exist,false,1000005);
    Exist[1] = true; Exist[2] = true;
    for (int i = 2; i <= MAXN; i++) {
        N[i] = N[i-1] + Nod(N[i-1]);
        Exist[N[i]] = true;
    }
}

int Result() {
    int k, i;
    ans[0] = 0; k = 0;
    for (i = 1; i <= 1000000; i++) {
        ans[i] = ans[i-1];
        if (i >= N[k]) {
            ans[i]++;
            k++;
        }
    }
}

main() {
    PreCal();
    Result();
    int kase, k, a, b, rs;
    cin >> kase;
    for (k = 1; k <= kase; k++) {
        cin >> a >> b;
        rs = ans[b]-ans[a];
        if (Exist[a]) rs++;
        printf("Case %d: %d\n", k, rs);
        
    }
}
