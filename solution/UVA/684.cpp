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

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 33;


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

	friend Fraction abs(const Fraction &frac) {
		return Fraction(abs(frac.a), abs(frac.b));
	}
};


vector< vector<Fraction> > a;


ll determinant(vector< vector<Fraction> > a) {
	int n = a.size();
	Fraction det(1, 1);
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i; j < n; j++)
			if (abs(a[j][i]) > abs(a[k][i]))
				k = j;
		if (a[k][i].a == 0) {
			det = Fraction(0, 1);
			break;
		}
		swap(a[i], a[k]);
		if (i != k)
			det.a = -det.a;
		det = det * a[i][i];
		for (int j = i + 1; j < n; j++)
			a[i][j] = a[i][j] / a[i][i];
		for (int j = 0; j < n; j++)
			if (j != i && a[j][i].a != 0)
				for (int k = i + 1; k < n; k++)
					a[j][k] = a[j][k] - (a[i][k] * a[j][i]);
	}
	return det.a;
}


int main() {
#ifdef DEBUG
	freopen("684.in", "r", stdin);
	freopen("684.out", "w", stdout);
#endif
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		a.clear();
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(n);
			for (int j = 0; j < n; ++j)
				scanf("%lld", &a[i][j].a);
		}
		printf("%lld\n", determinant(a));
	}
	printf("*\n");
	return 0;
}