// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {  ll x;   cin >> x;   return x;   }


const int MAX_N = 22;
const int MAX_W = 1001;
const int LIMIT = 2e6+1;


int n;
ll dest, maxW, w[MAX_N];
bool ok[LIMIT];


bool solve() {
    filla(ok, 0);
    ok[0] = 1;
    for (int x = 1; x < LIMIT; ++x)
    	for (int i = 0; i < n; ++i)
    		if (w[i] <= x && ok[x-w[i]]) {
    			ok[x] = 1;
    			break;
    		}

    if (dest < LIMIT) return ok[dest];
    ll g = w[0];
    for (int i = 0; i < n; ++i)
    	g = __gcd(g, w[i]);
    return (dest%g) == 0;
}


int main() {
#ifdef DEBUG
    freopen("GCPC2016_C.in", "r", stdin);
    freopen("GCPC2016_C.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);   cin.tie(0);

    cin >> n >> dest;
    maxW = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        maxW = max(maxW, w[i]);
    }
    if (solve()) cout << "possible\n";
    else cout << "impossible\n";

    return 0;
}