//*****************
// LAM PHAN VIET **
// UVA 127 - "Accordian" Patience
// Time limit: 3.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
class Card {
public:
    char suit, rank;
    Card() {};
    Card(char *s) {
        rank = s[0]; suit = s[1];
    }
};
vector< vector<Card> > Stack;

bool isMatch(Card a, Card b) {
    return (a.suit==b.suit || a.rank==b.rank);
}

main() {
 //   freopen("127.inp", "r", stdin); freopen("127.out", "w", stdout);
    char s[4];
    while (scanf("%s", &s)) {
        if (s[0]=='#') break;
        Stack.clear();
        Stack.push_back( vector<Card>(1, Card(s)) );
        int n = 0;
        For (i, 2, 52) {
            scanf(" %s ", &s);
            Stack.push_back( vector<Card>(1, Card(s)) ); n++;
            bool move;
            do {
                move = false;
                For (i, 0, n) {
                    if (i>=3 && isMatch(Stack[i-3].back(), Stack[i].back()))
                        Stack[i-3].push_back(Stack[i].back());
                    else if (i>=1 && isMatch(Stack[i-1].back(), Stack[i].back()))
                        Stack[i-1].push_back(Stack[i].back());
                    else continue;
                    Stack[i].pop_back();
                    if (Stack[i].size()==0) {
                        Stack.erase(Stack.begin() + i);
                        n--;
                    }
                    move = true;
                    break;
                }
            } while (move);
        }
        printf("%d pile", n+1); if (n+1!=1) printf("s");
        printf(" remaining:");
        For (i, 0, n) printf(" %d", Stack[i].size());
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
