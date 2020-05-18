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


const int MAX_N = 1e4 + 4;
const int MAX_P = 104;


struct node {
	int x, y, c;
	node(int x=0, int y=0, int c=0) : x(x), y(y), c(c) {}
};


int n;
node a[MAX_N];
int f[MAX_N][MAX_P];
vector<int> e[MAX_N];


bool cmp(const node &a, const node &b) {
	return a.y != b.y ? a.y < b.y : a.x != b.x ? a.x < b.x : a.c < b.c;
}


int find(int i, int limit) {
	int l=0, r=sz(e[i])-1, ans=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (a[e[i][mid]].y<limit) {
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6905.in", "r", stdin);
	freopen("6905.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) {
			int x, y, c;
			cin >> x >> y >> c;
			a[i]=node(x,y,c);
			e[i].clear();
		}
		sort(a+1, a+1+n, cmp);

		int ans=0;
		f[0][0]=0;
		fori(i,1,n) {
			int k=i-1;
			while (k>0 && a[k].y>=a[i].x) --k;
			int x=0, t=0;
			while (k<i) {
				e[i].pb(k);
				int p = (k==0) ? 0 : find(k, a[i].x);
				f[i][x]=max(t, f[k][p]+a[i].c);
				t=f[i][x];
				ans=max(ans, f[i][x]);
				++k, ++x;
			}
		}
		cout << ans << endl;
	}

	return 0;
}