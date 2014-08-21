#include <iostream>
#include <algorithm>

using namespace std;
int M1[110], M2[110];

bool myfun(int a, int b){
    return (b < a);
    }

int main () {
    int n, d, r, a, t;
    while(scanf("%d%d%d",&n,&d,&r) && n){
        t = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d",&a);
            M1[i] = a;
            }
        for(int i = 1; i <= n; i++){
            scanf("%d",&a);
            M2[i] = a;
            }        
        sort(M2 + 1, M2 + n + 1);
        sort(M1 + 1, M1 + n + 1, myfun);
                //for(int i = 1; i <= n; i++){
            //printf("%d ",M1[i]);
            //M1[i] = a;
            //}
        for(int i = 1; i <= n; i++){
            if(M2[i] + M1[i] > d){
                t += ((M2[i] + M1[i] - d) * r);
                }
            }
        printf("%d\n",t);
        }
    
    return 0;
    }
