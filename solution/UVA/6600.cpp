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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_M = 7;
const int MAX_N = MAX_M * MAX_M;
const ld EPS = 1e-9;
const int dx[8] = {-1, -1, -1, 0, +1, +1, +1, 0};
const int dy[8] = {-1, 0, +1, +1, +1, 0, -1, -1};


const int BASE = 10000;
typedef vector <int> BigInt;

BigInt toBigInt(const string &t) {
    string s = "";
    int l = 0, r = t.length()-1;
    while (l <= r && !isdigit(t[l])) ++l;
    while (l <= r && !isdigit(t[r])) --r;
    if (l > r) s = "0";
    else s = string(t.begin()+l, t.begin()+r+1);
    BigInt a;
    if (s.size() == 0) { a.push_back(0); return a; }
    while (s.size() % 4 != 0) s = '0' + s;
    for (int i = 0, sz = s.size(); i < sz; i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++)
            value = value * 10 + (s[i + j] - '0');
        a.insert(a.begin(), value);
    } return a;
}

BigInt toBigInt(ll x) {
    char s[22];
    snprintf(s, sizeof(s), "%lld", x);
    return toBigInt(string(s));
}

void Print(const BigInt &a) {
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
}

BigInt operator + (const BigInt &a, const BigInt &b) {
    BigInt c; int carry = 0;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n || i < m; i++) {
        if (i < n) carry += a[i];
        if (i < m) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}

BigInt operator - (const BigInt &a, const BigInt &b) {
    BigInt c; int carry = 0;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++) {
        int s = a[i] - carry;
        if (i < m) s -= b[i];
        if (s < 0) s += BASE, carry = 1; else carry = 0;
        c.push_back(s);
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}

BigInt operator * (const BigInt &a, const int mul) {
    BigInt c; int carry = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        carry += a[i] * mul; c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}

BigInt operator * (const BigInt &a, const BigInt &b) {
    BigInt c(a.size() + b.size() + 5, 0);
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = 0; j < m; j++) {
            int k = i + j; c[k] += a[i] * b[j] + carry;
            carry = c[k] / BASE; c[k] %= BASE;
        }
        if (carry) c[i + b.size()] += carry;
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}

bool operator < (BigInt a, BigInt b) {
    while (a.size() && *a.rbegin() == 0) a.pop_back();
    while (b.size() && *b.rbegin() == 0) b.pop_back();
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

BigInt operator / (const BigInt &a, const BigInt &b) {
    BigInt c, t;
    for (int i = a.size() - 1; i >= 0; i--) {
        t.insert(t.begin(), a[i]);
        int lo = 1, hi = BASE - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (t < (b * mid)) hi = mid - 1; else lo = mid + 1;
        } c.insert(c.begin(), hi); t = t - (b * hi);
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}


const BigInt ZERO = toBigInt(0);


struct Fraction {
	BigInt a, b;

	Fraction(BigInt _a = ZERO, BigInt _b = ZERO) {
		a = _a;
		b = _b;
		reduce();
	}

	void reduce() {
		if (a == ZERO) b = 1;
		if (b < ZERO) a = -a, b = -b;
		BigInt d = gcd(abs(a), b);
		a = a/d, b = b/d;
	}

	Fraction operator + (const Fraction &other) const {
		BigInt g = lcm(b, other.b);
		return Fraction(g/b*a + g/other.b*other.a, g);
	}

	Fraction operator - (const Fraction &other) const {
		BigInt g = lcm(b, other.b);
		return Fraction(g/b*a - g/other.b*other.a, g);
	}

	Fraction operator * (const Fraction &other) const {
		BigInt d1 = gcd(abs(a), other.b);
		BigInt d2 = gcd(abs(other.a), b);
		return Fraction((a/d1)*(other.a/d2), (b/d2)*(other.b/d1));
	}

	Fraction operator / (const Fraction &other) const {
		BigInt d1 = gcd(abs(a), abs(other.a));
		BigInt d2 = gcd(other.b, b);
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

	// friend istream& operator >> (istream &in, Fraction &frac) {
	// 	in >> frac.a;
	// 	char ch = in.get();
	// 	if (ch == '/') in >> frac.b;
	// 	else frac.b = 1;
	// 	return in;
	// }

	// friend ostream& operator << (ostream &out, const Fraction &frac) {
	// 	out << frac.a;
	// 	if (frac.b != 1) out << "/" << frac.b;
	// 	return out;
	// }

	// friend Fraction abs(const Fraction &frac) {
	// 	return Fraction(abs(frac.a), abs(frac.b));
	// }
};


vector< vector<ld> > a;
int id[MAX_N][MAX_N];


inline ld xabs(ld x) {
	return x < 0 ? -x : x;
}


ld determinant(vector< vector<ld> > &a, int n) {
	ld det = 1.0;
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i; j < n; j++)
			if (xabs(a[j][i]) > xabs(a[k][i]))
				k = j;
		if (xabs(a[k][i]) < EPS) {
			det = 0;
			break;
		}
		swap(a[i], a[k]);
		if (i != k) det *= -1;
		det *= a[i][i];
		for (int j = i + 1; j < n; j++)
			a[i][j] /= a[i][i];
		for (int j = 0; j < n; j++)
			if (j != i && xabs(a[j][i]) > EPS)
				for (int k = i + 1; k < n; k++)
					a[j][k] -= a[i][k] * a[j][i];
	}
	return det;
}


int main() {
#ifdef DEBUG
	freopen("6600.in", "r", stdin);
	freopen("6600.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int m = read();
		int n = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				id[i][j] = n++;
		a.clear();
		a.resize(n);
		for (int i = 0; i < n; ++i)
			a[i].resize(n, 0);

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j) {
				int u = id[i][j];
				for (int k = 0; k < 8; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if (x < 0 || x >= m || y < 0 || y >= m) continue;
					int v = id[x][y];
					++a[u][u];
					a[u][v] = -1;
				}
			}

		ll ans = roundl(determinant(a, n-1));
		printf("%lld\n", ans);
	}
	return 0;
}