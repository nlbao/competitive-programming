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


const int MAX_N = 255;
const int MOD = 10;

int n;
string s;
int a[MAX_N], c[MAX_N];


#define mmod(x) (((x%MOD)+MOD)%MOD)


bool check(int len, int val) {
	fori(i,1,n) c[i]=0;
	int t=0;
	fori(i,1,n) {
		if (i<=n-len+1) {
			int x=mmod(val-a[i]-t);
			t=mmod(t+x);
			c[i+len-1]+=x;
		}
		if (mmod(a[i]+t) != val)
			return 0;
		t=mmod(t-c[i]);
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100712I.in", "r", stdin);
	freopen("100712I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> s;
		n=sz(s);
		fori(i,1,n) a[i]=s[i-1]-'0';
		int ans=1;
		ford(k,n,2) {
			fori(x,0,9)
				if(check(k, x)) {
					ans=k;
					break;
				}
			if (ans>1) break;
		}
		cout << ans << endl;
	}

	return 0;
}