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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


int n, nQ;
map<ll, ll> valD[2], sD[2];
map<pii, ll> valCell;
ll finalAns;


void change(int k, int i, ll val) {
	int kk=k^1;
	// remove
	ll t=valD[k][i];
	if (sD[k][t]>0) {
		--sD[k][t];
		finalAns -= sD[kk][t];
	}
	// add
	++sD[k][val];
	finalAns += sD[kk][val];
	valD[k][i]=val;
}


int main() {
#ifdef DEBUG
	freopen("TOPOVI.in", "r", stdin);
	freopen("TOPOVI.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll dSize = read();
	ll nSize = sqr(dSize);
	cin >> n >> nQ;
	finalAns=nSize;
	sD[0][0]=sD[1][0]=dSize;
	fori(i,1,n) {
		int x, y, val;
		cin >> x >> y >> val;
		change(0,x,valD[0][x]^val);
		change(1,y,valD[1][y]^val);
		valCell[mp(x,y)]=val;
	}

	while (nQ--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		pii u=mp(x1,y1), v=mp(x2,y2);
		ll tVal=valCell[u];

		ll tx=valD[0][x1]^tVal, ty=valD[1][y1]^tVal;
		change(0,x1,tx);
		change(1,y1,ty);
		valCell[u]=0;

		tx=valD[0][x2]^tVal, ty=valD[1][y2]^tVal;
		change(0,x2,tx);
		change(1,y2,ty);
		valCell[v]=tVal;

		cout << nSize-finalAns << endl;
	}

	return 0;
}