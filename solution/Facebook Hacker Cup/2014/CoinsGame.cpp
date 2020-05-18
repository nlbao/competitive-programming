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

const int MAX_N = 2*int(1e6)+6;
const int oo = 2*MAX_N;


int solve(int n, int k, int c) {
	if (n > k) return oo;
	if (n == k) return c;
	if (c <= n) return c;
	int d = k/n, r = k%n;
	int res = d*n;
	if (c <= res) return c;
	c -= res;
	res += n-r;
	res += c;
	return res;
}


int main() {
#ifdef DEBUG
	freopen("CoinsGame.txt", "r", stdin);
	freopen("CoinsGame.out", "w", stdout);
#endif
	int nTest = read();
	foru(test_id, 1, nTest) {
		int n, k, c;
		scanf("%d%d%d", &n, &k, &c);
		int res = oo;
		rep(i, n)
			res = min(res, i + solve(n-i, k, c));
		printf("Case #%d: %d\n", test_id, res);
	}
	return 0;
}