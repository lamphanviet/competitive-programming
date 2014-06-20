//*****************
// LAM PHAN VIET **
// UVA 122 - Trees on the level
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1000000
int val[maxN], Maxp;
bool Exist[maxN], cmpl;

bool Check() {
   if (!Exist[1]) return false;
   for (int i=2; i<=Maxp; i+=2) {
      bool Child = Exist[i] || Exist[i+1];
      if (Child && !Exist[i/2]) return false;
   }
   return true;
}

main() {
//   freopen("122.inp", "r", stdin); freopen("122.out", "w", stdout);
   int a, len;
   char s[300], path[300];
   while (scanf("%s", &s)!=EOF) {
      Maxp = 1; cmpl = true;
      memset(Exist, false, maxN);
      while (1) {
         if (strcmp(s, "()")==0) break;
         sscanf(s, "(%d,%s)", &a, &path);
         len = strlen(path);
         int p = 1;
         For (i, 0, len-2) {
            p *= 2;
            if (path[i]=='R') p++;
         }
         if (Exist[p]) cmpl = false;
         Exist[p] = true;
         val[p] = a;
         Maxp = max(p, Maxp);
         scanf("%s", &s);
      }
      if (!cmpl || !Check()) puts("not complete");
      else {
         printf("%d", val[1]);
         For (i, 2, Maxp)
            if (Exist[i]) printf(" %d", val[i]);
         printf("\n");
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
