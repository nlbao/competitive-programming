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


const int MAX_N = 111;
const int MINUTES_PER_WEEK = 10080;

int n;
ll L;
string names[MAX_N];
int prices[MAX_N];


// parse a string by delimiter
inline vector<string> parse(const string &s, char delim) {
	vector<string> a;    stringstream ss(s);    string x;
	while (getline(ss, x, delim)) a.push_back(x);
	return a;
}


int check(int idx, const string &s) {
	vector<string> a = parse(s, ',');
	names[idx] = a[0];
	prices[idx] = atoi(a[1].c_str());
	ll c = atoi(a[2].c_str());
	ll t = atoi(a[3].c_str());
	ll r = atoi(a[4].c_str());
	// cout << name << " : " << p << " " << c << " " << t << " " << r << endl;
	ll tmp = t*c;
	ll x = L / tmp;
	while (x*tmp < L) ++x;
	ll S = L - (x-1)*tmp, m = 0;
	while (S > 0) {
		++m;
		S -= c;
	}
	ll cost = 1LL*(x-1)*t + m + x*r;
	if (cost <= MINUTES_PER_WEEK) return prices[idx];
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("101933H.in", "r", stdin);
	freopen("101933H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> L >> n;
	string s;
	getline(cin, s);
	int minPrice = -1;
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		int p = check(i, s);
		if (p > 0)
			if (minPrice < 0 || p < minPrice)
				minPrice = p;
	}
	if (minPrice < 0) cout << "no such mower" << endl;
	else
		for (int i = 0; i < n; ++i)
			if (prices[i] == minPrice)
				cout << names[i] << endl;

	return 0;
}