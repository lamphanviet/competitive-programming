// 10340 - All in All
#include <iostream>

using namespace std;

char a[1000005], b[1000005];

bool Check() {
    int i, j, na, nb;
    na = strlen(a); nb = strlen(b);
    if (na>nb) return false;
    for (i=0,j=0;i<na;i++,j++) {
        while (j<nb && b[j]!=a[i]) j++;
        if (j>=nb) return false;
    }
    return true;
}

main() {
    while (scanf("%s %s",&a,&b)!=EOF) {
        if (Check()) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
