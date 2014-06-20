//*****************
// LAM PHAN VIET **
// UVA 11343 - Isolated Segments
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define maxN 102
class Segment {
    int x1, y1, x2, y2;
    double a, b, c;
public:
    Segment() {
        x1 = y1 = x2 = y2 = 0;
        a = b = c = 0;
    }
    void Read() {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        Create();
    }
    void Create() {
        a = y1 - y2;
        b = x2 - x1;
        c = x1*y2 - x2*y1;
    }
    double Side(int x, int y) {
        return (a*x + b*y + c);
    }
    double Distance(int x, int y, int k) {
        if (k==1) return sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
        return sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
    }
    double Length() {
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }
    bool isCollide(Segment s) {
        double sidea, sideb, sidec, sided;
        sidea = s.Side(x1, y1);
        sideb = s.Side(x2, y2);
        sidec = Side(s.x1, s.y1);
        sided = Side(s.x2, s.y2);
        if (sidea*sideb<0 && sidec*sided<0) return true;
        if (sidea*sideb>0 || sidec*sided>0) return false;
        double len = Length(), lens = s.Length();
        if (!sidea && s.Distance(x1, y1, 1)+s.Distance(x1, y1, 2)==lens) return true;
        if (!sideb && s.Distance(x2, y2, 1)+s.Distance(x2, y2, 2)==lens) return true;
        if (!sidec && Distance(s.x1, s.y1, 1)+Distance(s.x1, s.y1, 2)==len) return true;
        if (!sided && Distance(s.x2, s.y2, 1)+Distance(s.x2, s.y2, 2)==len) return true; 
        return false;
    }
};
Segment seg[maxN];
bool Isolated[maxN];

main() {
 //   freopen("343.inp", "r", stdin); freopen("343.out", "w", stdout);
    int Case, n;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            seg[i].Read();
            Isolated[i] = true;
        }
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if (seg[i].isCollide(seg[j])) {
                    Isolated[i] = Isolated[j] = false;
                }
        int Count = 0;
        for (int i=0; i<n; i++)
            if (Isolated[i]) Count++;
        printf("%d\n", Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
