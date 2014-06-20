/*****************/
/* LAM PHAN VIET */
/* UVA 101 - The Blocks Problem
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 27
using namespace std;

int n, block[maxN];
stack<int> pile[maxN];
char s1[10], s2[10];

void move_onto(int a, int b) {
    while (pile[block[a]].top() != a) {
        int top = pile[block[a]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[a]].pop();
    }
    while (pile[block[b]].top() != b) {
        int top = pile[block[b]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[b]].pop();
    }
    
    pile[block[a]].pop();
    block[a] = block[b];
    pile[block[b]].push(a);
}

void move_over(int a, int b) {
    while (pile[block[a]].top() != a) {
        int top = pile[block[a]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[a]].pop();
    }
    
    pile[block[a]].pop();
    block[a] = block[b];
    pile[block[b]].push(a);
}

void pile_onto(int a, int b) {
    while (pile[block[b]].top() != b) {
        int top = pile[block[b]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[b]].pop();
    }
    
    stack<int> tmp;
    while (pile[block[a]].top() != a) {
        tmp.push(pile[block[a]].top());
        pile[block[a]].pop();
    }
    
    tmp.push(a);
    pile[block[a]].pop();
    
    while (!tmp.empty()) {
        pile[block[b]].push(tmp.top());
        block[tmp.top()] = block[b];
        tmp.pop();
    }
}

void pile_over(int a, int b) {
    stack<int> tmp;
    while (pile[block[a]].top() != a) {
        tmp.push(pile[block[a]].top());
        pile[block[a]].pop();
    }
    
    tmp.push(a);
    pile[block[a]].pop();
    
    while (!tmp.empty()) {
        pile[block[b]].push(tmp.top());
        block[tmp.top()] = block[b];
        tmp.pop();
    }
}

void result() {
    stack<int> tmp;
    REP(i, n) {
        printf("%d:", i);
        while (!pile[i].empty()) {
            tmp.push(pile[i].top());
            pile[i].pop();
        }
        while (!tmp.empty()) {
            printf(" %d", tmp.top());
            tmp.pop();
        }
        putchar('\n');
    }
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &n) != EOF) {
        REP(i, n) {
            pile[i].push(i);
            block[i] = i;
        }
        int a, b;
        while (scanf("%s", &s1) != EOF) {
            if (s1[0] == 'q') break;
            scanf("%d %s %d ", &a, &s2, &b);
            
            if (a == b || block[a] == block[b]) continue;
            if (s1[0] == 'm') {
                if (s2[1] == 'n') move_onto(a, b);
                else move_over(a, b);
            }
            else {
                if (s2[1] == 'n') pile_onto(a, b);
                else pile_over(a, b);
            }
        }
        result();
    }
}

/* lamphanviet@gmail.com - 2011 */
