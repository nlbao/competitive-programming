#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int MAX_N = 2003;
const int MAX_M = 2*MAX_N;

double a[MAX_M], t[MAX_M];
double f_ceil[MAX_M], f_floor[MAX_M];

/*double f_ceil(double x) {
    return ceil(x)-x;
}

double f_floor(double x) {
    return x-floor(x);
}*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("351A.in", "r", stdin);
    freopen("351A.out", "w", stdout);
#endif
    int n = read(), m = 2*n;
    double s0 = 0, res = 2000000000;
    foru(i,1,m) {
        scanf("%lf",&a[i]);
        f_ceil[i] = ceil(a[i]);//-a[i];
        f_floor[i] = /*a[i]-*/floor(a[i]);
        s0 += a[i];
    }

    cout << "     " << f_ceil[2] << endl;

    double s1 = 0, st = 0;
    foru(i,1,m) {
        s1 += f_ceil[i];
        t[i] = f_floor[i]-f_ceil[i];
        cout << i << " " << t[i] << endl;
    }
    sort(t+1, t+1+m);
    foru(i,1,n) st += t[i];

    if (st <= s0-s1)
        res = min(res, s1+st-s0);
    s1 = 0; st = 0;
    foru(i,1,m) {
        s1 += f_floor[i];
        t[i] = f_ceil[i]-f_floor[i];
    }
    sort(t+1, t+1+m);
    ford(i,m,m-n+1) st += t[i];
    if (st >= s1-s0)
        res = min(res, s0-(s1+st));

    printf("%.3f\n", res);
    return 0;
}
