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

const int MAX_N = 3003;

int n, m;
int a[MAX_N], p[MAX_N];


int calF() {
	int res = 0;
	int ta[MAX_N], tp[MAX_N];
	for (int i = 1; i <= n; ++i) {
		ta[i] = a[i];
		tp[i] = p[i];
	}
	for (int x = 1; x <= n; ++x) {
		if (tp[x] == x) continue;
		++res;
		swap(ta[tp[x]], ta[x]);
		tp[ta[tp[x]]] = tp[x];
		tp[ta[x]] = x;
	}
	return res;
}


int main() {
#ifdef DEBUG
	freopen("441D.in", "r", stdin);
	freopen("441D.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		p[a[i]] = i;
	}
	m = read();

	int f = calF();
	if (f == m) {
		printf("0");
		return 0;
	}

	vector<int> res;
	if (f > m) {
		f -= m;
		for (int i = 1; i <= n && f; ++i, --f) {
			if (a[i] == i) continue;
			int j = min(p[i], a[i]);
			res.push_back(i);
			res.push_back(j);
			swap(a[i], a[j]);
			p[a[i]] = i;
			p[a[j]] = j;
		}
	} else {
		f = m-f;
		for (int i = 1; i < n && f; ++i, --f) {

			cout << "		" << i << endl;
			cout << "		";
			for (int k = 1; k <= n; ++k) cout << a[k] << " ";	cout << endl;
			cout << "		";
			for (int k = 1; k <= n; ++k) cout << p[k] << " ";	cout << endl;

			int j;
			if (a[i] == i) j = i+1;
			else
				for (int k = i+1; k <= n; ++k)
					if (a[k] == k) {
						j = k;
						break;
					}
			res.push_back(i);
			res.push_back(j);
			swap(a[i], a[j]);
			p[a[i]] = i;
			p[a[j]] = j;
		}
	}

	int sz = res.size();
	printf("%d\n", sz/2);
	for (int i = 0; i < sz; ++i)
		printf("%d ", res[i]);
	return 0;
}