#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 3e5 + 5;
const ll oo = 1e18;


int n, nPoint, start;
int l[MAX_N], r[MAX_N], a[MAX_N];
ll f[2][MAX_N], gleft[2][MAX_N], gright[2][MAX_N];
map<int, int> q;


inline ll getDist(int pos, int i) {
	if (pos<l[i]) return l[i]-pos;
	if (pos>r[i]) return pos-r[i];
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("575F.in", "r", stdin);
	freopen("575F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> start;
	q.clear();
	q[start];
	fori(i, 1, n) {
		cin >> l[i] >> r[i];
		q[l[i]], q[r[i]];
	}

	int nPoint=0;
	foreach(it, q) a[++nPoint] = it->fr;
	int t=0;
	fori(i,0,nPoint) fori(x,0,1) {
		f[x][i]=oo;
		gleft[x][i]=oo;
		gright[x][i]=oo;
	}
	fori(i,1,nPoint) if (a[i]==start) {
		f[0][i]=0;
		fori(j,i,nPoint) gleft[0][j]=f[0][i]-a[i];
		ford(j,i,1) gright[0][j]=f[0][i]+a[i];
		break;
	}
	fori(turn,1,n) {
		int tt=t;
		t ^= 1;
		fori(i,1,nPoint) {
			ll tmp=getDist(a[i], turn);
			f[t][i]=oo;
			f[t][i]=min(f[t][i], gleft[tt][i] + a[i] + tmp);
			f[t][i]=min(f[t][i], gright[tt][i] - a[i] + tmp);
		}
		gleft[t][0]=gright[t][nPoint+1]=oo;
		fori(i,1,nPoint) gleft[t][i]=min(gleft[t][i-1], f[t][i] - a[i]);
		ford(i,nPoint,1) gright[t][i]=min(gright[t][i+1], f[t][i] + a[i]);
	}

	ll ans = oo;
	fori(i,1,nPoint) ans = min(ans, f[t][i]);
	cout << ans << endl;

	return 0;
}