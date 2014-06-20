//*****************
// LAM PHAN VIET **
// UVA 11513 - 9 Puzzle
// Time limit: 6s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 362900
class Answer {
public:
   string result;
   int move;
   Answer() { result=""; move=0; }
   Answer(string r, int m) {
      result = r; move = m;
   }
   Answer(Answer a, int go) {
      switch (go) {
         case 1: result = "H1"; break;
         case 2: result = "H2"; break;
         case 3: result = "H3"; break;
         case 4: result = "V1"; break;
         case 5: result = "V2"; break;
         case 6: result = "V3"; break;
      }
      result += a.result;
      move = a.move + 1;
   }
};
int n = 1;
vector<Answer> ans;
map<string, int> Index;

string Hor(string s, int i) {
   char tmp = s[i]; s[i] = s[i+1]; s[i+1] = s[i+2]; s[i+2] = tmp;
   return s;
}
string Ver(string s, int i) {
   char tmp = s[i+6]; s[i+6] = s[i+3]; s[i+3] = s[i]; s[i] = tmp;
   return s;
}

void PreCal_BFS() {
   queue<string> Q;
   Q.push("123456789");
   Index["123456789"] = 1;
   ans.push_back(Answer()); // 0
   ans.push_back(Answer("", 0)); // first
   
   string s, nexts;
   while (!Q.empty()) {
      s = Q.front(); Q.pop();
      int u = Index[s];
      
      nexts = Hor(s, 0);
      if (Index[nexts]==0) {
//         cout << nexts << endl;
         Index[nexts] = ++n; ans.push_back(Answer(ans[u], 1));
         Q.push(nexts);
      }
      nexts = Hor(s, 3);
      if (Index[nexts]==0) {
 //        cout << nexts << endl;
         Index[nexts] = ++n; ans.push_back(Answer(ans[u], 2));
         Q.push(nexts);
      }
      nexts = Hor(s, 6);
      if (Index[nexts]==0) {
 //        cout << nexts << endl;
         Index[nexts] = ++n; ans.push_back(Answer(ans[u], 3));
         Q.push(nexts);
      }
      nexts = Ver(s, 0);
      if (Index[nexts]==0) {
 //        cout << nexts << endl;
         Index[nexts] = ++n; ans.push_back(Answer(ans[u], 4));
         Q.push(nexts);
      }
      nexts = Ver(s, 1);
      if (Index[nexts]==0) {
//         cout << nexts << endl;
         Index[nexts] = ++n; ans.push_back(Answer(ans[u], 5));
         Q.push(nexts);
      }
      nexts = Ver(s, 2);
      if (Index[nexts]==0) {
 //        cout << nexts << endl;
         Index[nexts] = ++n; ans.push_back(Answer(ans[u], 6));
         Q.push(nexts);
      }
   }
}

main() {
//   freopen("513.inp", "r", stdin); freopen("513.out", "w", stdout);
   PreCal_BFS();
   int a;
   while (scanf("%d", &a) && a) {
      string s = "";
      s += char(a+48);
      For (i, 2, 9) {
         scanf("%d", &a);
         s += char(a+48);
      }
//      cout << s << endl;
      int idx = Index[s];
      if (idx==0) puts("Not solvable");
      else {
         printf("%d ", ans[idx].move);
         cout << ans[idx].result << endl;
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
