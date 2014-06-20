//*****************
// LAM PHAN VIET **
// UVA 10258 - Contest Scoreboard
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 101
class Team {
public:
    int num, pro, time;
    Team() {};
    Team(int n, int p, int t) {
        num = n; pro = p; time = t;
    }
};
int Count[maxN][10], Time[maxN];
bool Exist[maxN];

bool cmp(Team a, Team b) {
    if (a.pro>b.pro) return true;
    if (a.pro==b.pro) {
        if (a.time<b.time) return true;
        else if (a.time==b.time && a.num<b.num) return true;
    }
    return false;
}

void Init() {
    For (i, 1, maxN-1) {
        Time[i] = 0;
        Exist[i] = false;
        For (j, 1, 9) Count[i][j] = 0;
    }
}

main() {
  //  freopen("258.inp", "r", stdin); freopen("258.out", "w", stdout);
    int Case, num, pro, t;
    char s[50], rs;
    scanf("%d", &Case); getchar(); getchar();
    while (Case--) {
        Init();
        while (gets(s) && strlen(s)) {
            sscanf(s, "%d %d %d %c", &num, &pro, &t, &rs);
            Exist[num] = true;
            if (Count[num][pro]==-1) continue;
            if (rs=='C') {
                Time[num] += Count[num][pro]*20 + t;
                Count[num][pro] = -1;
            }
            else if (rs=='I') Count[num][pro]++;
        }
        vector<Team> ans;
        For (i, 1, maxN-1)
            if (Exist[i]) {
                int numpro = 0;
                For (j, 1, 9) if (Count[i][j]==-1) numpro++;
                ans.push_back(Team(i, numpro, Time[i]));
            }
        sort(ans.begin(), ans.end(), cmp);
        for (int i=0, size=ans.size(); i<size; i++)
            printf("%d %d %d\n", ans[i].num, ans[i].pro, ans[i].time);
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
