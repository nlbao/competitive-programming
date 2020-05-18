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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6+6;

string s;
int f[MAX_N];


bool match(char a, char b) {
	if (a == '(' && b == ')') return true;
	if (a == '[' && b == ']') return true;
	if (a == '{' && b == '}') return true;
	return false;
}


int solve() {
	int ans = 0;
	int n = s.length();
	filla(f, 0);
	stack<int> stk;
	for (int i = 0; i < n; ++i) {
		int x = s[i];
		if (x == '(' || x == '[' || x == '{') {
			stk.push(i);
			continue;
		}
		if (stk.empty()) continue;
		int k = stk.top();
		char ch = s[k];
		if (match(ch, x)) {
			stk.pop();
			f[i] = i-k+1;
			if (k>0) f[i] += f[k-1];
			ans = max(ans, f[i]);
		}
		else {
			while (!stk.empty()) stk.pop();
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("Parentheses.in", "r", stdin);
	freopen("Parentheses.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid <= nTest; ++testid) {
		cin >> s;
		cout << "Case #" << testid << endl;
		cout << solve() << endl;
	}

	return 0;
}