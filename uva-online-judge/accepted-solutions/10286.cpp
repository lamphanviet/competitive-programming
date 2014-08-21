#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double MyPi = 2 * acos(0);
const double Cos9 = cos(MyPi * 0.05);
const double Sin9 = sin(MyPi * 0.05);
const double Tan63 = tan(MyPi * 63 / 180);

int main () {
    double n;
    while(scanf("%lf",&n) != EOF){
        printf("%.10lf\n", n * Cos9 + n * Sin9 / Tan63);
        }
    return 0;
    }
