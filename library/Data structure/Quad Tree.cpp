// live archive 6041

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