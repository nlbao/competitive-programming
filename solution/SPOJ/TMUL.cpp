	// ios_base::sync_with_stdio(false);
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


const int BASE = 10000;
typedef vector<int> BigInt;

BigInt toBigInt(const string &t = "0") {
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


const int MAX_N = 1e4 + 7;

char s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("TMUL.in", "r", stdin);
	freopen("TMUL.out", "w", stdout);
#endif
	BigInt ans, a, b;
	int nTest = read();
	while (nTest--) {
		scanf("%s", s);
		a = toBigInt(string(s));
		scanf("%s", s);
		b = toBigInt(string(s));
		ans = a*b;
		Print(ans);
		printf("\n");
	}
	return 0;
}