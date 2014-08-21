//*****************
// LAM PHAN VIET **
// UVA 10603 - Fill
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 1000000
#define maxN 500000
class Status {
public:
    int a, b, c;
    Status() { a=b=c=0; }
    Status(int x, int y, int z) {
        a = x; b = y; c = z;
    }
    bool Have(int x) {
        return (a==x || b==x || c==x);
    }
    int Val(int K) {
        int u = 0;
        if (u<a && a<K) u = a;
        if (u<b && b<K) u = b;
        if (u<c && c<K) u = c;
        return u;
    }
};
struct classcomp {
    bool operator() (Status X, Status Y) const {
        if (X.a<Y.a) return true;
        if (X.a==Y.a) return (X.b<Y.b || (X.b==Y.b && X.c<Y.c));
        return false;
    }
};
int n, ans, tmpmax, A, B, C, K;
vector<Status> SList;
vector<int> d;
vector<bool> Free;
map<Status, int, classcomp> Index;

void Init(int c) {
    Status First(0, 0, c);
    SList.clear();
    SList.push_back(Status());  // [0] don't use
    SList.push_back(First);
    d.clear();
    d.push_back(INF);           // [0] don't use
    d.push_back(0);             // [1] 0
    Free.clear();
    Free.push_back(false);
    Free.push_back(true);
    Index.clear();
    n = 1;
    Index[First] = n;
    ans = INF; tmpmax = 0;
}

int GetIndex(Status s) {
    int u = Index[s];
    if (u!=0) return u;
    u = Index[s] = ++n;
    SList.push_back(s);
    d.push_back(INF);
    Free.push_back(true);
    return u;
}

void Dijkstra() {
    int u, v, tmpmin, a, b, c, cost;
    while (1) {
        u = 0; tmpmin = INF;
        For (i, 1, n)
            if (Free[i] && d[i]<tmpmin) {
                u = i; tmpmin = d[i];
            }
        if (u==0) return;
        Free[u] = false;
        if (SList[u].Have(K)) {
            tmpmax = K; ans = d[u]; 
            return;
        }
        else {
            int x = SList[u].Val(K);
            if (x>tmpmax || (x==tmpmax && d[u]<ans)) {
                tmpmax = x;
                ans = d[u];
            }
        }
        
        a = SList[u].a; b = SList[u].b; c = SList[u].c;
        if (a) {
            cost = min(a, B-b);
            a -= cost; b += cost;
            v = GetIndex(Status(a, b, c));
            if (Free[v] && d[u]+cost < d[v]) d[v] = d[u] + cost;
            
            a = SList[u].a; b = SList[u].b; c = SList[u].c;
            cost = min(a, C-c);
            a -= cost; c += cost;
            v = GetIndex(Status(a, b, c));
            if (Free[v] && d[u]+cost < d[v]) d[v] = d[u] + cost;
        }
        a = SList[u].a; b = SList[u].b; c = SList[u].c;
        if (b) {
            cost = min(b, A-a);
            b -= cost; a += cost;
            v = GetIndex(Status(a, b, c));
            if (Free[v] && d[u]+cost < d[v]) d[v] = d[u] + cost;
            
            a = SList[u].a; b = SList[u].b;
            cost = min(b, C-c);
            b -= cost; c += cost;
            v = GetIndex(Status(a, b, c));
            if (Free[v] && d[u]+cost < d[v]) d[v] = d[u] + cost;
        }
        a = SList[u].a; b = SList[u].b; c = SList[u].c;
        if (c) {
            cost = min(c, A-a);
            c -= cost; a += cost;
            v = GetIndex(Status(a, b, c));
            if (Free[v] && d[u]+cost < d[v]) d[v] = d[u] + cost;
            
            a = SList[u].a; b = SList[u].b; c = SList[u].c;
            cost = min(c, B-b);
            c -= cost; b += cost;
            v = GetIndex(Status(a, b, c));
            if (Free[v] && d[u]+cost < d[v]) d[v] = d[u] + cost;
        }
    }
}

main() {
//    freopen("603.inp", "r", stdin); freopen("603.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d %d %d", &A, &B, &C, &K);
        Init(C);
        Dijkstra();
        printf("%d %d\n", ans, tmpmax);
    }
}

/* lamphanviet@gmail.com - 2011 */
