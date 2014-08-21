// 11869 - SOAP Response
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Pro {
    map <string, string> ppt;
    map <int, int> kid;
    int prt;
} tag[1005];

map <string, int> Stt;
int n; // so luong tag

int Find(string s) {
    for (int i=0;i<s.length();i++)
        if (s[i]=='"') return i;
}

void Enter() {
    int Stack[2000], top;
    int m, i, t, k, len;
    string str, temp, s1, s2;
    
    n = 0;
    top = 1; Stack[1] = 0;
    
    cin >> m; cin.get();
    for (t=1; t<=m; t++) {
        getline(cin, str);
        
  //      cout << str << endl;
        
        if (str[1]=='/') top--;
        else {
            k = 0; len = str.length()-1;
            while (k < len && str[k] != ' ') k++;
            
            temp = str.substr(1,k-1);
            Stt[temp] = Stack[++top] = ++n;
            tag[Stack[top-1]].kid[n] = 1;
            
   //         cout << temp << endl;
            k++;
            while (k<len) {
                i = k;
                while (i<len && str[i]!=' ') i++;
                temp = str.substr(k, i-k);
  //              cout << temp << endl;
                
                int mid = temp.find('"');
                
                s1 = temp.substr(0,mid-1); s2 = temp.substr(mid+1,temp.length()-mid-2);
  //              cout << s1 << " " << s2 << endl;
                
                tag[n].ppt[s1] = s2;
                
                k = i+1;
            } 
        }
    }
}

int Solve(string str) {
    int i, k, mid, dot;
    string temp;
    int u, v, parent = 0;

    bool f = true;
    
    k = 0;
    mid = str.find('"');
    while (k<mid && f) {
        dot = str.find('.', k);
        if (dot==-1) dot = mid-1;
        temp = str.substr(k, dot-k);
 //       cout << temp << endl;
            
        u = Stt[temp];
        if (tag[parent].kid[u]==0)
            return 1;
        
        parent = u;
        k = dot+1;
    }
    mid++;
    temp = str.substr(mid, str.length()-mid-2);
    
    if (tag[parent].ppt[temp]!="")
        cout << tag[parent].ppt[temp] << endl;
    else return 1;
    
    return 0;
}

main() {
 //   freopen("bb.inp","r",stdin); freopen("bb.out","w",stdout); 
    
    int k, kase, i, m;
    string str;
    
    cin >> kase;
    for (k=1; k<=kase; k++) {
        Enter();
        
        printf("Case %d:\n",k);
        cin >> m; cin.get();
        for (i=1;i<=m;i++) {
            getline(cin, str);
            int ans = Solve(str);
            if (ans) printf("Undefined\n");
        }
        
        for (i=1; i<=n; i++) {
            tag[i].ppt.clear(); tag[i].kid.clear();
        }
        Stt.clear();
    }
}
