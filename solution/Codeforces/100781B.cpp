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


const int MAX_N = 8+4;
const int MAX_P = 5e4+4;


int n, nP, nUse, limit;
int a[MAX_N], b[MAX_N], p[MAX_P][MAX_N];
int  f[MAX_P], d[MAX_P];
bool ok[MAX_P];
// map<string, int> id;
vector<int> e[MAX_P];


void gen() {
	nP=0;
	fori(i,1,n) a[i]=i;
	do {
		++nP;
		// string s="";
		fori(i,1,n) {
			p[nP][i]=a[i];
			// s+=char('0'+a[i]);
		}
		// id[s]=nP;
		// cout << s << endl;
	}
	while (next_permutation(a+1, a+1+n));
}


inline bool check(int x, int y) {
	fori(i,1,n) {
		a[p[x][i]]=i;
		b[p[y][i]]=i;
	}
	fori(i,1,n) if (abs(a[i]-b[i])>1) return 0;
	return 1;
}


inline void printP(int x) {
	fori(i,1,n) cout << p[x][i] << " ";
	cout << endl;
}


void buildEdge(int l, int r) {
	fori(i,l,r) {
		fori(j,i+1,r) {
			if (!check(i, j)) continue;
			e[i].pb(j);
			e[j].pb(i);
		}
	}
}

bool tryf(int nF) {
	if (nF>nUse) return 1;
	int u=f[nF-1];
	// cout << nF << " " << u << endl;
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) continue;
		// cout << "	" << v << endl;
		if (v>limit) continue;
		f[nF]=v;
		ok[v]=0;
		if (tryf(nF+1)) return 1;
		ok[v]=1;
		f[nF]=-1;
	}
	return 0;
}


bool checkAns() {
	fori(i,1,nP-1) if (!check(f[i], f[i+1])) return 0;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100781B.in", "r", stdin);
	freopen("100781B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	gen();

	if (n==1) {
		printP(1);
		return 0;
	}
	if (n==2) {
		printP(1);
		printP(2);
		return 0;
	}

	// int NOT_USE[] = {13, 14, 17, 18, 16, 9, 7, 8, 11, 21, 19, 20, 23, 24, 22, 12, 10, 15};
	// int NOT_USE[] = {1, 2, 5, 6, 4, 3};
	int NOT_USE[] =  {1, 2, 5, 6, 4, 3, 13, 14, 17, 18, 16, 9, 7, 8, 11, 21, 19, 20, 23, 24, 22, 12, 10, 15};
	int nNotUse = sizeof(NOT_USE) / sizeof(int);
	limit = 80;
	nUse = nP - nNotUse;
	nUse = min(nUse, limit - nNotUse);

	buildEdge(1, nP);

	filla(f, -1);
	filla(ok, 1);
	fori(i,0,nNotUse-1) ok[NOT_USE[i]]=0;
	f[0]=NOT_USE[nNotUse-1];
	ok[f[0]]=0;
	tryf(1);

	// if (!checkAns()) {
	// 	cout << "WRONG ANSWER!!!!" << endl;
	// 	return 0;
	// }
	fori(i,1,nP) cout << f[i] << endl;


	return 0;
}