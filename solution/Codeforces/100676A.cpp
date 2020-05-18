#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define forr(i,a,b) for (__typeof(b) i=(a); i!=(b)+((a)<(b)?1:-1); i+=((a)<(b)?1:-1))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


int x, y;
string o;


bool solve() {
	if (o=="!=") return x!=y;
	if (o=="==") return x==y;
	if (o=="<") return x<y;
	if (o=="<=") return x<=y;
	if (o==">") return x>y;
  	return x>=y;
}


int main() {
#ifdef DEBUG
	freopen("100676A.in", "r", stdin);
	freopen("100676A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	forr(testid,1,nTest) {
		cin >> x >> o >> y;
		if (solve()) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}