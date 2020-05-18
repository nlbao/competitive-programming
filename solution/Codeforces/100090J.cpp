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


const int MAX_N = 4e5+5;


int n;
int a[MAX_N], l[MAX_N], r[MAX_N];


inline void insert(int x, int value) {
	a[++n]=value;
	int y=r[x];
	r[x]=n;
	l[n]=x;
	l[y]=n;
	r[n]=y;
}


int main() {
#ifdef DEBUG
	freopen("100090J.in", "r", stdin);
	freopen("100090J.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int p;
	cin >> n >> p;
	fori(i,1,n) cin >> a[i];
	fori(i,1,n) {
		l[i]=i-1;
		r[i]=i+1;
	}
	l[1]=r[n]=0;

	int nQ=read(), x;
	string s;
	while (nQ--) {
		cin >> s;
		if (s=="print") cout << a[p] << endl;
		else if (s=="moveLeft") p = l[p] ? l[p] : p;
		else if (s=="moveRight") p = r[p] ? r[p] : p;
		else {
			cin >> x;
			if (s=="insertLeft") {
				if (l[p]) insert(l[p], x);
				else {
					a[++n]=x;
					l[n]=0;
					r[n]=p;
					l[p]=n;
				}
			}
			else insert(p, x);
		}
	}

	return 0;
}