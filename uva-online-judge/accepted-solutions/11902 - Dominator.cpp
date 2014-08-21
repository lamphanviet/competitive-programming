//----------------------------
// LAM PHAN VIET
// UVA 11902 - Dominator
// Time limit: 2s
//----------------------------
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define maxN 105
int n;
vector <int> ke[maxN];
bool First[maxN], other[maxN], result[maxN][maxN];

void BFS(int x, bool *Free) {
    int Queue[maxN], front, rear;
    front = rear = 1;
    Queue[front] = 0;
    Free[0] = false;
    while (front<=rear) {
        int u = Queue[front++];
        for (int i=0; i<ke[u].size(); i++) {
            int v = ke[u][i];
            if (v!=x && Free[v]) {
                Free[v] = false;
                Queue[++rear] = v;
            }
        }
    }
}

void PrintResult() {
    printf("+");
    for (int i=1; i<n; i++) printf("--");
    printf("-+\n");
    for (int i=0; i<n; i++) {
        printf("|");
        for (int j=0; j<n; j++) {
            if (result[i][j]) printf("Y");
            else printf("N");
            printf("|");
        }
        printf("\n+");
        for (int j=1; j<n; j++) printf("--");
        printf("-+\n");
    }
}

main() {
//    freopen("902.inp", "r", stdin); freopen("902.out", "w", stdout);
    int kase;
    scanf("%d", &kase);
    for (int kk=1; kk<=kase; kk++) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            ke[i].clear();
            for (int j=0, k; j<n; j++) {
                scanf("%d", &k);
                if (k) ke[i].push_back(j);
            }
            First[i] = true;
        }
        BFS(-1, First);
        for (int j=0; j<n; j++)
            result[0][j] = !First[j];
        for (int i=1; i<n; i++) {
            memset(other, true, n+1);
            BFS(i, other);
            for (int j=0; j<n; j++)
                if (!First[j] && other[j])
                    result[i][j] = true;
                else result[i][j] = false;
            if (!First[i]) result[i][i] = true;
            else result[i][i] = false;
        }
        printf("Case %d:\n", kk);
        PrintResult();
    }
}
