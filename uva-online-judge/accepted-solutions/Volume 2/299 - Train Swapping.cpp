// UVA Problem 299 - Train Swapping
// Link:
#include <iostream>

using namespace std;

int a[55],b[55];
int dem,n;

void Merge(int x[], int y[], int a, int b, int c) {
    int i,j,p;
    p=a; i=a; j=b+1;
    while (i<=b && j<=c) {
        if (x[i]<=x[j]) {
            y[p] = x[i]; i++;
        }
        else {
            y[p] = x[j];
            dem += j-p;
            j++;
        }
        p++;
    }
    if (i<=b)   for (;i<=b;i++) y[p++] = x[i];
    else    for (;j<=c;j++) y[p++] = x[j];
}

void MergeByLength(int x[], int y[], int len) {
    int a,b,c;
    a=1; b=len; c=2*len;
    while (c<=n) {
        Merge(x,y,a,b,c);
        a+=2*len; b+=2*len; c+=2*len;
    }
    if (b<n) Merge(x,y,a,b,n);
    else if (a<=n) {
        for (;a<=n;a++) y[a] = x[a];
    }
}

void MergeSort() {
    double Flag = true;
    int len = 1;
    while (len<n) {
        if (Flag) MergeByLength(a,b,len);
        else MergeByLength(b,a,len);
        len*=2; Flag=!Flag;
    }
}

main() {
    int kase, i;
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=1;i<=n;i++)
            cin >> a[i];
        dem = 0;
        MergeSort();
        printf("Optimal train swapping takes %d swaps.\n",dem);
    }
}
