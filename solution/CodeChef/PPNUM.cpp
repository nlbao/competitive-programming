//#include <sstream>
#include <iostream>
#include <cstdio>
/*#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")*/

using namespace std;

typedef long long ll;
/*typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;*/

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

const ll MODULE = 1000000007LL;

ll f[11];

ll mmod(ll x) {
    x %= MODULE;
    return (x+MODULE)%MODULE;
}

ll sum(ll i) {
    return mmod(i*(i+1)/2)%MODULE;
}

ll s(int i, int j) {
    return mmod(sum(j) - sum(i-1) + MODULE);
}

ll cal(ll x) {
    if (x < 1) return 0;
    ll n = 0, t = x, p = 1;
    while (t) {
        ++n;
        t /= 10;
        p *= 10;
    }
    p /= 10;
    return mmod(f[n-1] + s(p, x)*n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("PPNUM.in", "r", stdin);
    freopen("PPNUM.out", "w", stdout);
#endif
    f[0] = 0;
    f[1] = s(1, 9);
    int l = 1, r = 9;
    foru(i, 2, 9) {
        l *= 10;
        r = r*10+9;
        f[i] = mmod(f[i-1] + s(l, r)*ll(i));
    }

    //cout << f[1] << " " << f[2] << endl;
    //cout << cal(9) << " " << cal(8) << "      " << cal(11) << endl;

    int nTest = read();
    rep(test_id, nTest) {
        scanf("%d%d", &l ,&r);
        int res = mmod(cal(r) - cal(l-1));
        printf("%d\n", res);
        printf("    %lld\n",long long(res));
    }
    return 0;
}
