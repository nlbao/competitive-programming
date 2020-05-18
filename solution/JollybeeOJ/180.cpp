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


map<string, int> gmt;


// parse a string by delimiter
inline vector<string> parse(const string &s, char delim) {
	vector<string> a;    stringstream ss(s);    string x;
	while (getline(ss, x, delim)) a.push_back(x);
	return a;
}


inline int toMinute(const string &s) {
	int n=sz(s), i=0, h=0, m=0;
	while (i<n && isdigit(s[i])) h=h*10+s[i++]-'0';	++i;
	while (i<n && isdigit(s[i])) m=m*10+s[i++]-'0';	++i;
	return h*60+m;
}


inline int toGMT(const string &s) {
	int n=sz(s), i=0, g=0, p=1;
	while (i<n && !isdigit(s[i])) {
		if (s[i]=='-') p=-1;
		++i;
	}
	while (i<n && isdigit(s[i])) g=g*10+s[i++]-'0';
	return g*p;
}


int main() {
#ifdef DEBUG
	freopen("180.in", "r", stdin);
	freopen("180.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n=read();
	fori(i,1,n) {
		string s, t;
		cin >> s >> t;
		gmt[s]=toGMT(t);
	}

	int nTest=read();
	string line;
	getline(cin, line);
	fori(testid,1,nTest) {
		getline(cin, line);
		vector<string> l=parse(line, ' ');
		string a=l[0], b=l[2];
		int ta=toMinute(l[1]);
		int tb=toMinute(l[3]);
		int d=0;
		if (sz(l)>4) {
			if (l[4][0]=='+') d=1;
			else d=-1;
		}
		tb += d*24*60;
		tb -= (gmt[b]-gmt[a])*60;
		tb -= ta;
		int h=tb/60, m=tb%60;
		cout << "Case #" << testid << ": " << h << " hours and " << m << " minutes" << endl;
	}

	return 0;
}