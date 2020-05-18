// find x: a^x = b (mod m), (a, m) = 1, O(sqrt(m)*log(m))
int solve (int a, int b, int m) {
	int n = (int)sqrt(1.0*m) + 1, an = 1;
	for (int i = 0; i < n; ++i)
		an = (an * a) % m;
		map<int, int> vals;
		for (int i = 1, cur = an; i <= n; ++i) {
			if (!vals.count(cur))
				vals[cur] = i;
			cur = (cur * an) % m;
		}
	for (int i = 0, cur = b; i <= n; ++i) {
		if (vals.count(cur)) {
			int ans = vals[cur] * n - i;
			if (ans < m) return ans;
		}
		cur = (cur * a) % m;
	}
	return -1;
}