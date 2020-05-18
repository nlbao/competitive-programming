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

const int MAX_N = 3*100005;
const ll BASE = 10007LL;

int n, m, k;
int a[MAX_N], b[MAX_N], len[MAX_N];
ll p[MAX_N], f[MAX_N];
map<int, int> q;
vi res;


ll get_h(ll value) {
	return p[q[value]]*value;
}


int main() {
#ifdef DEBUG
	freopen("367B.in", "r", stdin);
	freopen("367B.out", "w", stdout);
#endif
	p[0] = 1;
	foru(i, 1, MAX_N-1)
		p[i] = p[i-1]*BASE;

	int c = 0;
	scanf("%d%d%d", &n, &m, &k);
	foru(i, 1, n) {
		read(a[i]);
		if (q.find(a[i]) == q.end())
			q[a[i]] = ++c;
	}
	foru(i, 1, m) {
		read(b[i]);
		if (q.find(b[i]) == q.end())
			q[b[i]] = ++c;
	}

	ll pattern = 0;
	foru(i, 1, m) pattern += get_h(b[i]);

	res.clear();
	f[n+1] = 0;
	ford(i, n, 1) {
		f[i] = get_h(a[i]);
		len[i] = 1;
		if (i+k <= n) {
			f[i] += f[i+k];
			len[i] += len[i+k];
			if (len[i] > m) {
				f[i] -= get_h(a[i + m*k]);
				--len[i];
			}
		}
		if (len[i] == m && f[i] == pattern)
			res.pb(i);
	}

	sort(all(res));
	int szRes = sz(res);
	printf("%d\n", szRes);
	rep(i, szRes) printf("%d ", res[i]);
	return 0;
}