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
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int MAX_A = 16100;

ll n, res = 0;
vector<ll> a;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

ll up(ll a, ll b, ll c) {
    if (a < 0 || b < 0 || c < 0) return 0;
    if (a == b && b == c) return 1;
    if (a == b && b < c) return 3;
    if (a < b && b == c) return 3;
    if (a < b && b < c) return 6;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("293C.in", "r", stdin);
    freopen("293C.out", "w", stdout);
#endif
    cin >> n;
    if (n%3 != 0) {
        cout << 0;
        return 0;
    }

    ll tmp = n/3, limit = ll(sqrt(double(tmp))) + 4;
    for(ll i = 1; i <= limit; ++i)
        if (n%i == 0) {
            ll d = tmp/i;
            if (d < i) break;
            a.pb(i);
            if (d == i) break;
            a.pb(d);
        }

    int m = size(a);

    cout << m << endl;
    //rep(i,m) cout << a[i] << endl;   cout << endl;  cout << endl;
    limit = ll(pow(double(n/24+1), double(1)/double(3)))+4;
    cout << "limit = " << limit << endl;


    rep(i,m) {
        ll s = a[i], t1 = s*s, t2 = 4*n/(3*s);
        for(ll x = 1; x < limit && x < s; ++x) {
            ll y = s-x;
            ll delta = t1 - 4*x*y + t2;
            if (delta < 0) continue;
            if (delta == 0) {
                if (s%2 == 0) res += up(x,y,-s/2);
                continue;
            }
            ll tmp = sqrt(double(delta));
            if (tmp*tmp != delta) continue;
            if ((-s-tmp)%2 == 0) res += up(x,y,(-s-tmp)/2);
            if ((-s+tmp)%2 == 0) res += up(x,y,(-s+tmp)/2);
        }
    }

    cout << res << endl;
    return 0;
}
