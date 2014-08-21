// UVA Problem 11733 - Airports
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2833
#include <iostream>

using namespace std;

#define MAXN 10005
#define MAXM 100005

struct Canh {
    int u,v,cost;
} canh[MAXM];

int n,m, Lab[MAXN];
int numAp,CostAp,mincost;

void Init() {
    for (int i=1;i<=n;i++) {
        Lab[i] = -1;
    }
}

void Enter() {
    int i,k,u,v, cost;
    cin >> n >> k >> CostAp;
    Init();
    m = 0;
    for (i=1;i<=k;i++) {
        cin >> u >> v >> cost;
        if (cost<CostAp) {
            canh[++m].u = u; canh[m].v = v; canh[m].cost = cost;
        }
    }
}

int GetRoot(int v) {
    while (Lab[v]>0) v = Lab[v];
    return v;
}

void Union(int r1, int r2) {
    int x = Lab[r1]+Lab[r2];
    if (Lab[r1]>Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}

void QuickSort(int L, int H) {
    if (L>=H) return;
    
    int i,j,pivot;
    i = L; j = H; pivot = canh[(L+H)/2].cost;
    do {
        while (canh[i].cost<pivot) i++;
        while (canh[j].cost>pivot) j--;
        if (i<=j) {
            if (i<j) {
                Canh temp=canh[i]; canh[i]=canh[j]; canh[j]=temp;
            }
            i++; j--;
        }
    } while (i<=j);
    QuickSort(L,j); QuickSort(i,H);
}

void Kruscal() {
    int k,r1,r2, dem;
    
    mincost = dem = 0;
    for (k=1;k<=m;k++) {
        r1 = GetRoot(canh[k].u); r2 = GetRoot(canh[k].v);
        if (r1!=r2) {
            Union(r1,r2);
 //           printf("%d %d\n",canh[k].u,canh[k].v);
            mincost += canh[k].cost;
            dem++;
            if (dem==n-1) break;
        }
    }
    numAp = 0;
    for (k=1;k<=n;k++)
        if (Lab[k]<0) {
            mincost += CostAp;
            numAp++;
        }
}

main() {
//    freopen("733.inp","r",stdin);
//    freopen("733.out","w",stdout);
    int k,kase;
    cin >> kase;
    for (k=1;k<=kase;k++) {
        Enter();
        QuickSort(1,m);
        Kruscal();
        printf("Case #%d: %d %d\n",k,mincost,numAp);
    }
}
