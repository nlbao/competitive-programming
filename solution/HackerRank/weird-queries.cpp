#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>
// #include <random>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
// #define for_each(it, X) for(auto it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;
const double EPSILON = 1e-7;


struct Treap {
	int prior, cnt, value;
	bool rev;
	Treap *l, *r;

	Treap(int _value = 0) {
		prior = (rand() << 16) | rand();
		cnt = 1;
		value = _value;
		rev = false;
		l = r = NULL;
	}
};
typedef Treap* pTreap;


int n, nQ, m;
pTreap root[2];
int tmp[MAX_N];


inline int getCnt(pTreap p) {	return p ? p->cnt : 0;	}

inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = getCnt(p->l) + getCnt(p->r) + 1;
}

inline void push(pTreap p) {
	if (p && p->rev) {
		p->rev = false;
		swap(p->l, p->r);
		if (p->l) p->l->rev ^= true;
		if (p->r) p->r->rev ^= true;
	}
}


void merge(pTreap &p, pTreap u, pTreap v) {
	push(u);
	push(v);
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upNode(p);
}


void split(pTreap p, pTreap &u, pTreap &v, int key, int add = 0) {
	push(p);
	if (!p) u = v = NULL;
	else {
		int pKey = add + getCnt(p->l);
		if (key <= pKey)
			split(p->l, u, p->l, key, add), v = p;
		else
			split(p->r, p->r, v, key, pKey+1), u = p;
	}
	upNode(u);
	upNode(v);
}


void insert(pTreap &p, int key, int value) {
	pTreap newNode = new Treap(value), u, v;
	split(p, u, v, key);
	merge(p, u, newNode);
	merge(p, p, v);
}


void reverse(pTreap &p, int x, int y) {
	if (x >= y) return;
	pTreap t1, t2, t3;
	split(p, t1, t2, x);
	split(t2, t2, t3, y-x+1);
	t2->rev ^= true;
	merge(p, t1, t2);
	merge(p, p, t3);
}


void erase(pTreap &p) {
	if (!p) return;
	erase(p->l);
	erase(p->r);
	delete p;
	p = NULL;
}


void printValue(pTreap p) {
	if (!p) return;
	push(p);
	printValue(p->l);
	tmp[m++] = p->value;
	printValue(p->r);
}


void query_2(pTreap &p, int l1, int r1, int l2, int r2) {
	pTreap t1, t2, t3, t4, t5;
	split(p, t1, t2, l1);
	split(t2, t2, t3, r1-l1+1);
	split(t3, t3, t4, l2-r1-1);
	split(t4, t4, t5, r2-l2+1);
	merge(p, t1, t4);
	merge(p, p, t3);
	merge(p, p, t2);
	merge(p, p, t5);
}


void query_3(pTreap &p, pTreap &q, int l, int r) {
	pTreap u1, u2, u3, v1, v2, v3;
	split(p, u1, u2, l);
	split(u2, u2, u3, r-l+1);
	split(q, v1, v2, l);
	split(v2, v2, v3, r-l+1);
	merge(p, u1, v2);
	merge(p, p, u3);
	merge(q, v1, u2);
	merge(q, q, v3);
}

//////////////////////////////////////////////////////////////////////////////

inline double sqr(double x) {	return x*x;	}

struct Point {
	double x, y;

	Point(double x = -1, double y = -1) : x(x), y(y) {};
	void operator = (const Point &p) {
		x = p.x, y = p.y;
	}
	bool operator < (const Point &p) const {
		if (fabs(x-p.x) > EPSILON)
			return x < p.x;
		return y > p.y;
	}
	Point subtract(const Point &p) const {
		return Point(x-p.x, y-p.y);
	}
	double distance(const Point &p) const {
		return sqrt(sqr(x-p.x) + sqr(y-p.y));
	}
	double cross(const Point &p) const {
		return x*p.y - y*p.x;
	}
	double norm() const {
		return sqr(x) + sqr(y);
	}
};


struct Circle {
	Point center;
	double r;

	Circle() {
		center = Point(-1, -1);
		r = -1;
	}
	Circle(const Point &p, double _r) {
		center = p;
		r = _r;
	}
	bool contains(const Point &p) const {
		return center.distance(p) <= r + EPSILON;
	}
	bool contains(const vector<Point> &ps) const {
		for_each(p, ps)
			if (!contains(*p))
				return false;
		return true;
	}
};


Circle makeDiameter(const Point &a, const Point &b) {
	return Circle(Point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0), a.distance(b) / 2.0);
}


Circle makeCircumcircle(const Point &a, const Point &b, const Point &c) {
	double d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2;
	if (fabs(d) < EPSILON)
		return Circle();
	double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
	double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
	Point p(x, y);
	return Circle(p, p.distance(a));
}


Circle makeCircleTwoPoints(vector<Point> points, const Point &p, const Point &q) {
	Circle temp = makeDiameter(p, q);
	if (temp.contains(points))
		return temp;

	Circle left, right;
	for (int i = 0, sz = points.size(); i < sz; ++i) {
		Point r = points[i];
		Point pq = q.subtract(p);
		double cross = pq.cross(r.subtract(p));
		Circle c = makeCircumcircle(p, q, r);
		if (c.r < 0)
			continue;
		else if (cross > 0 && (left.r < 0 || pq.cross(c.center.subtract(p)) > pq.cross(left.center.subtract(p))))
			left = c;
		else if (cross < 0 && (right.r < 0 || pq.cross(c.center.subtract(p)) < pq.cross(right.center.subtract(p))))
			right = c;
	}

	if (left.r < 0 && right.r < 0) {
		Point a = p, b = p;
		if (q < a) a = q;
		if (b < q) b = q;
		for (int i = 0, sz = points.size(); i < sz; ++i) {
			if (points[i] < a) a = points[i];
			if (b < points[i]) b = points[i];
		}
		return makeDiameter(a, b);
	}

	return (right.r < 0 || (left.r >= 0 && left.r <= right.r)) ? left : right;
}


Circle makeCircleOnePoint(vector<Point> points, Point p) {
	Circle c(p, 0);
	for (int i = 0, sz = points.size(); i < sz; ++i) {
		Point q = points[i];
		if (!c.contains(q)) {
			if (fabs(c.r) < EPSILON)
				c = makeDiameter(p, q);
			else
				c = makeCircleTwoPoints(vector<Point>(points.begin(), points.begin()+i+1), p, q);
		}
	}
	return c;
}


Circle makeCircle(vector<Point> points) {
	random_shuffle(points.begin(), points.end());
	Circle c;
	for (int i = 0, sz = points.size(); i < sz; ++i) {
		Point p = points[i];
		if (c.r < 0 || !c.contains(p))
			c = makeCircleOnePoint(vector<Point>(points.begin(), points.begin()+i+1), p);
	}
	return c;
}


double query_4(int x, int y) {
	vector<Point> points;
	pTreap t1, t2, t3;

	m = 0;
	split(root[0], t1, t2, x);
	split(t2, t2, t3, y-x+1);
	printValue(t2);
	for (int i = 0; i < m; ++i)
		points.push_back(Point(tmp[i], -1));
	merge(root[0], t1, t2);
	merge(root[0], root[0], t3);

	m = 0;
	split(root[1], t1, t2, x);
	split(t2, t2, t3, y-x+1);
	printValue(t2);
	for (int i = 0; i < m; ++i)
		points[i].y = tmp[i];
	merge(root[1], t1, t2);
	merge(root[1], root[1], t3);

	return makeCircle(points).r;
}


int main() {
#ifdef DEBUG
	freopen("weird-queries0.in", "r", stdin);
	freopen("weird-queries.out", "w", stdout);
#endif
	srand(time(NULL));
	scanf("%d%d", &n, &nQ);
	for (int k = 0; k < 2; ++k) {
		root[k] = NULL;
		for (int i = 0; i < n; ++i)
			insert(root[k], i, read());
	}

	while (nQ--) {
		int t = read();
		if (t == 1) {
			int id, l, r;
			scanf("%d%d%d", &id, &l, &r);
			reverse(root[id], l-1, r-1);
		}
		else if (t == 2) {
			int id, l1, r1, l2, r2;
			scanf("%d%d%d%d%d", &id, &l1, &r1, &l2, &r2);
			query_2(root[id], l1-1, r1-1, l2-1, r2-1);
		}
		else if (t == 3) {
			int l, r;
			scanf("%d%d", &l, &r);
			query_3(root[0], root[1], l-1, r-1);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			double ans = query_4(l-1, r-1);
			printf("%.2lf\n", ans);
		}
	}

	for (int k = 0; k < 2; ++k)
		erase(root[k]);
	return 0;
}