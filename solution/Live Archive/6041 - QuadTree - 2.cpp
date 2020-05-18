// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const ll oo = 1e18;
const double EPS = 1e-9;
const double M_PI = acos(-1);

inline int cmp(double a, double b) {
	return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct RealPoint {
	double x, y;
	RealPoint(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	RealPoint operator + (RealPoint a) { return RealPoint(x+a.x, y+a.y); }
	RealPoint operator - (RealPoint a) { return RealPoint(x-a.x, y-a.y); }
	RealPoint operator * (double k) { return RealPoint(x*k, y*k); }
	RealPoint operator / (double k) { return RealPoint(x/k, y/k); }
	double operator * (RealPoint a) { return x*a.x + y*a.y; }
	double operator % (RealPoint a) { return x*a.y - y*a.x; }
	RealPoint conj() { return RealPoint(x, -y); }
	double norm() { return x*x + y*y; }
	double len() { return sqrt(norm()); }
};

int ccw(RealPoint a, RealPoint b, RealPoint c) {
	return cmp((b-a)%(c-a),0);
}

double angle(RealPoint a, RealPoint o, RealPoint b) { // angle AOB
	a = a - o; b = b - o;
	return acos((a * b) / sqrt(a.norm() * b.norm()));
}

double distToLine(RealPoint p, RealPoint a, RealPoint b) {
	RealPoint ap = p - a, ab = b - a;
	double u = (ap * ab) / ab.norm();
	RealPoint c = a + (ab * u);
	return (p-c).len();
}

double distToLineSegment(RealPoint p, RealPoint a, RealPoint b) {
	RealPoint ap = p - a, ab = b - a;
	double u = (ap * ab) / ab.norm();
	if (u < 0.0) return (p - a).len();
	if (u > 1.0) return (p - b).len();
	return distToLine(p, a, b);
}

typedef vector<RealPoint> Polygon;

// Inside polygon: O(N). Works with any polygon.
bool inPolygon(const Polygon &P, RealPoint pt) {
	if ((int)P.size() == 0) return false;
	int n = P.size();
	//////////
	fori(i,0,n-1) if (!cmp(pt.x, P[i].x) && !cmp(pt.y, P[i].y)) return 1;
	fori(i,0,n-1) {
		int j=(i+1)%n;
		if (i==j) continue;
		if (!cmp(distToLineSegment(pt, P[i], P[j]), 0))
			return 1;
	}
	//////////
	double sum = 0;
	for (int i = 0; i < (int)P.size(); i++) {
		RealPoint Pj = P[(i+1) % P.size()];
		if (ccw(pt, P[i], Pj) > 0)
		sum += angle(P[i], pt, Pj);
		else sum -= angle(P[i], pt, Pj);
	}
	return fabs(fabs(sum) - 2*M_PI) < EPS;
}


const int MAX_N = 2e4+44;
const int MAX_X = 1e6;

struct Point {
	ll x, y;
	Point() {}
	Point(ll x, ll y): x(x), y(y) {}

	ll distance(const Point &a) const {
		return sqr(1LL*a.x-x)+sqr(1LL*a.y-y);
	}

	bool operator < (const Point& b) const {
		return y<b.y;
	}
};


Point points[MAX_N];
int bestIDs[MAX_N];
ll bestDists[MAX_N];


struct Rect {
	int x1, y1, x2, y2;

	Rect() {
		x1=0, x2=-1;
		y1=0, y2=-1;
	}
	Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

	bool isNull() const  {	return x1>x2 || y1>y2;		}
	bool isPoint() const {	return x1==x2 && y1==y2;	}

	bool contains(const Point &a) {
		return (x1 <= a.x && a.x <= x2) && (y1 <= a.y && a.y <= y2);
	}

	ll distToPoint(const Point &a) const {
		bool inX = (x1 <= a.x && a.x <= x2);
		bool inY = (y1 <= a.y && a.y <= y2);
		if (inX && inY) return 0;
		ll ans = oo;
		if (inY) ans = min(ans, 1LL*min(abs(x1-a.x), abs(x2-a.x)));
		if (inX) ans = min(ans, 1LL*min(abs(y1-a.y), abs(y2-a.y)));
		if (ans < oo) ans = sqr(ans);
		if (!inX && !inY) {
			ans = min(ans, a.distance(Point(x1, y1)));
			ans = min(ans, a.distance(Point(x1, y2)));
			ans = min(ans, a.distance(Point(x2, y1)));
			ans = min(ans, a.distance(Point(x2, y2)));
		}
		return ans;
	}

	vector<Rect> divideTo4Parts() const {
		// 2 3
		// 0 1
		vector<Rect> ans(4, Rect());
		if (isNull() || isPoint()) return ans;
		int xmid = (x1+x2)/2;
		int ymid = (y1+y2)/2;
		ans[0] = Rect(x1, y1, xmid, ymid);
		ans[1] = Rect(xmid+1, y1, x2, ymid);
		ans[2] = Rect(x1, ymid+1, xmid, y2);
		ans[3] = Rect(xmid+1, ymid+1, x2, y2);
		return ans;
	}
};


typedef struct Node* pNode;
struct Node {
	vector<int> ids;
	Rect bounds;
	pNode children[4];

	Node() {
		fori(i,0,3) children[i] = 0;
	}
	Node(const Rect &r) {
		bounds = r;
		ids.clear();
		fori(i,0,3) children[i] = 0;
	}

	bool isLeaf() {
		bool ok=1;
		fori(i,0,3) if (children[i]) {
			ok=0;
			break;
		}
		return ok;
	}

	bool insert(int newID) {
		Point p = points[newID];
		if (!bounds.contains(p)) return 0;
		ids.pb(newID);
		if (bounds.isPoint()) return 1;
		if (sz(ids)>1) {
			if (isLeaf()) {
				vector<Rect> subBounds = bounds.divideTo4Parts();
				fori(i,0,3) if (!subBounds[i].isNull())
					children[i] = new Node(subBounds[i]);
			}
			fori(i,0,3) if (children[i])
				foreach(it, ids) children[i]->insert(*it);
			ids.clear();
		}
		return 1;
	}

	void find_K_NearestPoints(int K, const Point &p) {
		ll d = bounds.distToPoint(p);
		if (d>bestDists[K]) return;
		foreach(it, ids) {
			ll d = points[*it].distance(p);
			fori(i,1,K) if (d<bestDists[i] || (d==bestDists[i] && *it<bestIDs[i])) {
				ford(j,K,i+1) {
					bestDists[j] = bestDists[j-1];
					bestIDs[j] = bestIDs[j-1];
				}
				bestDists[i] = d;
				bestIDs[i] = *it;
				break;
			}
		}
		pll a[4];
		fori(i,0,3) a[i] = pll(children[i] ? children[i]->bounds.distToPoint(p) : oo, i);
		sort(a, a+4);
		fori(i,0,3) if (children[a[i].sc])
			children[a[i].sc]->find_K_NearestPoints(K, p);
	}
};


void remove(pNode &p) {
	if (!p) return;
	fori(i,0,3) remove(p->children[i]);
	delete p;
}


void findNearestPoints(pNode root, int K, const Point &p) {
	fori(i,1,K) bestDists[i] = oo, bestIDs[i] = 1e9;
	if (root) root->find_K_NearestPoints(K, p);
}


int main() {
#ifdef DEBUG
	freopen("6041.in", "r", stdin);
	freopen("6041.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	pNode root=0;
	int nTest=read(), n, nR, nP, nQ;
	Polygon poly;
	fori(testid,1,nTest) {
		cout << "Case #" << testid << ":\n";
		cin >> n;
		fori(i,1,n) cin >> points[i].x >> points[i].y;

		cin >> nR;
		fori(rid,1,nR) {
			cout << "Region " << rid << endl;
			cin >> nP;
			poly.clear();
			fori(i,1,nP) {
				int x, y;
				cin >> x >> y;
				poly.pb(RealPoint(x, y));
			}

			remove(root);
			root = new Node(Rect(0, 0, MAX_X, MAX_X));
			fori(i,1,n) if (inPolygon(poly, RealPoint(points[i].x, points[i].y))) {
				// cout << "	insert: " << i << ": " << points[i].x << " " << points[i].y << endl;
				root->insert(i);
			}

			cin >> nQ;
			while (nQ--) {
				Point p;
				cin >> p.x >> p.y;
				findNearestPoints(root, 2, p);
				cout << bestIDs[1] << " " << bestIDs[2] << endl;
			}
		}
	}
	remove(root);

	return 0;
}