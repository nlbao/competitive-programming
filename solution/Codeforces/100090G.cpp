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


const int MAX_K = 33;


string s;
int c[MAX_K];
bool ok[MAX_K];


int main() {
#ifdef DEBUG
	freopen("100090G.in", "r", stdin);
	freopen("100090G.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	string s;
	cin >> s;
	int n=sz(s);
	if (n>('z'-'a'+1)) cout << "IMPOSSIBLE";
	else {
		filla(ok, 1);
		filla(c, 0);
		fori(i,0,n-1) ok[s[i]-'a']=0;
		int k=0;
		fori(i,0,n-1) {
			int x=s[i]-'a';
			++c[x];
			if (c[x]==1) continue;
			else {
				while (k < MAX_K && !ok[k]) ++k;
				ok[k]=0;
				c[k]=1;
				s[i]=char('a'+k);
			}
		}
		cout << s << endl;
	}

	return 0;
}