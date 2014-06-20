// 10327 - Flip Sort
#include <iostream>

using namespace std;

int dem, n, a[1005], b[1005];

void Merge(int x[], int y[], int a, int b, int c) {
    int i, j, p;
    i = p = a; j = b+1;
    while (i<=b && j<=c) {
        if (x[i]<=x[j]) y[p] = x[i++];
        else {
            dem += j-p;
            y[p] = x[j++];
        }
        p++;
    }
    if (i<=b) for (; i<=b; i++) y[p++] = x[i];
    else for (; j<=c; j++) y[p++] = x[j];
}

void MergeByLength(int x[], int y[], int len) {
    int a, b, c;
    a = 1; b = len; c = len + len;
    while (c<=n) {
        Merge(x, y, a, b, c);
        a += len+len; b += len+len; c += len+len;
    }
    if (b<=n) Merge(x, y, a, b, n);
    else if (a<=n) for (; a<=n; a++) y[a] = x[a];
}

void MergeSort(int x[], int y[]) {
    bool Flag = true;
    int len = 1;
    while (len<n) {
        if (Flag) MergeByLength(x, y, len);
        else MergeByLength(y, x, len);
        Flag=!Flag;
        len += len;
    }
}

main() {
    while (cin >> n) {
        for (int i=1; i<=n; i++)
            cin >> a[i];
        dem = 0;
        MergeSort(a, b);
        printf("Minimum exchange operations : %d\n", dem);
    }
}
