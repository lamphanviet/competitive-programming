//*****************
// LAM PHAN VIET **
// UVA 112 - Tree Summing
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define i64 long long
int SUM;
bool yes;
char ch;

bool ReadTree(i64 val) {
   bool child1 = false, child2 = false;
   int thisval = 0, sign = 1;
   while (scanf("%c", &ch)!=EOF) {
      if (ch==' ' || ch=='\n') continue;
      if (ch==')') return false; // null
      if (ch=='(') break;
      if (ch=='-') sign = -1;
      if (isdigit(ch)) thisval = thisval*10 + (ch-48);
   }
   thisval *= sign;
   val += (i64)thisval;
   child1 = ReadTree(val);
   while (scanf("%c", &ch)!=EOF && ch!='(');
   child2 = ReadTree(val);
   
   if (!child1 && !child2 && val==SUM) yes = true;
   while (scanf("%c", &ch)!=EOF && ch!=')');
   return true;
}

main() {
//   freopen("112.inp", "r", stdin); freopen("112.out", "w", stdout);
   char ch;
   while (scanf("%d ", &SUM)!=EOF) {
      yes = false;
      while (scanf("%c", &ch)!=EOF && ch!='(');
      ReadTree(0);
      if (yes) puts("yes");
      else puts("no");
   }
}

/* lamphanviet@gmail.com - 2011 */
