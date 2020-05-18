struct Point {
    ld x, y;
    Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point operator - (const Point& b) const {   return Point(x - b.x, y - b.y); }
    Point operator + (const Point& b) const {   return Point(x + b.x, y + b.y); }
    Point operator * (const ld& b) const {  return Point(x * b, y * b); }
    bool operator == (const Point& b) const {
        return abs(x - b.x) < EPSILON && abs(y - b.y) < EPSILON;
    }
    bool operator < (const Point& b) const {
        if(abs(x - b.x) > EPSILON)
            return x < b.x;
        return y < b.y;
    }
};

ld dot(const Point& a, const Point& b) {    return a.x * b.x + a.y * b.y;   }
ld cross(const Point& a, const Point& b) {  return a.x * b.y - a.y * b.x;   }
ld dist(const Point& a, const Point& b) {   return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));   }
ld det(ld a, ld b, ld c, ld d) { return a * d - b * c;  }

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