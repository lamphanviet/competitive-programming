//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11783 - Nails
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1011

struct Sticks {
    int x1,y1,x2,y2;
} a[maxN];

int n,rs;
bool Free[maxN];

void Enter() {
    for (int i=1;i<=n;i++)
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    memset(Free,true,n+5);
}

long Side(int x, int y, int x1, int y1, int x2, int y2) {
    return ((y-y1)*(x2-x1)-(x-x1)*(y2-y1));
}

void Count() {
    rs=0;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            long si1,si2,sj1,sj2;
            si1=Side(a[i].x1,a[i].y1,a[j].x1,a[j].y1,a[j].x2,a[j].y2);
            si2=Side(a[i].x2,a[i].y2,a[j].x1,a[j].y1,a[j].x2,a[j].y2);
            sj1=Side(a[j].x1,a[j].y1,a[i].x1,a[i].y1,a[i].x2,a[i].y2);
            sj2=Side(a[j].x2,a[j].y2,a[i].x1,a[i].y1,a[i].x2,a[i].y2);
            long ti,tj;
            ti=si1*si2; tj=sj1*sj2;
            if ((ti<=0 && tj<=0)) {
                rs++;
                Free[i]=Free[j]=false;
      //          printf("%d %d yes\n",i,j);
            }
     //       else printf("%d %d not\n",i,j);
        }
        if (Free[i]) rs+=2;
    }
}

main() {
//    freopen("783inp.txt","r",stdin);
//    freopen("783out.txt","w",stdout);
    scanf("%d",&n);
    while (n!=0) {
        Enter(); Count();
        printf("%d\n",rs);
        scanf("%d",&n);
    }
}
