#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define forr(i,a,b) for (__typeof(b) i=(a); i!=(b)+((a)<(b)?1:-1); i+=((a)<(b)?1:-1))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 11;
// const int n=9;


int n=9;
string s;
int c[MAX_N], a[MAX_N][MAX_N];


bool solve() {
	forr(i,1,n) {
		filla(c, 0);
		forr(j,1,n) if((++c[a[i][j]])>1) return 0;
		filla(c, 0);
		forr(j,1,n) if((++c[a[j][i]])>1) return 0;
	}
	for (int x=1; x<=7; x+=3) for (int y=1; y<=7; y+=3) {
		filla(c, 0);
		forr(i,x,x+2) forr(j,y,y+2) if ((++c[a[i][j]])>1) return 0;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100676D.in", "r", stdin);
	freopen("100676D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	//cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	forr(testid,1,nTest) {
		forr(i,1,n) {
			cin >> s;
			forr(j,1,n) a[i][j]=s[j-1]-'0';
		}
		if (solve()) cout << "Valid\n";
		else cout << "Invalid\n";
	}

	return 0;
}