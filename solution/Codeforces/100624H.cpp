#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_R = 10;
const int r[MAX_R] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};

int rr[MAX_R], score[MAX_R];


int main() {
#ifdef DEBUG
	freopen("100624H.in", "r", stdin);
	freopen("100624H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,0,MAX_R-1) rr[i]=sqr(r[i]);
	fori(i,0,MAX_R-1) score[i]=MAX_R-i;

	int nTest=read();
	while (nTest--) {
		int n;
		cin >> n;
		ll ans=0;
		while (n--) {
			int x, y;
			cin >> x >> y;
			int d=sqr(x)+sqr(y);
			fori(i,0,MAX_R-1) if (d<=rr[i]) {
				ans+=score[i];
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}