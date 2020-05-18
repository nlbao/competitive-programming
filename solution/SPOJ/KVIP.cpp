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

const int MAX_N = int(1e3);
const ll oo = ll(1e12);

int n;
ll c[MAX_N][MAX_N], s[MAX_N], f[MAX_N][2];


int main() {
#ifdef DEBUG
	freopen("KVIP.in", "r", stdin);
	freopen("KVIP.out", "w", stdout);
#endif
	read(n);
	foru(i, 1, n)
		foru(j, 1, n)
			c[i][j] = read();

	s[0] = 0;
	foru(i, 1, n) s[i] = s[i-1] + c[i][i];

	foru(i, 1, n)
		rep(j, 2) f[i][j] = -oo;
	f[0][0] = f[0][1] = 0;
	f[1][1] = 0;
	foru(i, 1, n) {
		if (i == 1) f[i][0] = c[1][1];
		else f[i][0] = max(f[i-1][0] + c[i][i], f[i][1] + c[i][1]);
		foru(j, i+1, n)
			f[j][1] = max(f[j][1], f[i][1] + s[j-1] - s[i] + c[i][j]);
	}
	cout << f[n][0] << endl;
	return 0;
}