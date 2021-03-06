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


const int MAX_N = 22;


int main() {
#ifdef DEBUG
	freopen("100186I.in", "r", stdin);
	freopen("100186I.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n, limit;
	string s;
	cin >> limit >> n;
	cin >> s;
	int ans=0, c[2];
	c[0]=c[1]=0;
	fori(turn,0,n-1) {
		if (turn>0) ++c[s[turn-1]-'0'];
		int len=n-turn;
		if (c[0]==limit-1 && c[1] < limit-1) continue;
		if (c[1]==limit-1 && c[0] < limit-1) continue;
		if (c[0] > c[1] && c[0]+len == limit) break;
		if (c[1] > c[0] && c[1]+len == limit) break;
		++ans;
	}
	cout << ans << endl;

	return 0;
}
