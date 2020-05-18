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
#include <iomanip>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const ll oo = 1e9;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
	return abs(x / gcd(x, y) * y);
}

struct Fraction {
	ll a, b;

	Fraction(ll _a = 0, ll _b = 1) {
		a = _a;
		b = _b;
		reduce();
	}

	void reduce() {
		if (a == 0) b = 1;
		if (b < 0) a = -a, b = -b;
		ll d = gcd(abs(a), b);
		a /= d, b /= d;
	}

	Fraction operator + (const Fraction &other) const {
		ll g = lcm(b, other.b);
		return Fraction(g/b*a + g/other.b*other.a, g);
	}

	Fraction operator - (const Fraction &other) const {
		ll g = lcm(b, other.b);
		return Fraction(g/b*a - g/other.b*other.a, g);
	}

	Fraction operator * (const Fraction &other) const {
		ll d1 = gcd(abs(a), other.b);
		ll d2 = gcd(abs(other.a), b);
		return Fraction((a/d1)*(other.a/d2), (b/d2)*(other.b/d1));
	}

	Fraction operator / (const Fraction &other) const {
		ll d1 = gcd(abs(a), abs(other.a));
		ll d2 = gcd(other.b, b);
		return Fraction((a/d1)*(other.b/d2), (b/d2)*(other.a/d1));
	}

	bool operator < (const Fraction &other) const {
		return a*other.b < b*other.a;
	}

	bool operator > (const Fraction &other) const {
		return a*other.b > b*other.a;
	}

	bool operator == (const Fraction &other) const {
		return a*other.b == b*other.a;
	}

	friend istream& operator >> (istream &in, Fraction &frac) {
		in >> frac.a;
		char ch = in.get();
		if (ch == '/') in >> frac.b;
		else frac.b = 1;
		return in;
	}

	friend ostream& operator << (ostream &out, const Fraction &frac) {
		out << frac.a;
		if (frac.b != 1) out << "/" << frac.b;
		return out;
	}

	friend Fraction abs(const Fraction &frac) {
		return Fraction(abs(frac.a), abs(frac.b));
	}
};

const Fraction ZERO = Fraction(0, 1);


vector< vector<Fraction> > a;
vector<Fraction> ans;


int gauss(vector< vector<Fraction> > &a, vector<Fraction> &ans, int &rank) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int k = row;
		for (int i = row+1; i < n; ++i)
			if (abs(a[i][col]) > abs(a[k][col]))
				k = i;
		if (a[k][col].a == 0) continue;

		for (int i = col; i <= m; ++i)
			swap(a[k][i], a[row][i]);
		for (int i = 0; i < n; ++i)
			if (i != row) {
				Fraction c = a[i][col] / a[row][col];
				for (int j = col+1; j <= m; ++j)
					a[i][j] = a[i][j] - (a[row][j] * c);
				a[i][col] = ZERO;
			}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (a[i][j].a != 0) {
				zero = false;
				break;
			}
		if (zero && a[i][m].a != 0)
			return 0;
	}

	rank = 0;
	ans.assign(m, ZERO);
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (a[i][j].a != 0) {
			ans[j] = a[i][m] / a[i][j];
			++i, ++rank;
		}
	if (rank < m) return oo;	// arbitrary constants = m - rank
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("10109.in", "r", stdin);
	freopen("10109.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	bool firstTest = true;
	int testID, nX, nEquation, rank;
	while (true) {
		cin >> testID;
		if (testID == 0) break;
		cin >> nX >> nEquation;

		a.clear();
		a.resize(nEquation);
		for (int i = 0; i < nEquation; ++i) {
			a[i].resize(nX+1, ZERO);
			for (int j = 0; j <= nX; ++j)
				cin >> a[i][j];
		}

		int nSolution = gauss(a, ans, rank);

		if (firstTest) firstTest = false;
		else cout << '\n';

		cout << "Solution for Matrix System # " << testID << '\n';
		if (nSolution == 0)
			cout << "No Solution." << '\n';
		else if (nSolution >= oo)
			cout << "Infinitely many solutions containing " << nX-rank << " arbitrary constants." << '\n';
		else {
			for (int i = 0; i < nX; ++i)
				cout << "x[" << i+1 << "] = " << ans[i] << '\n';
		}
	}
	return 0;
}