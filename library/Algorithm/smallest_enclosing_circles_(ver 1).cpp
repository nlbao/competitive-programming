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