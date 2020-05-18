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

const int MAX_N = 3*int(1e4)+4;

string a, b;
set<ll> sa, sb;


char getNext(char ch, int base) {
	int x = ch-'0';
	x = (x+1)%base;
	return char(x + '0');
}


void add(const string &a, ll base, set<ll> &s) {
	int n = a.length();
	ll value = 0, p = 1;
	for (int i = n-1; i >= 0; --i) {
		ll x = a[i] - '0';
		value += x*p;
		p *= base;
	}
	s.insert(value);
}


int main() {
#ifdef DEBUG
	freopen("831.in", "r", stdin);
	freopen("831.out", "w", stdout);
#endif
	getline(cin, a);
	getline(cin, b);

	if (a[0] == '0') {
		a[0] = '1';
		add(a, 2, sa);
	}
	else {
		int n = a.length();
		for (int i = 0; i < n; ++i) {
			char tmp = a[i];
			a[i] = getNext(a[i], 2);
			if (i != 0 || a[i] != '0')
				add(a, 2, sa);
			a[i] = tmp;
		}
	}
	if (b[0] == '0') {
		b[0] = '1';
		add(b, 3, sb);
		b[0] = '2';
		add(b, 3, sb);
	}
	else {
		int n = b.length();
		for (int i = 0; i < n; ++i) {
			char tmp = b[i];
			for (int k = 0; k < 2; ++k) {
				b[i] = getNext(b[i], 3);
				if (i == 0 && b[i] == '0') continue;
				add(b, 3, sb);
			}
			b[i] = tmp;
		}
	}

	ll ans = -1;
	for_each(it, sa) {
		ll x = *it;
		if (sb.find(x) != sb.end()) {
			ans = x;
			break;
		}
	}
	cout << ans;
	return 0;
}