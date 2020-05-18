ll getC(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	if (k == 0 || k == n) return 1;
	if (n < MODULE) return c[n][k];
	ll ans = 1;
	while (n) {
		ll t = getC(n % MODULE, k % MODULE);
		if (t == 0) return 0;
		ans = (ans*t) % MODULE;
		n /= MODULE, k /= MODULE;
	}
	return ans;
}