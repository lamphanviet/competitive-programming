// Problem 11734 - Big Number of Teams will Solve This
#include <iostream>
#include <string.h>

using namespace std;

char team[30],jud[30];

int Judge() {
    if (strcmp(team,jud)==0) return 1;
    
    char temp[30];
    int i,k,n = strlen(team);
    for (i=0,k=0;i<=n;i++)
        if (team[i]!=' ') temp[k++] = team[i];
    if (strcmp(temp,jud)==0) return 3;
    else return 2;
}

main() {
    int kase,t,k;
    cin >> kase;
    scanf(" ");
    for (t=1;t<=kase;t++) {
        gets(team);
        gets(jud);
        k = Judge();
        cout << "Case " << t << ": ";
        if (k==1) cout << "Yes";
        else if (k==2) cout << "Wrong Answer";
        else cout << "Output Format Error";
        cout << endl;
    }
}
