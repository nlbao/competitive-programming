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

const int MAX_N = 3*int(1e5) + 5;
const int MAX_TREE = 4*MAX_N;
const ll MODULE = int(1e9) + 9;

int n, nQuery, u, v, oldL;
int treeValue[MAX_TREE];
int a[MAX_N], sumA[MAX_N], sumF[MAX_N];
map<int, int> treeIndex[MAX_TREE];
ll ans;


ll mmod(ll x) {
	x %= MODULE;
	if (x < 0)
		return (x+MODULE)%MODULE;
	return x;
}


ll getSumA(int i, int j) {
	return mmod(sumA[j] - sumA[i-1]);
}


ll getSumF(int i, int j) {
	return mmod(sumF[j] - sumF[i-1]);
}


void push(int k, int i, int c) {
	if (treeIndex[k].find(i) == treeIndex[k].end())
		treeIndex[k][i] = c;
	else
		treeIndex[k][i] += c;
}


void update(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		int startF = l-u+1;
		push(k, startF, 1);
		treeValue[k] = mmod(treeValue[k] + getSumF(startF, startF + r - l));
		return;
	}

	int leftChild = k<<1, rightChild = leftChild+1;
	int mid = (l+r)>>1;
	for (map<int, int>::iterator it = treeIndex[k].begin(); it != treeIndex[k].end(); ++it) {
		int start = it->first, c = it->second;
		push(leftChild, start, c);
		treeValue[leftChild] = mmod(treeValue[leftChild] + mmod(c*getSumF(start, start + mid - l)));
		start += mid+1 - l;
		push(rightChild, start, c);
		treeValue[rightChild] = mmod(treeValue[rightChild] + mmod(c*getSumF(start, start + r - mid - 1)));
	}
	treeIndex[k].clear();

	update(leftChild, l, mid);
	update(rightChild, mid+1, r);
	treeValue[k] = mmod(treeValue[leftChild] + treeValue[rightChild]);
}


void get(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		ans = mmod(ans + treeValue[k]);
		return;
	}

	int leftChild = k<<1, rightChild = leftChild+1;
	int mid = (l+r)>>1;
	for (map<int, int>::iterator it = treeIndex[k].begin(); it != treeIndex[k].end(); ++it) {
		int start = it->first, c = it->second;
		push(leftChild, start, c);
		treeValue[leftChild] = mmod(treeValue[leftChild] + mmod(c*getSumF(start, start + mid - l)));
		start += mid+1 - l;
		push(rightChild, start, c);
		treeValue[rightChild] = mmod(treeValue[rightChild] + mmod(c*getSumF(start, start + r - mid - 1)));
	}
	treeIndex[k].clear();

	get(leftChild, l, mid);
	get(rightChild, mid+1, r);
	treeValue[k] = mmod(treeValue[leftChild] + treeValue[rightChild]);
}


int main() {
#ifdef DEBUG
	freopen("447E.in", "r", stdin);
	freopen("447E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQuery);
	a[0] = sumA[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sumA[i] = mmod(sumA[i-1] + a[i]);
	}
	// calF
	a[0] = sumF[0] = 0;
	a[1] = sumF[1] = 1;
	for (int i = 2; i <= n; ++i) {
		a[i] = mmod(a[i-1] + a[i-2]);
		sumF[i] = mmod(sumF[i-1] + a[i]);
	}

	// queries
	for (int id = 0; id < nQuery; ++id) {
		int queryType, l, r;
		scanf("%d%d%d", &queryType, &l, &r);
		u = l;	v = r;
		if (queryType == 1) {
			update(1, 1, n);
		}
		else {
			ans = getSumA(l, r);
			get(1, 1, n);
			printf("%d\n", int(ans));
		}
	}
	return 0;
}