// 10926 - How Many Dependencies?
#include <iostream>
#include <vector>
#include <queue>
#define N 105

using namespace std;

int n;
bool Free[N];
vector <int> a[N];

int BFS(int u) {
    queue <int> Q;
    Q.push(u); Free[u] = false;
    int i, v, dem = 0;
    while (!Q.empty()) {
        u = Q.front();
        for (i=0; i<a[u].size(); i++) {
            v = a[u][i];
            if (Free[v]) {
                Q.push(v);
                dem++;
                Free[v] = false;
            }
        }
        Q.pop();
    }
    return dem;
}

main() {
    int i, t, m;
    while (scanf("%d", &n) && n) {
        for (i=1; i<=n; i++) {
            a[i].clear();
            scanf("%d", &t);
            while (t--) {
                scanf("%d", &m);
                a[i].push_back(m);
            }
        }
        int u, ans, temp;
        ans = -1; u = -1;
        for (i=1; i<=n; i++) {
            memset(Free, true, n+2);
            temp = BFS(i);
            if (temp>ans) {
                ans = temp; u = i;
            }
        }
        
        printf("%d\n", u);
    }
}
