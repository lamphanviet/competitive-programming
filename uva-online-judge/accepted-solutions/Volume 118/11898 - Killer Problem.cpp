// 11898 - Killer Problem
#include <iostream>
#include <vector>
#define N 200005
#define INF 1000000

using namespace std;

int a[N];

int Solve(int p, int q) {
    vector <int> vec;
    vec.push_back(a[p]);
    int i, u, v, ans = INF;
    for (i=p+1; i<=q && ans!=0; i++) {
        for (u=0, v=vec.size()-1; u<v; ) {
            int mid = (u+v)/2;
            if (vec[mid] < a[i]) u = mid+1;
            else v = mid;
        }
        if (vec[u]<a[i]) {
            vec.insert(vec.begin()+u+1, a[i]);
            u++;
        }
        else if (vec[u]>=a[i]) {
            vec.insert(vec.begin()+u, a[i]);
        }
        
        if (u>0 && vec[u]-vec[u-1] < ans) ans = vec[u]-vec[u-1];
        if (u<vec.size()-1 && vec[u+1]-vec[u]<ans) ans = vec[u+1]-vec[u];

//        for (int j=0; j<vec.size(); j++)
//            printf(" %d", vec[j]);
//        cout << endl;
    }
    return ans;
}

main() {
 //   freopen("898.inp", "r", stdin); freopen("898.out", "w", stdout);
    int kase, i, j, n, p, q, ques;
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=1; i<=n; i++)
            scanf("%d", &a[i]);
        cin >> ques;
        while (ques--) {
            scanf("%d %d", &p, &q);
            cout << Solve(p, q) << endl;
        }
        
    }
}
