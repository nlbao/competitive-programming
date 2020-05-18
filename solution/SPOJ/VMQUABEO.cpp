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


deque<int> q;



int main() {
#ifdef DEBUG
	freopen("VMQUABEO.in", "r", stdin);
	freopen("VMQUABEO.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &len, &d);
	for (int i = 0; i < n; ++i) scanf("%d", &h[i]);

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		while (!q.empty() && q.front() <= i-len) q.pop_front();
		if (!q.empty()) l[i] = find_1();
		else l[i] = i;
		while (!q.empty() && h[q.back()] <= h[i]) q.pop_back();
		q.push_back(i);
	}
	q.clear();
	for (int i = 0; i < n; ++i) {
		while (!q.empty() && q.front() <= i-len) q.pop_front();
		if (!q.empty()) l[i] = max(l[i], find_2());
		else l[i] = i;
		while (!q.empty() && h[q.back()] <= h[i]) q.pop_back();
		q.push_back(i);
	}


	cout << ans << endl;
	return 0;
}