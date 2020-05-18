#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5+5);
const ll oo = ll(1e18);

int n, m;
int a[MAX_N], b[MAX_N];
ll sa[MAX_N], sb[MAX_N];
vector<int> q;


int findA(int value) {
	int l = 0, r = n-1, t = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (a[mid] == value)
			return mid;
		else if (a[mid] < value) {
			t = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return t;
}


int findB(int value) {
	int l = 0, r = m-1, t = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (b[mid] == value)
			return mid;
		else if (b[mid] > value) {
			t = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return t;
}



int main() {
#ifdef DEBUG
	freopen("439D.in", "r", stdin);
	freopen("439D.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		a[i] = read();
		q.push_back(a[i]);
	}
	for (int i = 0; i < m; ++i) {
		b[i] = read();
		q.push_back(b[i]);
	}

	sort(a, a+n);
	sort(b, b+m);
	sa[0] = a[0];
	for (int i = 1; i < n; ++i) sa[i] = sa[i-1] + ll(a[i]);
	sb[m] = 0;
	for (int i = m-1; i >= 0; --i) sb[i] = sb[i+1] + ll(b[i]);

	ll res = oo;
	sort(q.begin(), q.end());
	for (int k = 0, sz = q.size(); k < sz; ++k) {
		ll value = q[k];
		ll i = findA(value), j = findB(value);
		ll tmp = (i+1)*value - sa[i] + sb[j] - (m-j)*value;
		if (tmp >= 0)
			res = min(res, tmp);
	}
	cout << res << endl;
	return 0;
}