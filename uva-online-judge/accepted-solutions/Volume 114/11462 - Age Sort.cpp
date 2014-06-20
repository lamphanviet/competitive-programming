//*****************
// LAM PHAN VIET **
// UVA 11462 - Age Sort
// Time limit: 5.000s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define maxN 101

int n, num[maxN];
char buff[20000000];
char number[][5] = { "0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10",  "11",  "12",  "13",  "14",  "15",  "16",  "17",  "18",  "19",  "20",  "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",  "30",  "31",  "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",  "40",  "41",  "42",  "43",  "44",  "45",  "46",  "47",  "48",  "49",  "50",  "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",  "60",  "61",  "62",  "63",  "64",  "65",  "66",  "67",  "68",  "69",  "70",  "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",  "80",  "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",  "90",  "91",  "92",  "93",  "94",  "95",  "96",  "97",  "98",  "99",  "100" };

void read_input() {
    gets(buff);
    int len = strlen(buff), k = 0;
    while (k < len)
        if (buff[k] != ' ') {
            int value = 0;
            while (k < len && buff[k] != ' ')
                value = value * 10 + (buff[k++] - 48);
            num[value]++;
        }
        else k++;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf(" %d ", &n) && n) {
        Fill(num, 0);
        read_input();
        bool space = false;
        REP(i, maxN)
            while (num[i]--) {
                if (space) putchar(' ');
                int m = 2;
                if (i < 10) m--;
                else if (i == 100) m++;
                REP(j, m) putchar(number[i][j]);
                space = true;
            }
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
