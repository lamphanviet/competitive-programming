// UVA Problem   	11835 - Formula 1
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2935
#include <iostream>

using namespace std;

int race,pilots,score;
int rp[110][110],sc[110];

void DoIt() {
    int i,j,diem[110];
    for (i=1;i<=pilots;i++)
        diem[i]=0;
    for (i=1;i<=race;i++) {
        for (j=1;j<=pilots;j++) {
            diem[j] += sc[rp[i][j]];
        }
    }

    int max=0;
    for (i=1;i<=pilots;i++)
        if (diem[i]>max) max=diem[i];
        
    int k=0, rs[100];
    for (i=1;i<=pilots;i++)
        if (diem[i]==max) rs[++k]=i;
        
    cout << rs[1];
    if (k>1) {
        for (i=2;i<=k;i++)
            printf(" %d",rs[i]);
    }
    cout << endl;
}

void Enter() {
    int i,j;
    for (i=1;i<=race;i++)
        for (j=1;j<=pilots;j++)
            cin >> rp[i][j];
    cin >> score;
    int n;
    while (score--) {
        cin >> n;
        for (i=1;i<=n;i++)
            cin >> sc[i];
        while (i<=pilots) sc[i++]=0;
        DoIt();
    }
}

main() {
 //   freopen("f.inp","r",stdin);
//    freopen("f.out","w",stdout);
    
    while (cin >> race >> pilots) {
        if (race==0 && pilots==0) break;
        Enter();
    }
}
