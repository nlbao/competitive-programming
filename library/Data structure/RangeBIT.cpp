struct RangeBIT {
	static const int MAX_N = 2e5+5;
	int n;
	ll t1[MAX_N], t2[MAX_N];

	void init(int nn) {
		n = nn;
		filla(t1, 0);
		filla(t2, 0);
	}

	void update(ll f[], int i, ll val) {
		for (; i <= n; i += lowbit(i)) f[i] += val;
	}

	ll get(ll f[], int i) {
		ll ans = 0;
		for (; i > 0; i -= lowbit(i)) ans += f[i];
		return ans;
	}

	void update(int l, int r, ll val) {  // f[i] += val for l <= i <= r
		update(t1, l, val);
		update(t2, l, val*(l-1));
		update(t1, r+1, -val);
		update(t2, r+1, -val*r);
	}

	ll get(int k) {
		return get(t1, k)*k - get(t2, k);
	}

	ll get(int l, int r) {
		return get(r) - get(l-1);
	}
};