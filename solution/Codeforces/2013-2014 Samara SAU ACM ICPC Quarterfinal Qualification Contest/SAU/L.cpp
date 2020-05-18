//#include <cstdio>
//#include <cmath>
//#include <cstring>
//#include <iostream>
//#include <sstream>
//#include <algorithm>
//#include <utility>
//#include <vector>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//
//#pragma comment(linker, "/STACK:16777216")
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vecint;
//typedef pair<int, int> ii;
//typedef vector< pair<int, int> > vecppi;
//
//#define fill(a,x) memset(a, (x), sizeof(a))
//#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define sz(a) (int)a.size()
//#define pb push_back
//#define sqr(x) (x)*(x)
//
//int read() {   int x;   scanf("%d",&x);   return x;   }
//int read(int &x) {  scanf("%d",&x);     return x;   }
//
//vector <int> uoc;
//int n;
//
//int pow_(int a, int b) {
//    if (b == 0) return 1;
//    int res = pow_(a, b/2);
//    res *= res;
//    if (b & 1) res *= a;
//    return res;
//}
//
//void dquoc(int idx, vector <ii> & facts, int val) {
//    if (idx == sz(facts)) {
//        uoc.pb(val); return;
//    }
//    for (int i = 0; i <= facts[idx].second; i++)
//        dquoc(idx+1, facts, val * pow_(facts[idx].first, i));
//}
//
//void sinhUoc() {
//    vector <ii> facts;
//    int sqrtn = sqrt(n);
//    int n_ = n;
//    for (int i = 2; i <= sqrtn; i++) {
//        if (n_ % i) continue;
//        int m = sz(facts);
//        facts.pb(ii(i, 0));
//        while (n_ % i == 0) n_ /= i, facts[m].second++;
//    }
//    if (n_ > 1) facts.pb(ii(n_, 1));
//    dquoc(0, facts, 1);
//}
//int f[20000];
//int main() {
//#define DEBUG
//#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//    for (int i=0; i<20000; ++i) f[i] = 1000000000;
//    cin >> n;
//    sinhUoc();
//    int p = sz(uoc);
//    sort(uoc.begin(), uoc.end());
//    f[0]=1;
//    for (int i=1; i<p; ++i) {
//        for (int j=0; j<i; ++j) {
//            if (uoc[i]%uoc[j]==0) {
//                int tmp = uoc[i]/uoc[j];
//                f[i] = min(f[i], (tmp/2 + 1)*f[j]);
//            }
//        }
//    }
//    cout << f[p-1] << endl;
//    return 0;
//}
//
