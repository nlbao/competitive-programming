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


const int MAX_N = int(1e5)+5;

int n, nPrime;
int a[MAX_N], p[MAX_N];
int minDivisor[MAX_N], prime[MAX_N];
vector<pair<int,int> > res;


int find(int i, int j) {
	// i > j
	int l = 0, r = nPrime-1, res = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		int t = i-prime[mid]+1;
		if (t >= j) {
			res = t;
			l = mid+1;
		}
		else r = mid-1;
	}
	return res;
}


void swapPoint(int i, int j) {
	res.push_back(make_pair(j, i));
	swap(p[a[i]], p[a[j]]);
	swap(a[i], a[j]);
}


int main() {
#ifdef DEBUG
	freopen("432C.in", "r", stdin);
	freopen("432C.out", "w", stdout);
#endif
	// generate primes
	nPrime = 0;
	fill(minDivisor, 0);
	for (ll i = 2; i < MAX_N; ++i) {
		if (minDivisor[i] == 0)
			prime[nPrime++] = minDivisor[i] = i;
		for (int j = 0; j < nPrime && prime[j] <= minDivisor[i]; ++j) {
			ll x = ll(prime[j])*i;
			if (x > MAX_N) break;
			minDivisor[x] = prime[j];
		}
		// if (minDivisor[i] == i)
		// 	cout << i << endl;
	}

	// read input
	int n = read();
	for (int i = 0; i < n; ++i) {
		a[i] = read();
		p[a[i]] = i;
	}

	// solve
	res.clear();
	for (int x = 1; x <= n; ++x) {
		// cout << "		" << x << " " << p[x] << endl;
		int i = p[x], dest = x-1;
		while (i != dest) {
			int j = find(i, dest);
			swapPoint(i, j);
			i = j;
		}
	}

	// print result
	int sz = res.size();
	printf("%d\n", sz);
	for (int i = 0; i < sz; ++i)
		printf("%d %d\n", res[i].first+1, res[i].second+1);
	return 0;
}