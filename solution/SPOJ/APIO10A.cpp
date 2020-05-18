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


const int MAX_N = int(1e6) + 6;
const ll oo = ll(1e9);
const double eps = 1e-9;


struct Line {
	ll a, b;
	ll leftX, leftY;
	Line() {}
	Line(ll a, ll b, ll leftX, ll leftY): a(a), b(b), leftX(leftX), leftY(leftY) {}
	ll val(ll h) {return a*h + b;}
};


int n, m, top, front;
int sum[MAX_N];
Line q[MAX_N];
ll input_a, input_b, input_c;


void add(ll a, ll b) {
	while (top > 0 && q[top].leftY > a*q[top].leftX + b)
		--top;
	ll x = ceil(double(b-q[top].b)/double(q[top].a-a));
	q[++top] = Line(a, b, x, a*x+b);
	front = min(front, top);
}


ll find(ll h) {
	while (front < top && q[front+1].leftX <= h)
		++front;
	return q[front].val(h);
}


ll F(ll x) {return input_a*x*x + input_b*x + input_c;}


ll solve() {
	top = front = 0;
	ll f = input_c;
	q[0] = Line(0, 0, -oo, -oo);
	for (int i = 1; i <= n; ++i) {
		ll x = sum[i];
		f = F(x) - find(x);
		add(2*input_a*x, input_b*x - input_a*x*x - f);
	}
	return f;
}


int main() {
#ifdef DEBUG
	freopen("APIO10A.in", "r", stdin);
	freopen("APIO10A.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		n = read();
		input_a = read();
		input_b = read();
		input_c = read();
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			int x = read();
			sum[i] = sum[i-1] + x;
		}
		printf("%lld\n", solve());
	}
	return 0;
}