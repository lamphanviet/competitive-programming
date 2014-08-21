/*****************/
/* LAM PHAN VIET */
/* UVA 11356 - Dates
/* Time limit: 2.000s
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
#define maxN 10000
using namespace std;

const int day_max[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char month_name[][20] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
map<string, int> month_number;

struct Date {
    int year, month, day;
    void get(int y, int m, int d) {
        year = y; month = m; day = d;
    };
    void add_one() {
        day++;
        bool leap = year % 4 == 0 && (year % 100 || year % 400 == 0);
        if (month == 2 && day == 29 && leap) return;
        if (day > day_max[month]) {
            day = 1;
            month++;
        }
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    void print() {
        printf("%d-", year);
        printf("%s-", month_name[month]);
        if (day < 10) putchar('0');
        printf("%d\n", day);
    }
};

void read_date(Date& date) {
    char s[100];
    gets(s);
    int len = strlen(s), i = 5;
    int d = 0, y = 0;
    y = (s[0] - 48) * 1000 + (s[1] - 48) * 100 + (s[2] - 48) * 10 + s[3] - 48;
    string m = "";
    while (i < len && s[i] != '-')
        m += s[i++];
    d = (s[i + 1] - 48) * 10 + s[i + 2] - 48;
    date.get(y, month_number[m], d);
}

main() {
//    FileIn("test"); FileOut("test");
    FOR (i, 1, 12)
        month_number[month_name[i]] =  i;
    Date date;
    int Case, k;
    scanf("%d ", &Case);
    FOR (test, 1, Case) {
        read_date(date);
        scanf("%d ", &k);
        while (k--) date.add_one();
        printf("Case %d: ", test);
        date.print();
    }
}

/* lamphanviet@gmail.com - 2011 */
