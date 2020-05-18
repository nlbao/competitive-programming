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


const int MAX_N = 2e5+5;


int n;
int a[MAX_N], id[MAX_N], p[MAX_N], d[MAX_N];
queue<int> q;


int main() {
#ifdef DEBUG
	freopen("100090M.in", "r", stdin);
	freopen("100090M.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> a[i];
	filla(id, 0);
	ford(i,n,1) {
		p[i]=id[a[i]];
		id[a[i]]=i;
	}
	filla(d, 0);
	q.push(1);
	while (!q.empty()) {
		int u=q.front();	q.pop();
		if (u==n) break;
		if (d[u+1]==0) {
			d[u+1]=d[u]+1;
			q.push(u+1);
		}
		int v=p[u];
		if (v && d[v]==0) {
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	cout << d[n] << endl;

	return 0;
}