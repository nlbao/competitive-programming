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


int solve(int n, int m) {
	int l = 1, r = n, res = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		double x = mid;
		double f = 0.5*x*x - (1.0*n + 0.5)*x + (double)(n+m);
		if (f <= 0) {
			res = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return res;
}


int main() {
#ifdef DEBUG
	freopen("clique.in", "r", stdin);
	freopen("clique.out", "w", stdout);
#endif
	int nTest = read();
	rep(test_id, nTest) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", solve(n, m));
	}
	return 0;
}