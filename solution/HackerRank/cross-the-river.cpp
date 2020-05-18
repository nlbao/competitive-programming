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


const int MAX_N = 1e5+5;
const int MAX_X = 1e5+15;
const int MAX_S = 4*MAX_X;
const int oo = 1e9+99;


int n, u, v, pos, value, H, dH, dW;
int f[MAX_N];
multiset<int> s[MAX_S];
pair<pii,int> a[MAX_N];
bool isInsert;


void update(int k, int l, int r) {
	if (l>pos || r<pos) return;
	if (isInsert) s[k].insert(value);
	else s[k].erase(s[k].find(value));
	if (l==r) return;
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
}


int get(int k, int l, int r) {
	if (l>v || r<u || u>v) return -oo;
	if (u<=l && r<=v) {
		if (s[k].empty()) return -oo;
		return - *s[k].begin();
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return max(get(kl, l, mid), get(kr, mid+1, r));
}


inline void treeUpdate(int p, int val, bool insert) {
	if (val <= -oo) return;
	pos=p;
	value=-val;
	isInsert=insert;
	update(1, 1, MAX_X-1);
}


inline int treeGet(int l, int r) {
	u=max(l,1), v=min(r,MAX_X-1);
	return get(1, 1, MAX_X-1);
}


int main() {
#ifdef DEBUG
	freopen("cross-the-river.in", "r", stdin);
	freopen("cross-the-river.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> H >> dH >> dW;
	fori(i,1,n) {
		int x, y, z;
		cin >> y >> x >> z;
		++x;
		a[i]=mp(mp(y,x),z);
	}
	sort(a+1,a+1+n);

	int ans=-oo, l=1;
	for (int k=1, pnext=1; k<=n; k=pnext) {
		int j=k+1;
		while (j<=n && a[j].fr.fr==a[k].fr.fr) ++j;
		fori(i,k,j-1) {
			int y=a[i].fr.fr, x=a[i].fr.sc;
			while (l<k && a[l].fr.fr < y-dH) {
				treeUpdate(a[l].fr.sc, f[l], 0);
				++l;
			}
			f[i]=-oo;
			if (y-dH <= 0) f[i]=max(f[i], a[i].sc);
			int t=treeGet(x-dW, x+dW);
			if (t>-oo) f[i]=max(f[i], t+a[i].sc);
		}
		fori(i,k,j-1)
			if (f[i]>-oo) {
				treeUpdate(a[i].fr.sc, f[i], 1);
				if (a[i].fr.fr+dH >= H)
					ans=max(ans, f[i]);
			}
		pnext=j;
	}
	cout << ans << endl;

	return 0;
}