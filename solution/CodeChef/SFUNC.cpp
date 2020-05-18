#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


ll n, m, k;


ll gcd(ll a, ll b) {
	if (a == 0 || b == 0) return a + b;
	return gcd(b, a%b);
}



ll mpow(ll x, ll n) {
	if (n < 1) return 1;
	if (n == 1) return x%m;
	ll t = mpow(x, n>>1);
	t = (t*t)%m;
	if (n&1LL) t = (t*x)%m;
	return t;
}



ll phi(ll n) {
	ll res = n;
	for (ll i = 2; i*i <= n; ++i)
		if (n%i == 0) {
			res -= res/i;
			while (n%i == 0) n /= i;
		}
	return res;
}



void solve_0() {
	ll res = 0;
	for (ll i = 1; i < n; ++i)
		if (gcd(i, n) == 1)
			res = (res + mpow(i, k))%m;
	cout << res << endl;
}




int main() {
#ifdef DEBUG
	freopen("SFUNC.in", "r", stdin);
	freopen("SFUNC.out", "w", stdout);
#endif
	cin >> n >> k >> m;

	// s[1] = ((phi(n)*n)>>1)
	n = 100;
	ll s = 0;
	for (int i = 1; i < n; ++i)
		if (gcd(i, n) == 1) {
			s += i;
			cout << i << endl;
		}
	cout << endl << s << endl << ((phi(n)*n)>>1) << endl;

	
	
	return 0;
}