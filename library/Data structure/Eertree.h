struct Errtree {
	#define check(i, x) (i > 0 && a[i] == x)
	#define getLink(p, i) while (!check(i-1-len[p], a[i])) p = link[p]

	static const int MAX_N = 3e5 + 5;
	static const int MAX_X = 28;
	static const int oo = 1e9;

	char a[MAX_N];
	int nNode, last;
	int nexts[MAX_N][MAX_X];
	int len[MAX_N], link[MAX_N], diff[MAX_N], sLink[MAX_N];
	int f[MAX_N][2], sF[MAX_N][2];
	int num[MAX_N];	// count number of palindromes (no need distinct)
	ll cnt[MAX_N];	// count number of occurents of each palindrome

	inline bool hasNext(int i, int x) {
		return nexts[i][x] >= 0;
	}

	inline void newNode(int l, int k) {
		last = nNode++;
		len[last] = l;
		link[last] = k;
		filla(nexts[last], -1);
		num[last] = 0;
		cnt[last] = 0;
	}

	void init() {
		nNode = last = 0;
		newNode(-1, 0);
		newNode(0, 0);
		diff[0] = diff[1] = 0;
		for (int i = 0; i < MAX_N; ++i)
			for (int j = 0; j < 2; ++j)
				f[i][j] = sF[i][j] = oo;
		f[0][0] = sF[0][1] = sF[1][0] = 0;
	}

	int add(int i, int x) {	// i = 1..n. Return number of palindromes added when insert i-th character.
		a[i] = x;
		int p = last;
		getLink(p, i);
		if (hasNext(p, x)) {
			last = nexts[p][x];
			++cnt[last];
			return num[last];
		}
		newNode(len[p]+2, 1);
		nexts[p][x] = last;
		++cnt[last];
		if (p) {
			p = link[p];
			getLink(p, i);
			link[last] = nexts[p][x];
		}
		// build diff, sLink
		int k = link[last];
		diff[last] = len[last] - len[k];
		sLink[last] = (diff[last] == diff[k]) ? sLink[k] : k;
		tree[last].num = tree[tree[last].link].num + 1;
		return num[last] = num[link[last]] + 1;
	}

	void buildCnt() {
		for (int i = nNode-1; i > 0; --i)
			cnt[link[i]] += cnt[i];
	}

	// find minimal odd k (f[i][1]) and minimal even k (f[i][0])
	// such that we can split string s[1..i] into k palindromes
	void calF(int i) {
		for (int t = 0; t < 2; ++t)
			for (int u = last; len[u] > 0; u = sLink[u]) {
				sF[u][t] = f[i - (len[sLink[u]] + diff[u])][t];
				int k = link[u];
				if (diff[u] == diff[k])
					sF[u][t] = min(sF[u][t], sF[k][t]);
			}
		for (int t = 0; t < 2; ++t) {
			for (int u = last; len[u] > 0; u = sLink[u]) {
				f[i][t] = min(f[i][t], sF[u][t^1] + 1);
				if (t == 1 && len[u] == i)
					f[i][t] = 1;
			}
			if (f[i][t] > MAX_N) f[i][t] = oo;
		}
	}
};