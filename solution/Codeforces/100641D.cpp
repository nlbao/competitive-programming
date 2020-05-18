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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N=55;
const int MAX_X=100*MAX_N+11;


string s;
vector<int> q[MAX_N][MAX_N], ans;
int inQ[MAX_X], a[MAX_N];


inline int num(char x) {
	if (x=='I') return 1;
	if (x=='V') return 5;
	if (x=='X') return 10;
	if (x=='L') return 50;
	if (x=='C') return 100;
	return 0;
}


inline int cal(int x, int y) {
	return x>=y?x+y:y-x;
}


void solve() {
	int n=sz(s), crrTurn=0;
	fori(i,1,n) {
		a[i]=num(s[i-1]);
		fori(j,1,n) q[i][j].clear();
		q[i][i].pb(a[i]);
	}

	filla(inQ, 0);
	fori(len,2,n) {
		fori(i,1,n-len+1) {
			int j=i+len-1;
			++crrTurn;
			fori(k,i,j-1) {
				foreach(it1, q[i][k]) foreach(it2, q[k+1][j]) {
					int x=cal(*it1, *it2);
					if (inQ[x]==crrTurn) continue;
					inQ[x]=crrTurn;
					q[i][j].pb(x);
				}
			}
		}
	}
	ans.clear();
	foreach(it, q[1][n]) if (*it>0) ans.pb(*it);
}


int main() {
#ifdef DEBUG
	freopen("100641D.in", "r", stdin);
	freopen("100641D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	while (1) {
		cin >> s;
		if (s[0]=='0') break;
		solve();
		cout << "Case " << ++testid << ": ";
		sort(ans.begin(), ans.end());
		foreach(it, ans) cout << *it << " ";
		cout << endl;
	}

	return 0;
}