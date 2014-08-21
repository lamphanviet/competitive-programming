// 11308 - Bankrupt Baker
#include <iostream>
#include <map>
#include <string>
#include <string.h>

using namespace std;

struct ANS {
    char name[100];
    int cost;
} ans[110];

int numans;

bool cmp(ANS a, ANS b) {
    return (a.cost<b.cost || (a.cost==b.cost && strcmp(a.name,b.name)==-1));
}

main() {
//    freopen("308.inp","r",stdin);
//    freopen("308.out","w",stdout);
    
    map <string, int> mapInt;
    string s;
    char name[100];
    int a, n, m, maxcost;
    
    int kase;
    cin >> kase;
    while (kase--) {
        cin.get();
        gets(name);
        for (int i=0;i<strlen(name);i++)
            printf("%c",toupper(name[i]));
        cout << endl;
        
        cin >> n >> m >> maxcost;
        while (n--) {
            cin.get();
            cin >> s >> a;
  //          cout << s << " " << a << endl;
            mapInt[s] = a;
        }
        
        numans = 0;
        while (m--) {
            cin.get();
            gets(name);
            cin >> n;
            int cost = 0;
            while (n--) {
                cin.get();
                cin >> s >> a;
                cost += mapInt[s]*a;
            }
            if (cost<=maxcost) {
                numans++;
                strcpy(ans[numans].name,name);
                ans[numans].cost = cost;
            }
        }
        
        if (!numans) cout << "Too expensive!" << endl;
        else {
            sort(ans+1,ans+numans+1,cmp);
            for (int i=1;i<=numans;i++)
                puts(ans[i].name);
        }
        cout << endl;
        mapInt.clear();
    }
}
