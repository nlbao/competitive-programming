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

inline ll sqr(ll x) {	return x*x;	}


struct Point {
	ll x, y;
	Point (){}
	Point (ll x, ll y):x(x), y(y) {}
	bool operator / (Point oth){
		return (ll)(x) * oth.y - (ll)(y) * oth.x > 0;
	}

	ll operator ^ (Point oth) {
		return (ll)(x) * oth.y - (ll)(y) * oth.x;
	}

	Point operator - (Point oth) {
		return Point(x - oth.x, y - oth.y);
	}

	ll distance(const Point &a) const {
		return sqr(1LL*a.x-x)+sqr(1LL*a.y-y);
	}

	bool operator < (const Point& b) const {
		return y<b.y;
	}
};

bool fitInRange(Point o, Point a, Point b) {
	if (a.x > b.x) swap(a.x, b.x);
	if (a.y > b.y) swap(a.y, b.y);
	return a.x <= o.x && o.x <= b.x && a.y <= o.y && o.y <= b.y;
}

bool onSeg(Point o, Point a, Point b) {
	return !((b - o) ^ (a - o)) && fitInRange(o, a, b);
}

bool inPolygon(Point o, Point *p, int n) {
	bool ret = 0;
	fori(i,0,n-1) {
		Point a = p[i], b = p[(i + 1) % n];
		if (onSeg(o, a, b)) return 1;
		if (a.y > b.y) swap(a, b);
		ret ^= a.y != b.y && a.y != o.y && a.y <= o.y && o.y <= b.y && ((b - a) / (o - a));
	}
	return ret;
}


const int MAX_N = 2e4+44;
const int MAX_X = 1e6;


Point points[MAX_N], poly[MAX_N];
int bestIDs[MAX_N];
ll bestDists[MAX_N];


struct Rect {
	int x1, y1, x2, y2;

	Rect() : x1(0), y1(0), x2(-1), y2(-1) {}
	Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

	inline bool isNull() const  {	return x1>x2 || y1>y2;		}
	inline bool isPoint() const {	return x1==x2 && y1==y2;	}

	inline bool contains(const Point &a) const {
		return (x1 <= a.x && a.x <= x2) && (y1 <= a.y && a.y <= y2);
	}

	inline ll lenX() const {	return x1<=x2 ? x2-x1 : 0;	}
	inline ll lenY() const {	return y1<=y2 ? y2-y1 : 0;	}

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

};



const int MAX_nPOINTS_IN_NODE = 100;


typedef struct Node* pNode;
struct Node {
	vector<int> ids;
	Rect bounds;
	pNode children[4];
	// ll minDistToEdge[4];

	Node() {
		fori(i,0,3) children[i] = 0; //, minDistToEdge[i]=oo;
	}
	Node(const Rect &r) {
		bounds = r;
		ids.clear();
		fori(i,0,3) children[i] = 0; //, minDistToEdge[i]=oo;
	}

	inline bool isLeaf() const {
		fori(i,0,3) if (children[i]) return 0;
		return 1;
	}

	void insert(int newID) {
		Point p = points[newID];
		if (bounds.isNull() || !bounds.contains(p)) return;
		//   0
		// 3   1
		//   2
		// fori(i,0,3) {
		// 	minDistToEdge[0] = min(minDistToEdge[0], bounds.y2 - p.y);
		// 	minDistToEdge[1] = min(minDistToEdge[1], bounds.x2 - p.x);
		// 	minDistToEdge[2] = min(minDistToEdge[2], p.y - bounds.y1);
		// 	minDistToEdge[3] = min(minDistToEdge[3], p.x - bounds.x1);
		// }
		ids.pb(newID);
		if (bounds.isPoint()) return;
		if (!isLeaf() || sz(ids) > MAX_nPOINTS_IN_NODE) {
			if (isLeaf()) {
				vector<Rect> subBounds = bounds.divideTo4Parts();
				fori(i,0,3) if (!subBounds[i].isNull())
					children[i] = new Node(subBounds[i]);
			}
			fori(i,0,3) if (children[i])
				foreach(it, ids) children[i]->insert(*it);
			ids.clear();
		}
		return;
	}


	ll distToPoint(const Point &p) const {
		if (isLeaf() && ids.empty()) return oo;
		// if (bounds.contains(p)) return 0;
		return bounds.distToPoint(p);

		// ll ans = bounds.distToPoint(p);

		// ll ans = oo, tmp = bounds.distToPoint(p);
		// if (p.y >= bounds.y2) ans = min(ans, p.y - bounds.y2 + minDistToEdge[0]);
		// if (p.x >= bounds.x2) ans = min(ans, p.x - bounds.x2 + minDistToEdge[1]);
		// if (p.y <= bounds.y1) ans = min(ans, bounds.y1 - p.y + minDistToEdge[2]);
		// if (p.x <= bounds.x1) ans = min(ans, bounds.x1 - p.x + minDistToEdge[3]);
		// if (ans < oo) ans = sqr(ans);
		// ans = max(ans, tmp);

		// ll s = oo;
		// fori(i,0,3) s = min(s, minDistToEdge[i]);
		// if (s < oo) s += tmp;
		// ans = max(ans, s);

		// return ans;
	}


	void find_K_NearestPoints(int K, const Point &p) const {
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
		fori(i,0,3) a[i] = pll(children[i] ? children[i]->distToPoint(p) : oo, i);
		sort(a, a+4);
		fori(i,0,3) if (children[a[i].sc]) {
			if (a[i].fr > bestDists[K]) break;
			children[a[i].sc]->find_K_NearestPoints(K, p);
		}
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
	fori(testid,1,nTest) {
		cout << "Case #" << testid << ":\n";
		cin >> n;
		fori(i,1,n) cin >> points[i].x >> points[i].y;

		cin >> nR;
		fori(rid,1,nR) {
			cout << "Region " << rid << endl;
			cin >> nP;
			fori(i,0,nP-1) cin >> poly[i].x >> poly[i].y;

			remove(root);
			root = new Node(Rect(0, 0, MAX_X, MAX_X));
			fori(i,1,n) if (inPolygon(points[i], poly, nP)) {
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