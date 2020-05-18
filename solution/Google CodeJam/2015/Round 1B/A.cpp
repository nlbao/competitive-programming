#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e6 + 6;


int len;
string s;
int f[MAX_N];


string to_string(ll n) {
	ostringstream ss;
	ss << n;
	return ss.str();
}


ll rev() {
	ll ans = 0;
	for (int i = len-1; i >= 0; --i)
		ans = ans*10LL + ll(s[i]-'0');
	return ans;
}


ll pre() {
	ll ans = 0;
	for (int i = 0; i < len-1; ++i)
		ans = ans*10LL + 9;
	return ans;
}


ll solve(ll n) {
	if (n <= 20) return n;
	s = to_string(n);
	len = s.length();

	if (s[len-1] != '0') {
		ll d = ll(s[len-1] - '0') - 1;
		char tmp = s[len-1];
		s[len-1] = '1';
		ll t = rev();
		if (n > t) return 1 + solve(t) + d;
		s[len-1] = tmp;
	}

	if (s[0] == '1') {
		ll t = pre();
		return n-t + solve(t);
	}
	else {
		if (s[len-1] == '0') return 1 + solve(n-1);

		ll d = ll(s[len-1] - '0') - 1;
		s[len-1] = '1';

		ll t = rev();
		if (n > t) return 1 + solve(t) + d;
		else return 1 + solve(n-1);

		// ll ans;
		// if (n > t) ans = 1 + solve(t);
		// else ans = n;
		// return min(ans, 1 + solve(n-1));
	}
}


ll solve_0(ll n) {
	return f[n];
}


void init_0() {
	for (int i = 1; i < MAX_N; ++i) f[i] = i;
	for (int x = 12; x < MAX_N; ++x) {
		s = to_string(x);
		len = s.length();
		int y = x + 1;
		if (y < MAX_N) f[y] = min(f[y], f[x]+1);
		y = rev();
		if (y < MAX_N) f[y] = min(f[y], f[x]+1);
	}
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	init_0();

	for (int i = 1; i < MAX_N; ++i) {
		int u = solve_0(i), v = solve(i);
		// cout << ".... " << i << endl;
		if (u != v) {
			cout << "!!!!! " << i << endl;
			cout << u << " " << v << endl;
			break;
		}
	}
	return 0;


	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		ll n;
		scanf("%lld", &n);
		// ll ans = solve(n);
		ll ans = solve(n);
		printf("Case #%d: %lld\n", testid, ans);
	}
	return 0;
}