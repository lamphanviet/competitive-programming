// 10100 - Longest Match
#include <iostream>
#include <map>

using namespace std;

map <string, int> mapStr;
int stt;

bool isAlpha(char a) {
    return (('a'<=a && a<='z') || ('A' <=a && a<= 'Z') || ('0'<=a && a<='9'));
}

int Convert(string str, int x[]) {
    int i, j, n, len;
    len = str.length();
    i = n = 0;
    do {
        while (i<len && !isAlpha(str[i])) i++;
        j = i;
        if (j>=len) break;
        while (j<len && isAlpha(str[j])) j++;
        
        string temp(str,i,j-i);
 //       cout << temp << endl;
        if (mapStr[temp]==0) mapStr[temp] = ++stt;
        
        x[n++] = mapStr[temp];
        
        i = j;
    } while (i<len);
    return n;
}

main() {
//    freopen("100.inp","r",stdin);
//    freopen("100.out","w",stdout);
    string s1, s2;
    int kase = 0, i, k, tempmax;
    int a[1005], b[1005], x[1005], na, nb, ans;
    while (getline(cin,s1)) {
        getline(cin,s2);
        printf("%2d. ",++kase);
        if (!s1.length() || !s2.length()) {
            cout << "Blank!" << endl;
            continue;
        }
        stt = 0;
        na = Convert(s1,a);
        nb = Convert(s2,b);
        ans = 0;
        
/*        for (k=0;k<na;k++)
                printf(" %d",a[k]);
        cout << endl;
        for (k=0;k<nb;k++)
                printf(" %d",b[k]);
        cout << endl;
        */
        for (k=0;k<nb;k++) x[k] = 0;
        for (k=0;k<na;k++) {
            tempmax = 0;
            for (i=0;i<nb;i++)
                if (a[k]==b[i]) {
                    if (x[i]<=tempmax) x[i] = tempmax+1;
                    else tempmax = x[i];
                    if (x[i]>ans) ans = x[i];
                }
                else if (x[i]>tempmax) tempmax = x[i];
            
        }
        cout << "Length of longest match: " << ans << endl;
        mapStr.clear();
    }
}
