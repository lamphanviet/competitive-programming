// 11870 - Antonyms
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Connect {
    vector<int> snym;
    vector<int> anym;
} word[3000];

map <string, int> Stt;
int n, Color[3000];

bool ans;

void DFS(int u, int cl) {
    if (!ans) return;
    
    if (Color[u]!=0) {
        if (Color[u]!=cl)
            ans = false;
        return;
    }
    
    Color[u] = cl;
    int i, v;
    for (i=0; i<word[u].snym.size(); i++) {
        v = word[u].snym[i];
        DFS(v,cl);
    }
    
    for (i=0; i<word[u].anym.size(); i++) {
        v = word[u].anym[i];
        DFS(v,-cl);
    }
}

main() {
//    freopen("cc.inp","r",stdin);
//    freopen("cc.out","w",stdout);
    
    int kase, k, a, b, i, u, v;
    string s1, s2;
    cin >> kase;
    for (k=1; k<=kase; k++) {
        n = 0;
        cin >> a >> b; cin.get();
        for (i=1;i<=a;i++) {
            cin >> s1 >> s2;
            if (!Stt[s1]) Stt[s1] = ++n;
            if (!Stt[s2]) Stt[s2] = ++n;
            u = Stt[s1]; v = Stt[s2];
            word[u].snym.push_back(v);
            word[v].snym.push_back(u);
        }
        for (i=1;i<=b;i++) {
            cin >> s1 >> s2;
            if (!Stt[s1]) Stt[s1] = ++n;
            if (!Stt[s2]) Stt[s2] = ++n;
            u = Stt[s1]; v = Stt[s2];
            word[u].anym.push_back(v);
            word[v].anym.push_back(u);
        }
        
        for (i=1;i<=n;i++)
            Color[i] = 0;

        ans = true;
        for (i=1;i<=n && ans;i++) {
            if (Color[i]==0) DFS(i,1);
        }
        
        printf("Case %d: ",k);
        if (ans) printf("YES");
        else printf("NO");
        printf("\n");
        
        for (i=1;i<=n;i++) {
            word[i].snym.clear();
            word[i].anym.clear();
        }
        Stt.clear();
    }
}
