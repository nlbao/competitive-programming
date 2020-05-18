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


#define mmod(x, M) (((x)%M+M)%M)


const int MAX_N = 2022;
const int MAX_S = 1e7+7;
const int LIMIT = MAX_S+1000;
const int MAX_F = 4*MAX_N;
const ll oo = 2e18;


int n, nSlot, crrPos, value;
int a[MAX_N];
int id[MAX_S], q[MAX_S];
pii minF[MAX_F];
ll f[MAX_N], cTime;


void build(int k, int l, int r) {
	if (l>r) return;
	if (l==r) {
		minF[k]=pii(a[l],l);
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	build(kl, l, mid);
	build(kr, mid+1, r);
	minF[k]=min(minF[kl], minF[kr]);
}


void remove(int k, int l, int r) {
	if (l>crrPos || r<crrPos) return;
	if (l==r) {
		minF[k]=pii(LIMIT, -1);
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	remove(kl, l, mid);
	remove(kr, mid+1, r);
	minF[k]=min(minF[kl], minF[kr]);
}


pii getLeft(int k, int l, int r) {
	if (l>r || a[l]>value) return pii(LIMIT, -1);
	if (a[r]<=value) return minF[k];
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return min(getLeft(kl, l, mid), getLeft(kr, mid+1, r));
}


pii getRight(int k, int l, int r) {
	if (l>r || a[r]<value) return pii(LIMIT, -1);
	if (a[l]>=value) return minF[k];
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return min(getRight(kl, l, mid), getRight(kr, mid+1, r));
}


inline int findNext(int x) {
	value=x;
	pii u=getRight(1,1,n);
	if (u.fr<LIMIT) return u.sc;
	u=getLeft(1,1,n);
	if (u.fr<LIMIT) return u.sc;
	return -1;
}


ll cal(int pos) {
	ll ans=0, sum=0;
	build(1,1,n);
	while (1) {
		int k=findNext(mmod(pos+sum, nSlot));
		if (k<1) break;
		int p=mmod(a[k]-sum, nSlot);
		if (p==pos) {
			ans += cTime;
			sum = mmod(sum + cTime, nSlot);
			crrPos = k;
			remove(1,1,n);
		}
		else {
			int t = mmod(p-pos, nSlot);
			ans += t;
			sum = mmod(sum + t, nSlot);
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6960.in", "r", stdin);
	freopen("6960.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	while (cin >> n) {
		cin >> nSlot >> cTime;
		fori(i,1,n) cin >> a[i];
		sort(a+1,a+1+n);
		fori(i,1,n) f[i]=cal(a[i]);

		fori(i,0,nSlot) id[i]=0;
		int l=1, r=0;
		fori(i,1,n) if (!id[a[i]]) {
			id[a[i]]=i;
			q[++r]=a[i];
		}
		while (l<=r) {
			int u=q[l++];
			int v=mmod(u-1, nSlot);
			if (!id[v]) {
				id[v]=id[u];
				q[++r]=v;
			}
		}

		ll minCost=oo, maxCost=0, sumCost=0;
		fori(i,0,nSlot-1) {
			int p=id[i];
			ll cost=f[p] + mmod(a[p]-i, nSlot);
			minCost=min(minCost, cost);
			maxCost=max(maxCost, cost);
			sumCost+=cost;
		}
		cout << minCost << endl;
		cout << maxCost << endl;
		ll d=__gcd(sumCost, ll(nSlot));
		if (d) {
			sumCost /= d;
			nSlot /= d;
		}
		cout << sumCost << "/" << nSlot << endl;
	}

	return 0;
}