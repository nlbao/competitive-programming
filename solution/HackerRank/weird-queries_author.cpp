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
#include <assert.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
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

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

inline double sqr(double x) {	return x*x;	}

struct Point {
    ld x, y;
    Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

    Point operator - (const Point& b) const {
        return Point(x - b.x, y - b.y);
    }

    Point operator + (const Point& b) const {
        return Point(x + b.x, y + b.y);
    }

    Point operator * (const ld& b) const {
        return Point(x * b, y * b);
    }

    bool operator == (const Point& b)const {
        return abs(x - b.x) < EPSILON && abs(y - b.y) < EPSILON;
    }

    bool operator < (const Point& b) const {
        if(abs(x - b.x) > EPSILON)
            return x < b.x;
        return y < b.y;
    }
};


ld dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

ld cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ld dist(const Point& a, const Point& b){
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

ld det(ld a, ld b, ld c, ld d){
    return a * d - b * c;
}

bool inter(ld A1, ld B1, ld C1, ld A2, ld B2, ld C2, Point& res) {
    ld dt = det(A1, B1, A2, B2),
       dx = -det(C1, B1, C2, B2),
       dy = -det(A1, C1, A2, C2);
    if(abs(dt) < EPSILON)
        return false;
    res.x = dx / dt,
    res.y = dy / dt;
    return true;
}

pair<Point, ld> circle(const Point& a, const Point& b, const Point& c) {
    Point m1 = (a + b) * 0.5,
          m2 = (a + c) * 0.5,
          v1 = b - a,
          v2 = c - a;
    Point o;
    assert(inter(v1.x, v1.y, -dot(v1, m1), v2.x, v2.y, -dot(v2, m2), o));
    return make_pair(o, dist(o, a));
}

pair<Point, ld> min_circle(vector<Point> p, Point q, Point w) {
    pair<Point, ld> ans((q + w) * 0.5, dist(q, w) * 0.5);
    for (int i = 0, sz = (int)p.size(); i < sz; ++i)
        if (dist(ans.first, p[i]) > ans.second + EPSILON)
            ans = circle(p[i], q, w);
    return ans;
}

pair<Point, ld> min_circle(vector<Point> p, Point q) {
    pair<Point, ld> ans((p[0] + q) * 0.5, dist(p[0], q) * 0.5);
    for (int i = 1, sz = (int)p.size(); i < sz; ++i)
        if(dist(ans.first, p[i]) > ans.second + EPSILON)
            ans = min_circle(vector<Point>(p.begin(), p.begin() + i), p[i], q);
    return ans;
}

pair<Point, ld> min_circle(vector<Point> p) {
    if(p.empty())
        return pair<Point, ld>();
    if(sz(p) == 1)
        return make_pair(p[0], 0);
    random_shuffle(all(p));
    pair<Point, ld> ans((p[0] + p[1]) * 0.5, dist(p[0], p[1]) * 0.5);
    for (int i = 2, sz = (int)p.size(); i < sz; ++i)
        if(dist(ans.first, p[i]) > ans.second + EPSILON)
            ans = min_circle(vector<Point>(p.begin(), p.begin() + i), p[i]);
    return ans;
}


void printValue(pTreap p) {
	if (!p) return;
	push(p);
	printValue(p->l);
	tmp[m++] = p->value;
	printValue(p->r);
}


ld query_4(int x, int y) {
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

	// sort(points.begin(), points.end());
	// points.erase(unique(points.begin(), points.end()), points.end());
	return min_circle(points).second;
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
			printf("%.2lf\n", (double)ans);
		}
	}

	for (int k = 0; k < 2; ++k)
		erase(root[k]);
	return 0;
}