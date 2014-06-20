//*****************
// LAM PHAN VIET **
// UVA 11988 - Broken Keyboard (a.k.a. Beiju Text)
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100005
vector<string> home;
vector<string> end;

main() {
 //  freopen("bb.inp", "r", stdin); freopen("bb.out", "w", stdout);
   char s[maxN];
   while (gets(s)) {
      string tmp = "";
      home.clear(); end.clear();
      int n = strlen(s); s[n++] = ']';
      int i = 0, status = 0;
      while (i<n) {
         if (s[i]!='[' && s[i]!=']') tmp += s[i];
         else {
            if (status==1) home.push_back(tmp);
            else end.push_back(tmp);
            if (s[i]=='[') status = 1;
            else status = 0;
            tmp = "";
         }
         i++;
      }
      for (int i=home.size()-1; i>=0; i--) cout << home[i];
      for (int i=0, size=end.size(); i<size; i++) cout << end[i];
      printf("\n");
   }
}

/* lamphanviet@gmail.com - 2011 */
