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

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+5;
const ll oo = ll(1e9);


struct Line {
	ll a, b;
	ll leftX, leftY;
	Line() {}
	Line(ll a, ll b, ll leftX, ll leftY): a(a), b(b), leftX(leftX), leftY(leftY) {}
	ll val(ll h) {return a*h + b;}
};


int n, K;
int top[2], front[2];
Line q[2][MAX_N];
int w[MAX_N];
ll s[MAX_N], g[MAX_N];


void add(int id, ll a, ll b) {
	while (top[id] > 0 && q[id][top[id]].leftY > a*q[id][top[id]].leftX + b)
		--top[id];
	ll x = ceil(double(b-q[id][top[id]].b)/double(q[id][top[id]].a-a));
	q[id][++top[id]] = Line(a, b, x, a*x+b);
	front[id] = min(front[id], top[id]);
}


ll find(int id, ll h) {
	while (front[id] < top[id] && q[id][front[id]+1].leftX <= h)
		++front[id];
	return q[id][front[id]].val(h);
}


int main() {
#ifdef DEBUG
	freopen("NKLEAVES.in", "r", stdin);
	freopen("NKLEAVES.out", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	for (int i = n; i >= 1; --i)
		w[i] = read();
	s[0] = g[0] = 0;
	for (ll i = 1; i <= n; ++i) {
		s[i] = s[i-1] + ll(w[i]);
		g[i] = g[i-1] + i*ll(w[i]);
	}

	// init
	ll f = 0;
	int t = 0;
	top[0] = top[1] = 0;
	front[0] = front[1] = 0;
	q[0][0] = q[1][0] = Line(0, 0, -oo, -oo);
	// solve
	for (int x = 1; x <= K; ++x) {
		int tt = 1-t;
		top[tt] = front[tt] = 0;
		for (int i = 1; i <= n; ++i) {
			f = ll(i)*s[i] - g[i] + find(t, i);
			add(tt, -s[i], g[i] + f);
		}
		t = tt;
	}
	cout << f << endl;
	return 0;
}