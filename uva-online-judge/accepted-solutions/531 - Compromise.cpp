/*****************/
/* LAM PHAN VIET */
/* UVA 531 - Compromise
/* Time limit: 3.000s
/********************************/
#include <iostream>
#include <string>
#include <map>

using namespace std;

main() {
 //   freopen("531.inp","r",stdin);
 //   freopen("531.out","w",stdout);
    map <string, int> mapStr;
    string str;
    string luu[105];
    int na, nb, a[105], b[105], x[105];
    int stt, i, k, tempmax, Trace[105];
    while (cin >> str) {
        mapStr.clear();
        
        na = nb = stt = 0;
        do {
            if (str=="#") break;
            if (!mapStr[str]) {
                mapStr[str] = a[na++] = ++stt;
                luu[stt] = str;
            }
            else a[na++] = mapStr[str];
        } while (cin >> str);
        
        while (cin >> str) {
            if (str=="#") break;
            if (!mapStr[str]) {
                mapStr[str] = b[nb++] = ++stt;
                luu[stt] = str;
            }
            else b[nb++] = mapStr[str];
        }
        
        int maxlen = 0, last, u;
        for (k=0;k<nb;k++) {
            x[k] = 0; Trace[k] = -1;
        }
        
        for (k=0;k<na;k++) {
            tempmax = 0; last = -1;
            for (i=0;i<nb;i++)
                if (a[k]==b[i]) {
                    if (x[i]<=tempmax) {
                        x[i] = tempmax+1;
                        Trace[i] = last;
                    }
                    else {
                        tempmax = x[i];
                        last = i;
                    }
                    if (x[i]>maxlen) {
                        maxlen = x[i];
                        u = i;
                    }
                }
                else if (x[i]>tempmax) {
                    tempmax = x[i];
                    last = i;
                }
        }
        
 //       cout << maxlen << endl;
        i = maxlen;
        while (u>=0) {
            x[--i] = u;
            u = Trace[u];
        }
        if (maxlen>0) cout << luu[b[x[0]]];
        for (i=1; i<maxlen; i++) {
            cout << " " << luu[b[x[i]]];
        }
        cout << endl;
    }
}
