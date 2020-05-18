// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


void quickSort(vector<int> &a, int l, int r) {
	if (l >= r) return;
	int pivot = a[l + rand()%(r-l)];
	int i = l, j = r;
	do {
		while (i < r && a[i] < pivot) ++i;
		while (j > l && a[j] > pivot) --j;
		if (i <= j) {
			swap(a[i], a[j]);
			++i;	--j;
		}
	} while (i <= j);
	quickSort(a, l, j);
	quickSort(a, i, r);
}


void insertionSort(vector<int> &a, int l, int r) {
	for (int i = l; i <= r; ++i) {
		for (int j = i+1; j <= r; ++j)
			if (a[j] < a[i])
				swap(a[i], a[j]);
	}
}


/*
  |--------------------------|
           unsorted
  |-----|------|-------------|
  sorted  swap     sorted
  |-----|--------------------|
  unsorted	    sorted
  |--|--|--------------------|
    s  w          s
*/
const int THRESHOLD = 10;

void merge(vector<int> &a, int l, int x, int y, int r);

void mergeSort_inplace(vector<int> &a, int l, int r) {
	int len = r-l+1;
	if (len < 2) return;
	if (len < THRESHOLD) {
		insertionSort(a, l, r);
		return;
	}

	/*
		|----|-----|------------------|
		l    x     y                  r
	*/
	int len2 = len/2, len4 = len/4;
	int x = l+len4-1;
	int y = r-len2;
	mergeSort_inplace(a, l, x);
	mergeSort_inplace(a, y+1, r);
	merge(a, l, x, y, r);
}

void merge(vector<int> &a, int l, int x, int y, int r) {
	/*
		|-----|-----|------------------|
		l (s) x (w) y       (s)        r
		[l, x], [x+1, y], [y+1, r]
		len([x+1, y]) >= len([l, x])
	*/
	int len4 = x-l+1;
	int pos = y-len4+1, k = pos;
	int i = l, j = y+1;
	while (i <= l && j <= r) {
		if (i <= l && j <= r) {
			if (a[i] < a[j]) swap(a[pos], a[i]), ++pos, ++i;
			else swap(a[pos], a[j]), ++pos, ++j;
		}
		else {
			while (i <= l) swap(a[pos], a[i]), ++pos, ++i;
			while (j <= r) swap(a[pos], a[j]), ++pos, ++j;
		}
	}
	/*
		|-----|------------------------|
		l     k 					   r
		[k, r] is sorted
	*/
	if (k-l < 1) return;
	if (k-l < THRESHOLD) {
		insertionSort(a, l, k-1);
		int len = k-l;
		int tmp[len];
		for (int i = l; i < k; ++i)
			tmp[i-l] = a[i];
		int pos = l, i = 0, j = k;
		while (i<len && j<=r) {
			if (i<len && j<=r) {
				if (a[i] < a[j]) a[pos++] = tmp[i++];
				else a[pos++] = a[j++];
			}
			else {
				while (i<len) a[pos++] = tmp[i++];
				while (j<=r) a[pos++] = a[j++];
			}
		}
		return;
	}
	/*
		|--|--|------------------------|
		l  x  k 					   r
		[l, x], [x+1, k-1], [k, r]
	*/
	len4 = (k-l)/2;
	x = l+len4-1;
	y = k-1;
	mergeSort_inplace(a, l, x);
	merge(a, l, x, y, r);
}

int main() {
#ifdef DEBUG
	freopen("TSORT.in", "r", stdin);
	freopen("TSORT.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	srand(time(NULL));

	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	// sort(a.begin(), a.end());
	// quickSort(a, 0, n-1);
	// insertionSort(a, 0, n-1);
	mergeSort_inplace(a, 0, n-1);


	for (int i = 0; i < n; ++i)
		cout << a[i] << endl;

	return 0;
}