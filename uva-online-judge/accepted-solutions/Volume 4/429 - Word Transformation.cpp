//----------------------------
// LAM PHAN VIET
// UVA 429 - Word Transformation
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

#define maxN 205
int n;
bool cnt[maxN][maxN];
string word[maxN];
map <string, int> wIndex;

bool isCnt(string a, string b) {
    if (a.length()!=b.length()) return false;
    int dif=0;
    for (int i=0, sizes=a.length(); i<sizes; i++)
        if (a[i]!=b[i]) {
            dif++;
            if (dif>1) return false;
        }
    return true;
}

void Convert() {
    for (int i=0; i<n; i++) {
        cnt[i][i] = true;
        for (int j=i+1; j<n; j++)
            cnt[i][j] = cnt[j][i] = isCnt(word[i], word[j]);
    }
}

int BFS(int s, int f) {
    if (s==f) return 0;
    int Level[n];
    queue<int> Queue;
    for (int i=0; i<n; i++)
        Level[i] = 0;
    Queue.push(s);
    Level[s] = 1;
    while (!Queue.empty()) {
        int u = Queue.front();
        Queue.pop();
        for (int v=0; v<n; v++)
            if (Level[v]==0 && cnt[u][v]) {
                if (v==f) return Level[u];
                Level[v] = Level[u]+1;
                Queue.push(v);
            }
    }
}

main() {
//    freopen("429.inp", "r", stdin); freopen("429.out", "w", stdout);
    int Case;
    string tmp, a, b;
    scanf("%d", &Case);
    while (Case--) {
        wIndex.clear();
        n = 0;
        while (1) {
            cin >> word[n];
            if (word[n]=="*") break;
            wIndex[word[n]] = n;
            n++;
        }
        Convert();
        getline(cin, tmp);
        while (getline(cin, tmp)) {
            if (tmp=="") break;
            for (int i=0, sizet=tmp.length(); i<sizet; i++)
                if (tmp[i]==' ') {
                    a = tmp.substr(0, i);
                    b = tmp.substr(i+1, sizet);
                    break;
                }
            cout << tmp << " " << BFS(wIndex[a], wIndex[b]) << endl;
        }
        if (Case) printf("\n");
    }
}
