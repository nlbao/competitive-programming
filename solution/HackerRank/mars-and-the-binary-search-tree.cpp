#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MOD = 1e9+7;


map<int, int> q, id;


int main() {
#ifdef DEBUG
	freopen("mars-and-the-binary-search-tree.in", "r", stdin);
	freopen("mars-and-the-binary-search-tree.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int val, ans = 1, h = 0;
		cin >> val;
		map<int, int>::iterator p = q.upper_bound(val);
		if (p != q.end()) {
			ans = (id[p->first]*2) % MOD;
			h = p->second;
		}
		if (p != q.begin()) {
			--p;
			if (p->second > h) {
				ans = (id[p->first]*2 + 1) % MOD;
				h = p->second;
			}
		}
		q[val] = h + 1;
		id[val] = ans;
		cout << ans << " ";
	}

	return 0;
}