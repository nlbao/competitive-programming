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

const int MAX_N = 2003;

int n, x;
bool ok[MAX_N];
vector<pair<pair<int, int>, int> > a;



int solve(int t) {
	fill(ok, true);
	int res = 0, h = x;
	for (int k = 0; k < n; ++k) {
		int maxM = 0, id = -1;
		for (int i = 0; i < n; ++i)
			if (ok[i] && a[i].second == t) {
				if (a[i].first.first > h) break;
				if (a[i].first.second > maxM) {
					maxM = a[i].first.second;
					id = i;
				}
			}
		if (id == -1) break;
		++res;
		ok[id] = false;
		h += maxM;
		t = 1-t;
	}
	return res;
}


int main() {
#ifdef DEBUG
	freopen("436A.in", "r", stdin);
	freopen("436A.out", "w", stdout);
#endif
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i) {
		int t, h, m;
		scanf("%d%d%d", &t, &h, &m);
		a.push_back(make_pair(make_pair(h, m), t));
	}
	sort(a.begin(), a.end());

	int res = max(solve(0), solve(1));
	printf("%d\n", res);
	return 0;
}