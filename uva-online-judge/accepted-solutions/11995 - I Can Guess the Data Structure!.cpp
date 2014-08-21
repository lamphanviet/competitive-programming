//*****************
// LAM PHAN VIET **
// UVA 11995 - I Can Guess the Data Structure!
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001

class cmp {
public:
   cmp() {};
   bool operator() (const int& a, const int& b) const {
      return (a < b);
   }
};

int Check(bool s, bool q, bool h) {
   if (s || q || h) {
      if (s && !q && !h) return 1;
      if (!s && q && !h) return 2;
      if (!s && !q && h) return 3;
      return 4;
   }
   return 5;
}

main() {
//   freopen("ii.inp", "r", stdin); freopen("ii.out", "w", stdout);
   int n, a, val, k;
   while (scanf("%d", &n)!=EOF) {
      stack<int> Stack;
      queue<int> Queue;
      priority_queue<int, vector<int>, cmp> Heap;
      bool isS = true, isQ = true, isH = true;
      For (i, 1, n) {
         scanf("%d %d", &k, &val);
         if (k==1) {
            Stack.push(val);
            Queue.push(val);
            Heap.push(val);
         }
         else {
            if (Stack.empty()) isS = false;
            else if (isS) {
               a = Stack.top(); Stack.pop();
  //             printf("S %d\n", a);
               if (a!=val) isS = false;
            }
            
            if (Queue.empty()) isQ = false;
            else if (isQ) {
               a = Queue.front(); Queue.pop();
   //            printf("Q %d\n", a);
               if (a!=val) isQ = false;
            }
            
            if (Heap.empty()) isH = false;
            else if (isH) {
               a = Heap.top(); Heap.pop();
   //            printf("H %d\n", a);
               if (a!=val) isH = false;
            }
         }
      }
  //    printf("%d %d %d\n", isS, isQ, isH);
      int ans = Check(isS, isQ, isH);
      switch (ans) {
         case 1: puts("stack"); break;
         case 2: puts("queue"); break;
         case 3: puts("priority queue"); break;
         case 4: puts("not sure"); break;
         case 5: puts("impossible"); break;
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
