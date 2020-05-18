#pragma comment(linker, "/STACK:1024000000")
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


const int MAX_N = 1e5+55;
const int oo = 1e9;


unordered_map<string, pii> ip, net;


inline bool isIPAddress(const string &s) {
	int n=sz(s);
	ford(i,n-1,0) if (s[i]=='/') return 0;
	return 1;
}


inline ll toIP(const string &s) {
	ll ans=0, x=0;
	int len=sz(s);
	fori(i,0,len-1) {
		if (isdigit(s[i])) x=x*10+s[i]-'0';
		if (!isdigit(s[i]) || i==len-1) {
			ans <<= 8;
			ans |= x;
			x = 0;
		}
		if (s[i]=='/') break;
	}
	return ans;
}


string toBinary(ll x) {
	string s;
	while (x>0) {
		s.pb(char(x%2)+'0');
		x/=2;
	}
	reverse(s.begin(), s.end());
	while (sz(s)<32) s="0"+s;
	return s;
}


string remove(const string &s, int c) {
	int n=sz(s);
	return s.substr(0, n-c);
}


int main() {
#ifdef DEBUG
	freopen("100623A.in", "r", stdin);
	freopen("100623A.out", "w", stdout);
#else
	freopen("access.in", "r", stdin);
	freopen("access.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	string s, t, tmp;
	cin >> n;
	fori(i,1,n) {
		cin >> t >> tmp >> s;
		int val=int(t[0]=='a');
		string x = toBinary(toIP(s));
		if (isIPAddress(s)) {
			if (!has(ip, x)) ip[x]=mp(i, val);
		}
		else {
			int k=sz(s)-1, c=0;
			while (s[k]!='/') --k;
			fori(t,k+1,sz(s)-1) c=c*10+s[t]-'0';
			c=32-c;
			string y=remove(x, c);
			if (!has(net, y)) net[y]=mp(i, val);
			// cout << y << endl;
		}
	}

	cin >> n;
	fori(turn,1,n) {
		cin >> s;
		string x=toBinary(toIP(s)), y=x;
		// cout << turn << ": " << x << endl;
		int minPos=oo, minVal;
		if (has(ip, y)) {
			pii u=ip[y];
			if (u.fr<minPos) minPos=u.fr, minVal=u.sc;
		}
		if (has(net, y)) {
			pii u=net[y];
			if (u.fr<minPos) minPos=u.fr, minVal=u.sc;
		}
		fori(i,0,31) {
			y=remove(y, 1);
			if (has(net, y)) {
				pii u=net[y];
				if (u.fr<minPos) minPos=u.fr, minVal=u.sc;
			}
		}
		if (minPos>=oo) cout << "A";
		else cout << ((minVal) ? "A" : "D");
	}

	return 0;
}