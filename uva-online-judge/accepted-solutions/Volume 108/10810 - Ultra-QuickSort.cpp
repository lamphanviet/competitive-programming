// 10810 - Ultra-QuickSort
#include <iostream>

using namespace std;

#define MAXN 500005

int a[MAXN], b[MAXN], n;
long dem;

void Merge(int x[], int y[], int a, int b, int c) {
    int i, j, p;
    p = i = a; j = b+1;
    while (i<=b && j<=c) {
        if (x[i]<=x[j]) y[p] = x[i++];
        else {
            dem += j-p;
            y[p] = x[j++];
        }
        p++;
    }
    if (i<=b) for (;i<=b;i++) y[p++] = x[i];
    else for (;j<=c;j++) y[p++] = x[j];
}

void MergeByLength(int x[], int y[], int len) {
    int a, b, c;
    a = 1; b = len; c = len+len;
    while (c<=n) {
        Merge(x,y,a,b,c);
        a += 2*len; b+= 2*len; c += 2*len;
    }
    if (b<n) Merge(x,y,a,b,n);
    else if (a<=n) {
        for (;a<=n;a++)
            y[a] = x[a];
    }
}

void MergeSort() {
    int len = 1, i;
    bool Flag = true;
    while (len<n) {
        if (Flag) MergeByLength(a,b,len);
        else MergeByLength(b,a,len);
        len += len;
        Flag = !Flag;
    }
}

main() {
    while (cin >> n && n) {
        for (int i=1;i<=n;i++)
            cin >> a[i];
        dem = 0;
        MergeSort();
        cout << dem << endl;
    }
}
