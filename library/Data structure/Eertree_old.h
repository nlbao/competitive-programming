// find minimal odd k and minimal even k such that we can split string s[1..i] into k palindromes
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

	inline bool hasNext(int i, int x) {
		return nexts[i][x] >= 0;
	}

	inline void newNode(int l, int k) {
		last = nNode++;
		len[last] = l;
		link[last] = k;
		filla(nexts[last], -1);
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

	void add(int i, int x) {	// i: 1..n
		a[i] = x;
		int p = last;
		getLink(p, i);
		if (hasNext(p, x)) {
			last = nexts[p][x];
			return;
		}
		newNode(len[p]+2, 1);
		nexts[p][x] = last;
		if (p) {
			p = link[p];
			getLink(p, i);
			link[last] = nexts[p][x];
		}
		// build diff, sLink
		int k = link[last];
		diff[last] = len[last] - len[k];
		if (diff[last] == diff[k])
			sLink[last] = sLink[k];
		else
			sLink[last] = k;
	}

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



// no struct with count number of occurent of each palindrome (distinct)
struct Errtree {
	#define check(i, x) (i >= 0 && a[i] == x)

	static const int MAX_N = 2e5 + 5;
	static const int MAX_C = 28;

	int nNode, last;
	char a[MAX_N];
	int len[MAX_N], link[MAX_N];
	ll cnt[MAX_N];
	int nexts[MAX_N][MAX_C];

	inline bool hasNext(int i, int x) {
		return nexts[i][x] > -1;
	}

	inline void newNode(int i, int l, int k) {
		len[i] = l;
		link[i] = k;
		for (int x = 0; x < MAX_C; ++x)
			nexts[i][x] = -1;
		cnt[i] = 0;
	}

	void init() {
		nNode = 2;
		last = 1;
		newNode(0, -1, 0);
		newNode(1, 0, 0);
	}

	void add(int i, int x) {
		a[i] = x;
		int p = last;
		while (!check(i-1-len[p], x))
			p = link[p];
		if (hasNext(p, x)) {
			last = nexts[p][x];
			++cnt[last];
			return;
		}
		last = nNode++;
		newNode(last, len[p]+2, 1);
		++cnt[last];
		nexts[p][x] = last;
		if (p) {
			do {
				p = link[p];
			} while (!check(i-1-len[p], x));
			link[last] = nexts[p][x];
		}
	}

	void buildCnt() {
		for (int i = nNode-1; i > 0; --i)
			cnt[link[i]] += cnt[i];
	}
};


// no struct
struct Errtree {
	#define check(i, x) (i >= 0 && a[i] == x)
	#define hasNext(i, x) (nexts[i].find(x) != nexts[i].end())

	static const int MAX_N = 2e5 + 5;

	int nNode, last;
	char a[MAX_N];
	int len[MAX_N], link[MAX_N];
	map<int, int> nexts[MAX_N];

	inline void newNode(int i, int l, int k) {
		len[i] = l;
		link[i] = k;
		nexts[i].clear();
	}

	void init() {
		nNode = 2;
		last = 1;
		newNode(0, -1, 0);
		newNode(1, 0, 0);
	}

	void add(int i, int x) {
		a[i] = x;
		int p = last;
		while (!check(i-1-len[p], x))
			p = link[p];
		if (hasNext(p, x)) {
			last = nexts[p][x];
			return;
		}
		last = nNode++;
		newNode(last, len[p]+2, 1);
		nexts[p][x] = last;
		if (p) {
			do {
				p = link[p];
			} while (!check(i-1-len[p], x));
			link[last] = nexts[p][x];
		}
	}
};



// with struct
namespace Eertree {
#define check(i, x) (i >= 0 && a[i] == x)

const int MAX_N = 1e5 + 5;

struct Node {
	int len, link;
	map<int, int> nexts;

	Node(int l = 0, int pre = 0) {
		len = l;
		link = pre;
		nexts.clear();
	}

	void operator = (const Node &other) {
		len = other.len;
		link = other.link;
		nexts = other.nexts;
	}

	bool hasNext(int x) {
		return nexts.find(x) != nexts.end();
	}
};

int nNode, last;
int a[MAX_N];
Node tree[MAX_N];

void init() {
	nNode = 2;
	last = 1;
	tree[0] = Node(-1, 0);
	tree[1] = Node(0, 0);
}

void add(int x, int i) {
	a[i] = x;
	int p = last, k;
	while (!check(i-1-tree[p].len, x))
		p = tree[p].link;
	if (tree[p].hasNext(x)) {
		last = tree[p].nexts[x];
		return;
	}
	last = nNode++;
	tree[last] = Node(tree[p].len+2, 1);
	tree[p].nexts[x] = last;
	if (p) {
		do {
			p = tree[p].link;
		} while (!check(i-1-tree[p].len, x));
		tree[last].link = tree[p].nexts[x];
	}
}
};



////////////////////////////////////////

// Count number of palindrome (no need distinct)
namespace Errtree {
#define check(i, x) (i >= 0 && a[i] == x)

const int MAX_N = 1e5 +5;

struct Node {
	int len, link;
	int num;
	map<int, int> nexts;

	Node(int l = 0, int k = 0) {
		len = l;
		link = k;
		num = 0;
		nexts.clear();
	}

	void operator = (const Node &o) {
		len = o.len;
		link = o.link;
		num = o.num;
		nexts = o.nexts;
	}

	inline bool hasNext(int x) {
		return nexts.find(x) != nexts.end();
	}
};

int nNode, last;
char a[MAX_N];
Node tree[MAX_N];

void init() {
	nNode = 2;
	last = 1;
	tree[0] = Node(-1, 0);
	tree[1] = Node(0, 0);
}

int add(int i, int x) {
	a[i] = x;
	int p = last;
	while (!check(i-1-tree[p].len, x))
		p = tree[p].link;
	if (tree[p].hasNext(x)) {
		last = tree[p].nexts[x];
		return tree[last].num;
	}
	last = nNode++;
	tree[last] = Node(tree[p].len+2, 1);
	tree[p].nexts[x] = last;
	if (p) {
		do {
			p = tree[p].link;
		} while (!check(i-1-tree[p].len, x));
		tree[last].link = tree[p].nexts[x];
	}
	tree[last].num = tree[tree[last].link].num + 1;
	return tree[last].num;
}
}
