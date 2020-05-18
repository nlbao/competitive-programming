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

const int MAX_N = 505;
const int MAX_L = 250005;

int n, m;
ll a[MAX_N][MAX_N];
int x[MAX_L], y[MAX_L];


bool ok(int x, int y) {
	return !(x < 0 || x > n || y < 0 || y > m);
}



int main() {
#ifdef DEBUG
	freopen("MIKE1.in", "r", stdin);
	freopen("MIKE1.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	foru(i, 1, n)
		foru(j, 1, m)
			a[i][j] = read();
	int l = read();
	rep(i, l) scanf("%d%d", &x[i], &y[i]);

	ll e1 = 0, e2 = 0;
	rep(i, l) {
		if (e1 >= 0)
			if (ok(x[i], y[i])) e1 += a[x[i]][y[i]];
			else e1 = -1;
		if (e2 >= 0)
			if (ok(y[i], x[i])) e2 += a[y[i]][x[i]];
			else e2 = -1;
	}
	cout << max(e1, e2) << endl;
	return 0;
}