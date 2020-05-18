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

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }



const int MAX_N = 1003;


int m, n, back, res;

int a[MAX_N];	// a[i] is the "height" of a "increasing column" [i], such that
				// each element [j] on column [i] is >= the element [j] on column [i-1]
				// i.e., a[i] is numbers of continuous elements h[x][k]
				// with k >= i and x is a constant,
				// such that h[x][k] >= h[x][k-1]	(1)
				// and h[x][k] >= h[x-1][k]			(2)

int b[MAX_N];	// b[i] is the "height" of a "increasing column" [i],
				// the condition (2) of a[i] above is not necessary.

int h[MAX_N], preH[MAX_N], q[MAX_N];
int pLeft[MAX_N], pRight[MAX_N];



void update(int i) {
	while (back && (i >= n || a[q[back]] > a[i])) {
		int k = q[back--];
		pRight[k] = i-1;
		// update res
		int l1 = pLeft[k];
		int r1 = pRight[k];
			// if (l1-1): the previous column of l1 is "higher" than l1,
			// then it will be the left-most edge of the rectangle.
			// Because the left-most edge doesn't need to satisfy the condition (2) of a[i].
		if (l1 && b[l1-1] >= a[k]) --l1;
		res = max(res, a[k]*(r1-l1+1));
			// choose only column k
		res = max(res, b[k]);
	}
	if (back == 0) pLeft[i] = 0;
	else {
		int k = q[back];
		if (a[k] == a[i]) k  = pLeft[k];
		else ++k;
		pLeft[i] = k;
	}
	q[++back] = i;
}



int main() {
#ifdef DEBUG
	freopen("NKGOLF.inp", "r", stdin);
	freopen("NKGOLF.out", "w", stdout);
#endif
	res = 0;
	fill(h, 0);
	fill(a, 0);
	fill(b, 0);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &h[j]);
			if (i && h[j] >= preH[j]) ++a[j], ++b[j];
			else a[j] = b[j] = 1;
			if (j && h[j] < h[j-1]) a[j] = 0;	// not satisfy the condition (2)
			preH[j] = h[j];
		}
		// update deque
		back = 0;
		for (int j = 0; j <= n; ++j)
			update(j);
	}
	printf("%d\n", res);
	return 0;
}