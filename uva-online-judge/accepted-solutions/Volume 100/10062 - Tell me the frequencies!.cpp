//*****************
// LAM PHAN VIET **
// UVA 10062 - Tell me the frequencies!
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 270
typedef struct Number {
   int frequency, pos;
};
Number num[maxN];
char s[1005];

bool cmp(Number a, Number b) {
   return (a.frequency<b.frequency || (a.frequency==b.frequency && a.pos>b.pos));
}

main() {
   bool Line = false;
   while (gets(s)) {
      For (i, 0, maxN-1) {
         num[i].frequency = 0;
         num[i].pos = i;
      }
      int n = strlen(s);
      For (i, 0, n-1)
         num[s[i]].frequency++;
      sort(num+32, num+128, cmp);
      if (Line) printf("\n"); Line = true;
      For (i, 32, 127)
         if (num[i].frequency)
            printf("%d %d\n", num[i].pos, num[i].frequency);
   }
}

/* lamphanviet@gmail.com - 2011 */
