//*****************
// LAM PHAN VIET **
// UVA 186 - Trip Routing
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 501
int n, c[maxN][maxN], Trace[maxN][maxN];
string route[maxN][maxN];
map<string, int> Index;
vector<string> name;
int namelen[maxN];
char s[80];
string name1, name2;

void Init() {
    For (i, 1, maxN-1) {
        For (j, i+1, maxN-1) {
            c[i][j] = c[j][i] = INF;
            Trace[i][j] = j;
            Trace[j][i] = i;
            route[i][j] = route[j][i] = "";
        }
        Trace[i][i] = i;
        c[i][i] = 0;
    }
    name.clear(); name.push_back("");
    Index.clear();
    n = 0;
}

bool ReadLine() {
    int len, k = 0, w, u, v;
    gets(s); len = strlen(s);
    if (len==0) return false;
    string r = "";
    name1 = name2 = "";
    while (s[k]!=',') name1 += s[k++]; k++;
    while (s[k]!=',') name2 += s[k++]; k++;
    while (s[k]!=',') r += s[k++]; k++;
    sscanf(s+k, "%d", &w);
    u = Index[name1];
    if (u==0) {
        u = Index[name1] = ++n;
        name.push_back(name1);
        namelen[n] = name[n].length();
    }
    v = Index[name2];
    if (v==0) {
        v = Index[name2] = ++n;
        name.push_back(name2);
        namelen[n] = name[n].length();
    }
    if (w<c[u][v]) {
        c[u][v] = c[v][u] = w;
        route[u][v] = route[v][u] = r;
    }
    return true;
}

void Floyd() {
    For (k, 1, n)
        For (u, 1, n)
            For (v, 1, n)
                if (c[u][v] > c[u][k] + c[k][v]) {
                    c[u][v] = c[u][k] + c[k][v];
                    Trace[u][v] = Trace[u][k];
                }
}

void PrintResult(int s, int f) {
    printf("\n\n");
    puts("From                 To                   Route      Miles");
    puts("-------------------- -------------------- ---------- -----");
    
    int u, v = s;
    do {
        cout << name[v];
        for (int i = namelen[v]; i<21; i++) printf(" ");
        u = Trace[v][f];
        cout << name[u];
        for (int i = namelen[u]; i<21; i++) printf(" ");
        cout << route[u][v];
        for (int i = route[u][v].length(); i<11; i++) printf(" ");
        printf("%5d\n", c[u][v]);
        v = u;
    } while (v!=f);
    
    puts("                                                     -----");
    printf("                                          Total      "); printf("%5d\n", c[s][f]);
}

main() {
 //   freopen("186.inp", "r", stdin); freopen("186.out", "w", stdout);
    Init();
    while (ReadLine());
    Floyd();
    while (gets(s)) {
        name1 = name2 = "";
        int len = strlen(s), k = 0, u, v;
        while (s[k]!=',')  name1 += s[k++]; k++;
        while (k<len) name2 += s[k++];
        u = Index[name1]; v = Index[name2];
        PrintResult(u, v);
    }
}

/* lamphanviet@gmail.com - 2011 */
