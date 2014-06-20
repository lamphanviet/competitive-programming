//*****************
// LAM PHAN VIET **
// UVA 11239 - Open Source
// Time limit:
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
class Pro {
public:
   string name;
   int num;
   Pro() { name=""; num=0; }
   Pro(string s) { name=s; num=0; }
};
int Count;
vector<Pro> project;
map<string, int> Index;

bool cmp(Pro a, Pro b) {
   if (a.num>b.num) return true;
   if (a.num==b.num) return a.name<b.name;
   return false;
}

main() {
//   freopen("239.inp", "r", stdin); freopen("239.out", "w", stdout);
   string s;
   while (getline(cin, s)) {
      if (s[0]=='0') break;
      if (s[0]=='1') continue;
      Count = 1;
      project.clear(); Index.clear();
      project.push_back(Pro(s));
      while (getline(cin, s)) {
         if (s[0]=='1') break;
         if ('A'<=s[0] && s[0]<='Z') {
            project.push_back(Pro(s));
            Count++;
         }
         else {
            int idx = Index[s];
            if (idx==0) {
               Index[s] = Count;
               project[Count-1].num++;
            }
            else if (idx!=Count && idx>0) {
               project[idx-1].num--;
               Index[s] = -1;
            }
         }
      }
      sort(project.begin(), project.end(), cmp);
      For (i, 0, project.size()-1) {
         cout << project[i].name;
         printf(" %d\n", project[i].num);
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
