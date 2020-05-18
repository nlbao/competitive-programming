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
const ll oo = ll(1e18);
const double eps = 1e-8;

struct Point {
	double x, y;
	Point(){}
	Point(double xx, double yy) {x=xx; y=yy;}
};

struct Line {
	ll a, b;
	Line(){}
	Line(ll aa, ll bb) {a=aa; b=bb;}
	double val(double x) const {
		return a*x + b;
	}
};

struct Vertex {
	Line line;
	Point point;
};

int n, m;
Vertex hull[MAX_N];
int u[MAX_N], v[MAX_N];


Point intersect(const Line &m, const Line &n) {
	if (m.a == n.a)
		return Point(-oo, -oo);
	double x = (m.b-n.b)/(n.a-m.a);
	return Point(x, m.val(x));
}

double d(const Line &line, const Point &point) {
	if (point.x <= -oo) return -oo;
	return point.y - line.val(point.x);
}


ll find(double h) {
	int l = 0, r = m, t = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (hull[mid].point.x <= h) {
			t = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return hull[t].line.val(h);
}

void add(ll a, ll b) {
	Line tmp(a, b);
	while (m > 0 && d(tmp, hull[m].point) > -eps)
		--m;
	hull[++m].line = tmp;
	hull[m].point = intersect(hull[m-1].line, hull[m].line);
}


int main() {
#ifdef DEBUG
	freopen("319C.in", "r", stdin);
	freopen("319C.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < n; ++i) u[i] = read();
	for (int i = 0; i < n; ++i) v[i] = read();

	m = 0;
	hull[0].point = Point(-oo, -oo);
	hull[0].line = Line(v[0], 0);
	ll f = 0;
	for (int i = 1; i < n; ++i) {
		f = find(u[i]);
		add(v[i], f);
	}
	cout << f << endl;
	return 0;
}