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


const int MAX_N=200;
const int dx[4]={0,+1,0,-1};
const int dy[4]={+1,0,-1,0};


int turn[MAX_N][MAX_N];
bool ok[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("6802.in", "r", stdin);
	freopen("6802.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read(), crrTurn=0;
	filla(turn, 0);
	string s;
	fori(testid,1,nTest) {
		int x, y;
		cin >> x >> y;
		cin >> s;
		int n=sz(s), c=0, k=0;
		++crrTurn;
		filla(ok, 1);
		fori(i,0,n) {
			turn[x][y]=crrTurn;
			if (i==n) continue;
			if (s[i]=='F') {
				x+=dx[k];
				y+=dy[k];
				if (turn[x][y]==crrTurn) {
					if (ok[x][y]) ++c;
					ok[x][y]=0;
				}
			}
			else if (s[i]=='R') k=(k+1)%4;
			else k=(k-1+4)%4;
		}
		cout << "Case #" << testid << ": " << x << " " << y << " " << c << endl;
	}

	return 0;
}