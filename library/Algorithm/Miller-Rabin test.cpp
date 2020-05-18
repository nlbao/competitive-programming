ll mMul(ll a, ll b, ll mod) {
	if (!a || !b) return 0;
	if (b==1) return a % mod;
	ll t=mMul(a,b>>1,mod);
	t = (t+t)%mod;
	if (b&1) return (t+a)%mod;
	return t;
}

ll mPow(ll a, ll n, ll mod) {
	if (n < 1) return 1;
	if (n == 1) return a%mod;
	ll result = mPow(a, n>>1, mod);
	result = mMul(result, result, mod);
	if (n&1) result = mMul(result, a, mod);
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////

const ll nWitness = 4;
const ll witness[nWitness] = {2, 13, 23, 1662803};

bool primalityMillerRabinTest(ll n) {
	ll d = n-1, s = 0;
	while ((d&1) == 0) {
		++s;
		d >>= 1;
	}
	for (int k = 0; k < nWitness; ++k) {
		ll a = witness[k];
		ll b = mPow(a, d, n);
		if (b == 1 || b == n-1) continue;
		bool isPrime = false;
		for (int i = 0; i < s-1; ++i) {
			b = mMul(b, b, n);
			if (b == n-1) {
				isPrime = true;
				break;
			}
		}
		if (!isPrime) return false;
	}
	return true;
}

bool isPrime(ll n) {
	if (n == 2) return true;
	if (n < 2 || (n&1) == 0) return false;
	for (int i = 0; i < nWitness; ++i)
		if (n == witness[i]) return true;
		else if (n%witness[i] == 0) return false;
	return primalityMillerRabinTest(n);
}


///////////////////////////////////////////////////////////////////////////////////////////

bool suspect(ll a, ll s, ll d, ll n) {
	ll x = mPow(a, d, n);
	if (x == 1) return true;
	for (int r = 0; r < s; ++r) {
		if (x == n - 1) return true;
		x = mMul(x, x, n);
	}
	return false;
}

// {2,7,61,-1} is for n < 4759123 141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(ll n) {
	if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
	ll test[] = {2,3,5,7,11,13,17,19,23,-1};
	ll d = n - 1, s = 0;
	while ((d%2)==0) ++s, d /= 2;
	for (int i = 0; test[i] < n && test[i] != -1; ++i)
		if (!suspect(test[i], s, d, n)) return false;
	return true;
}