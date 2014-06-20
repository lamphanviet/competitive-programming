// 612 - DNA Sorting
#include <iostream>

using namespace std;

struct Line {
    char str[55];
    int nswap;
} line[105];

int n, dem;
char temp1[55], temp2[55];

void Merge(char x[], char y[], int a, int b, int c) {
    int i,j,p;
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

void MergeByLength(char x[], char y[], int len) {
    int a, b, c;
    a = 0; b = len-1; c = len+len-1;
    while (c<n) {
        Merge(x,y,a,b,c);
        a += 2*len; b += 2*len; c += 2*len;
    }
    if (b<n-1) Merge(x,y,a,b,n-1);
    else if (a<n) for(;a<n;a++) y[a] = x[a];
}

void MergeSort(char x[], char y[]) {
    int len = 1;
    bool Flag = true;
    while (len<n) {
        if (Flag) MergeByLength(x,y,len);
        else MergeByLength(y,x,len);
        len += len; Flag = !Flag;
    }
}

bool cmp(Line a, Line b) {
    return (a.nswap<b.nswap);
}

main() {
//    freopen("612.inp","r",stdin);
//    freopen("612.out","w",stdout);
    
    int kase, i, m;
    cin >> kase;
    while (kase--) {
        cin >> n >> m;
        cin.get();
        for (i=1;i<=m;i++) {
            gets(line[i].str);
            dem = 0;
            strcpy(temp1,line[i].str);
            MergeSort(temp1, temp2);
            line[i].nswap = dem;
        }
        stable_sort(line+1,line+m+1,cmp);
        for (i=1;i<=m;i++)
            puts(line[i].str);
        if (kase) cout << endl;
    }
}
