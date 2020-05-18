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

const int MAX_N = 1003;

int a[MAX_N];


void solve(int s, int n) {
	if (n < 1) return;
	ll d = s/n, r = s%n;
	rep(i, n) a[i] = d;
	rep(i, r) ++a[i];
	rep(i, n) printf("%d ", a[i]);
}


int main() {
#ifdef DEBUG
	freopen("369B.in", "r", stdin);
	freopen("369B.out", "w", stdout);
#endif
	int n, k, l, r, sall, sk;
	cin >> n >> k >> l >> r >> sall >> sk;
	solve(sk, k);
	solve(sall-sk, n-k);
	return 0;
}