//----------------------------
// LAM PHAN VIET
// UVA 297 - Quadtrees
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 32
#define maxS 10000
class Point {
public:
    int x, y;
    Point() { x = y = 0; }
    Point(int a, int b) { x=a; y=b; }
    void Get(int a, int b) { x=a; y=b; }
};
char s[maxS], mp[N+2][N+2];


void Fill(Point a, Point b, char color) {
    for (int i=a.x; i<=b.x; i++)
        for (int j=a.y; j<=b.y; j++)
            if (mp[i][j]!='f') mp[i][j] = color;
}

int Process(int k, Point a, Point b) {
    Point mid((a.x+b.x)/2, (a.y+b.y)/2);
    k++;
    if (s[k]=='f') Fill(a, mid, s[k]);
    else if (s[k]=='e') Fill(a, mid, s[k]);
    else k = Process(k, a, mid);
    k++;
    if (s[k]=='f') Fill(Point(a.x, mid.y+1), Point(mid.x, b.y), s[k]);
    else if (s[k]=='e') Fill(Point(a.x, mid.y+1), Point(mid.x, b.y), s[k]);
    else k = Process(k, Point(a.x, mid.y+1), Point(mid.x, b.y));
    k++;
    if (s[k]=='f') Fill(Point(mid.x+1, a.y), Point(b.x, mid.y), s[k]);
    else if (s[k]=='e') Fill(Point(mid.x+1, a.y), Point(b.x, mid.y), s[k]);
    else k = Process(k, Point(mid.x+1, a.y), Point(b.x, mid.y));
    k++;
    if (s[k]=='f') Fill(Point(mid.x+1, mid.y+1), b, s[k]);
    else if (s[k]=='e') Fill(Point(mid.x+1, mid.y+1), b, s[k]);
    else k = Process(k, Point(mid.x+1, mid.y+1), b);
    
    return k;
}

void Print() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            printf("%c", mp[i][j]);
        printf("\n");
    }
}

main() {
 //   freopen("297.inp", "r", stdin); freopen("297.out", "w", stdout);
    int Case, ans;
    scanf("%d", &Case); gets(s);
    while (Case--) {
        for (int i=1; i<=32; i++)
            for (int j=1; j<=32; j++)
                mp[i][j] = 'e';
        gets(s);
        if (s[0]=='p') Process(0, Point(1, 1), Point(N, N));
        else Fill(Point(1, 1), Point(N, N), s[0]);
        gets(s);
        if (s[0]=='p') Process(0, Point(1, 1), Point(N, N));
        else Fill(Point(1, 1), Point(N, N), s[0]);
        
 //       Print();
        ans = 0;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                if (mp[i][j]=='f') ans++;
        printf("There are %d black pixels.\n", ans);
    }
}
