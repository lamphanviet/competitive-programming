// UVA Problem 908 - Re-connecting Computer Sites
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=849
#include <iostream>

using namespace std;

#define MAXN 1000005

struct Line {
    int u,v,w;
} a[MAXN];

int n,m1,m2,first,neww;
int Lab[MAXN];

void Enter() {
    first = 0; neww = 0;
    int i,x,y,w;
    for (i=1;i<n;i++) {
        cin >> x >> y >> w;
    }
    cin >> m1;
    for (i=1;i<=m1;i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    cin >> m2;
    m2+=m1;
    for (;i<=m2;i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
}

void Init() {
    for (int i=1;i<=n;i++)
        Lab[i] = -1;
}

void QuickSort(int L, int H) {
    if (L>=H) return;
    
    int i,j,pivot;
    i = L; j = H; pivot = a[(L+H)/2].w;
    do {
        while (a[i].w<pivot) i++;
        while (a[j].w>pivot) j--;
        if (i<=j) {
            if (i<j) {
                Line temp=a[i]; a[i]=a[j]; a[j]=temp;
            }
            i++; j--;
        }
    } while (i<=j);
    QuickSort(L,j); QuickSort(i,H);
}

/*-------------Kruscal-------------*/

int GetRoot(int v) {
    while (Lab[v]>0) v=Lab[v];
    return v;
}

void Union(int r1, int r2) {
    int x = Lab[r1]+Lab[r2];
    if (Lab[r1]>Lab[r2]) {
        Lab[r1] =r2;
        Lab[r2] =x;
    }
    else {
        Lab[r1] =x;
        Lab[r2] =r1;
    }
}

void Kruscal(int p, int q, int k) {
    int i,r1,r2,dem,sum;
    dem = sum = 0;
    Init();
    for (i=p;i<=q;i++) {
        r1 = GetRoot(a[i].u); r2 = GetRoot(a[i].v);
        if (r1!=r2) {
            dem++;
    //        printf("canh %d %d %d\n",a[i].u,a[i].v,a[i].w);
            sum += a[i].w;
            if (dem==n-1) break;
            Union(r1,r2);
        }
    }
    if (k) first = sum;
    else neww = sum;
}

void Print() {
    for (int i=1;i<=m2;i++)
        printf("canh %d %d %d\n",a[i].u,a[i].v,a[i].w);
}

main() {
//    freopen("908.inp","r",stdin);
//    freopen("908.out","w",stdout);
    bool End = false;
    while (cin >> n) {
        if (End) cout << endl;
        End = true;
        Enter();
        
        QuickSort(m1+1,m2); Kruscal(m1+1,m2,1);
 //       Print();
        cout << first << endl;
        
        QuickSort(1,m2); Kruscal(1,m2,0);
 //       Print();
        cout << neww << endl;
    }
}
