// 11824 - A Minimum Land Price
#include <iostream>

using namespace std;

#define MAX 5000000
#define Max 2500000

int n,a[50];

int pow(int x, int k) {
    int rs=1;
    for (int i=1;i<=k;i++) {
        rs *= x;
        if (rs>Max) return rs;
    }
    return rs;
}

void Sort() {
    int i,j,temp;
    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++)
            if (a[i]<a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void Enter() {
    int temp;
    n = 0;
    while (cin >> temp && temp!=0 && n<39) {
        a[++n] = temp;
    }
}

int Run() {
    int i,sum;
    sum = 0;
    for (i=1;i<=n;i++) {
        sum += 2*pow(a[i],i);
        if (sum > MAX) return -1;
    }
    return sum;
}

main() {
 //   freopen("g.inp","r",stdin);
 //   freopen("g.out","w",stdout);
    int kase;
    cin >> kase;
    while (kase--) {
        Enter();
        Sort();
        int rs = Run();
        if (rs<0) cout << "Too expensive";
        else cout << rs;
        cout << endl;
    }
}
