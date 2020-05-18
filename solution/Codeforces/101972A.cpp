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
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }

typedef tuple<string, string, string> ts;


bool is_special(ll a) {
	a = abs(a);
	while (a >= 10) {
		if ((a % 10) != 0) return false;
		a /= 10;
	}
	return true;
}


vector<ts> get_special_list(int a) {
	vector<ts> ans;
	string s = to_string(a);
	int n = s.length();
	ll p = 1, sign = (a>=0) ? 1 : -1;
	for (int i = n-1; i >= (a>=0?0:1); --i, p *= 10) {
		ll x = ll(s[i])-ll('0');
		ll b = sign*p*x;
		if (is_special(a-b)) {
			if (b == 0) ans.push_back(mt(s, "+", "0"));
			if (a-b != 0) ans.push_back(mt(to_string(a-b), "+", to_string(b)));
		}
		b = sign*p*(10-x);
		if (is_special(a+b)) {
			if (b == 0) ans.push_back(mt(s, "-", "0"));
			if (a+b != 0) ans.push_back(mt(to_string(a+b), "-", to_string(b)));
		}
	}
	return ans;
}


string solve(int a, int b) {
	vector<ts> va = get_special_list(a);
	vector<ts> vb = get_special_list(b);
	foreach(ita, va) {
		string a0 = get<0>(*ita), a1 = get<1>(*ita), a2 = get<2>(*ita);
		foreach(itb, vb) {
			string b0 = get<0>(*itb), b1 = get<1>(*itb), b2 = get<2>(*itb);
			// if (b2 == "0") return a0 + " x " + b0 + " " + a1 + " " + a2 + " x " + b0;
			// if (a2 == "0") return a0 + " x " + b0 + " " + b1 + " " + a0 + " x " + b2;
			// if (a2 == "0" && b2 == "0") return a0 + " x " + b0;
			if (b2 == "0" && a2 != "0") return a0 + " x " + b0 + " " + a1 + " " + a2 + " x " + b0;
			if (a2 == "0" && b2 != "0") return a0 + " x " + b0 + " " + b1 + " " + a0 + " x " + b2;
		}
		if (is_special(a) && is_special(b))
			return to_string(a) + " x " + to_string(b);
	}
	assert(1 == 0);
	return "-1";
}


int main() {
#ifdef DEBUG
	freopen("101972A.in", "r", stdin);
	freopen("101972A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	int a, b;
	while (nTest > 0) {
		--nTest;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}

	return 0;
}