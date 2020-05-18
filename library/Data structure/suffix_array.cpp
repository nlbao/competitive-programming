const int MAX_N = 2*(25*int(1e4)+5);
const int MAX_LOG = 20;

int n, logN;
char s[MAX_N];
int key[MAX_N], cnt[MAX_N], sa[MAX_N], sb[MAX_N];
int lcp[MAX_N], rank[MAX_N];
bool mark[MAX_N];
int level[MAX_LOG][MAX_N];


void build_sa() {
	s[n++] = 1;
	fill(cnt, 0);
	for (int i = 0; i < n; ++i) ++cnt[key[i] = s[i]];
	for (int i = 1; i < MAX_N; ++i) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; --i) sa[--cnt[key[i]]] = i;
	mark[0] = true;
	for (int i = 1; i < n; ++i) mark[i] = (key[sa[i-1]] != key[sa[i]]);

	// logN = 0;
	// for (int i = 0; i < n; ++i) level[logN][i] = key[i];

	for (int k = 1; k <= n; k <<= 1) {
		int nKey = 0;
		for (int i = 0; i < n; ++i) {
			if (mark[i]) ++nKey;
			key[sa[i]] = nKey;
			sb[i] = (sa[i] - k + n)%n;
		}
		fill(cnt, 0);
		for (int i = 0; i < n; ++i) ++cnt[key[i]];
		for (int i = 1; i <= nKey; ++i) cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; --i) sa[--cnt[key[sb[i]]]] = sb[i];
		for (int i = 1; i < n; ++i)
			mark[i] = mark[i] || (key[(sa[i-1]+k)%n] != key[(sa[i]+k)%n]);

		// for (int i = 0; i < n; ++i) level[logN][i] = key[i];
		// ++logN;
	}
	// while ((1<<logN) > n) --logN;
}


void build_lcp() {
	for (int i = 0; i < n; ++i)
		rank[sa[i]] = i;
	lcp[0] = 1;
	for (int i = 0, q = 0; i < n-1; ++i) {
		int j = sa[rank[i]-1];
		while (s[j+q] == s[i+q]) ++q;
		lcp[rank[i]] = q;
		q = max(q-1, 0);
	}
}


int get_lcp(int i, int j) {
	int ans = 0;
	for (int k = logN; k >= 0; --k)
		if (level[k][i] == level[k][j]) {
			ans += 1<<k;
			i += 1<<k;
			j += 1<<k;
		}
	return ans;
}