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

const int MAX_N = int(1e6)+6;

ll n, x;
int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("MIKE2.in", "r", stdin);
	freopen("MIKE2.out", "w", stdout);
#endif
	cin >> n >> x;
	rep(i, n) a[i] = read();
	sort(a, a+n);

	int res1 = n, res2 = 0;
	rep(i, n) {
		ll t = (a[i]>>1) + (a[i]&1);
		if (x < t) break;
		x -= t;
		a[i] -= t;
		--res1;
	}
	rep(i, n) {
		if (x < a[i]) break;
		x -= a[i];
		++res2;
	}
	printf("%d %d\n", res1, res2);
	return 0;
}